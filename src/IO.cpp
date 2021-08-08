#include <iostream>
#include "IO.h"

Grafo montarGrafoRotasEntreAeroportos() {
    int numeroDeVertices, numeroDeArestas;
    std::cin >> numeroDeVertices >> numeroDeArestas;
    Grafo rotasEntreAeroportos = Grafo(numeroDeVertices);
    Grafo* rotasEntreAeroportosInvertidas = new Grafo(numeroDeVertices);

    int verticeOrigem, verticeDestino;
    for(int i = 0; i < numeroDeArestas; i++) {
        std::cin >> verticeOrigem >> verticeDestino;
        rotasEntreAeroportos.adicionaAresta(verticeOrigem - 1, verticeDestino - 1);
        rotasEntreAeroportosInvertidas->adicionaAresta(verticeDestino - 1, verticeOrigem - 1);
    }
    rotasEntreAeroportos.salvaGrafoTransposto(rotasEntreAeroportosInvertidas);

    return rotasEntreAeroportos;
};