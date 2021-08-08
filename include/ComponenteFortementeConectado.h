
#ifndef CFC_H
#define CFC_H

#include <vector>
#include "Vertice.h"

class ComponenteFortementeConectado {
    public:
        ComponenteFortementeConectado(std::vector<Vertice*> componenteConectados);
        int numeroDeEntradasESaidas;

    private:
        std::vector<Vertice*> vertices;
};

#endif