
#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "Vertice.h"

class Grafo {
    public:
        Grafo(int numeroDeVertices);
        int contaComponentesFortementeConectados();

    private:
        std::vector<Vertice> vertices;
        int tempo;
};

#endif