#include <iostream>
#include "Grafo.h"


Grafo::Grafo(int numeroDeVertices) {
    for(int i = 0; i < numeroDeVertices; i++)
        vertices.push_back(Vertice(i + 1));
    tempo = 0;
};

int Grafo::calculaNumeroDeRotasFaltantes() {
    return 1;
};

void Grafo::adicionaAresta(int origem, int destino) {
    int indexOrigem = origem - 1;
    int indexDestino = destino - 1;
    vertices[indexOrigem].adicionaSaida(&vertices[indexDestino]);
};

void Grafo::imprimeVerticesEArestas() {
    for(int i = 0; i < vertices.size(); i++) {
        std::cout << "V" << i + 1 << ": " << std::endl;
        vertices[i].imprimeSaidas();
    }
};