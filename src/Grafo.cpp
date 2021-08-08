#include <iostream>
#include "Grafo.h"
#include <numeric>

Grafo::Grafo(int numeroDeVertices) {
    for(int i = 0; i < numeroDeVertices; i++)
        vertices.push_back(new Vertice(i + 1));
    tempo = 0;
};

void Grafo::adicionaAresta(int origem, int destino) {
    int indexOrigem = origem - 1;
    int indexDestino = destino - 1;
    vertices[indexOrigem]->adicionaSaida(vertices[indexDestino]);
};

int Grafo::calculaNumeroDeRotasFaltantes() {
    std::vector<ComponenteFortementeConectado> componentesFortes = this->encontraComponentesFortementeConectados();
    int numeroDeComponentes = componentesFortes.size();
    int numeroDeArestasConectandoComponentes = 0;
    for(int i = 0; i < numeroDeComponentes; i++) 
        numeroDeArestasConectandoComponentes += componentesFortes[i].obtemNumeroDeEntradasESaidas();
    return numeroDeComponentes - numeroDeArestasConectandoComponentes;
};

std::vector<ComponenteFortementeConectado> Grafo::encontraComponentesFortementeConectados() {
    std::vector<int> indices(this->vertices.size());
    std::iota (std::begin(indices), std::end(indices), 0);
    this->realizaBuscaEmProfundidade(indices);
    std::vector<std::vector<Vertice*> > componentesConectados = this->transposto->realizaBuscaEmProfundidade(this->indicesPorOrdemDeFinalizacao);
    std::vector<ComponenteFortementeConectado> componentesFortementeConectados = std::vector<ComponenteFortementeConectado>();
    for(int i = 0; i < componentesConectados.size(); i++)
        componentesFortementeConectados.push_back(ComponenteFortementeConectado(componentesConectados[i]));
    return componentesFortementeConectados;
};

void Grafo::exploraVertice(Vertice* vertice, std::vector<Vertice*>& componenteConectado) {
    if(!vertice->jaFoiDescoberto()){
        this->tempo++;
        std::vector<Vertice*> saidasVertice = vertice->descobre(tempo);
        componenteConectado.push_back(vertice);
        for(int i = 0; i < saidasVertice.size(); i++)
            this->exploraVertice(saidasVertice[i], componenteConectado);
        vertice->finaliza(tempo);
        indicesPorOrdemDeFinalizacao.insert(indicesPorOrdemDeFinalizacao.begin(), vertice->obtemId() - 1);
    }
};

void Grafo::imprimeVerticesEArestas() {
    for(int i = 0; i < vertices.size(); i++)
        vertices[i]->imprime();
};

std::vector<std::vector<Vertice*> > Grafo::realizaBuscaEmProfundidade(std::vector<int> indices) {
    std::vector<std::vector<Vertice*> > componentesConectados = std::vector<std::vector<Vertice*> >();
    for(int i = 0; i < vertices.size(); i ++) {
        int indice = indices[i];
        if(!vertices[indice]->jaFoiDescoberto()) {
            std::vector<Vertice*> componenteConectado = std::vector<Vertice*>();
            exploraVertice(vertices[i], componenteConectado);
            componentesConectados.push_back(componenteConectado);
        }
    }
    return componentesConectados;
};

void Grafo::salvaGrafoTransposto(Grafo* grafoTransposto) {
    this->transposto = grafoTransposto;
};