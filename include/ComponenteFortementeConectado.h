
#ifndef CFC_H
#define CFC_H

#include <vector>
#include "Vertice.h"

class ComponenteFortementeConectado {
    public:
        ComponenteFortementeConectado(std::vector<Vertice*> componenteConectados);
        void imprime();
        std::vector<Vertice*> obtemSaidas();
        std::vector<Vertice*> obtemVertices();

    private:
        std::vector<Vertice*> vertices;
        std::vector<Vertice*> saidas;
};

#endif