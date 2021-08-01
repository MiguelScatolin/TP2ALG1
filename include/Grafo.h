
#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "Vertice.h"

class Grafo {
    public:
        Grafo(int numeroDeVertices);
        int contaComponentesFortementeConectados();
        void adicionaAresta(int origem, int destino);
        void imprimeVerticesEArestas();

    private:
        std::vector<Vertice> vertices;
        int tempo;
};

#endif