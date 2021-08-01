#include <iostream>
#include "IO.h"

Grafo montarGrafoRotasEntreAeroportos() {
    int numeroDeVertices, numeroDeArestas;
    std::cin >> numeroDeVertices >> numeroDeArestas;
    Grafo rotasEntreAeroportos = Grafo(numeroDeVertices);

    int verticeOrigem, verticeDestino;
    for(int i = 0; i < numeroDeArestas; i++) {
        std::cin >> verticeOrigem >> verticeDestino;
        rotasEntreAeroportos.adicionaAresta(verticeOrigem, verticeDestino);
    }

    return rotasEntreAeroportos;
};