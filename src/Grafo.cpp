#include <iostream>
#include "Grafo.h"
#include <numeric>
#include<algorithm>

Grafo::Grafo(int numeroDeVertices) {
    for(int i = 0; i < numeroDeVertices; i++)
        vertices.push_back(new Vertice(i + 1));
    tempo = 0;
};

Grafo::Grafo(std::vector<ComponenteFortementeConectado> componentesFortementeConectados) {
    for(int i = 0; i < componentesFortementeConectados.size(); i++)
        vertices.push_back(new Vertice(i));
    
    for(int i = 0; i < componentesFortementeConectados.size(); i++) {
        std::vector<Vertice*> saidas = componentesFortementeConectados[i].obtemSaidas();
        for(int j = 0; j < saidas.size(); j++) {
            for(int k = 0; k < componentesFortementeConectados.size(); k++) {
                std::vector<Vertice*> vertices = componentesFortementeConectados[k].obtemVertices();
                for(int l = 0; l < vertices.size(); l++) {
                    if(saidas[j] == vertices[l])
                        this->adicionaAresta(i, k);
                }
            }
        }
    }
};

void Grafo::adicionaAresta(int indexOrigem, int indexDestino) {
    vertices[indexOrigem]->adicionaSaida(vertices[indexDestino]);
    vertices[indexDestino]->adicionaEntrada(vertices[indexOrigem]);
};

int Grafo::calculaArestasParaConectarFortemente() {
    std::vector<ComponenteFortementeConectado> componentesFortes = this->encontraComponentesFortementeConectados();
    Grafo grafoCondensado = Grafo(componentesFortes);
    
    return grafoCondensado.calculaArestasFaltantesParaGrafoCondensado();
};

int Grafo::calculaArestasFaltantesParaGrafoCondensado() {
    int numeroDeFontes = 0,
        numeroDeDrenos = 0,
        numeroDeIsolados = 0; 
    for(int i = 0; i < this->vertices.size(); i++) {
        Vertice* vertice = vertices[i];
        int numeroDeEntradas = vertice->obtemEntradas().size();
        int numeroDeSaidas = vertice->obtemEntradas().size();

        if(numeroDeEntradas > 0 && numeroDeSaidas == 0)
            numeroDeDrenos++;
        else if(numeroDeEntradas == 0 && numeroDeSaidas > 0)
            numeroDeFontes++;
        else if(numeroDeEntradas == 0 && numeroDeSaidas == 0)
            numeroDeIsolados++;
    }
    return std::max(numeroDeFontes + numeroDeIsolados, numeroDeDrenos + numeroDeIsolados);
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
        std::vector<Vertice*> saidasVertice = vertice->descobre(this->tempo);
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
    for(int i = 0; i < indices.size(); i ++) {
        int indice = indices[i];
        if(!vertices[indice]->jaFoiDescoberto()) {
            std::vector<Vertice*> componenteConectado = std::vector<Vertice*>();
            exploraVertice(vertices[indice], componenteConectado);
            componentesConectados.push_back(componenteConectado);
        }
    }
    return componentesConectados;
};

void Grafo::salvaGrafoTransposto(Grafo* grafoTransposto) {
    this->transposto = grafoTransposto;
};