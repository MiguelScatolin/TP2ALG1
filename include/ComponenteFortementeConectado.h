
#ifndef CFC_H
#define CFC_H

#include <vector>
#include "Vertice.h"

class ComponenteFortementeConectado {
    public:
        ComponenteFortementeConectado(std::vector<Vertice*> componenteConectados);
        void imprime();
        int obtemNumeroDeEntradasESaidas();

    private:
        int numeroDeEntradasESaidas;
        std::vector<Vertice*> vertices;
};

#endif