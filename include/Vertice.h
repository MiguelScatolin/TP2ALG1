
#ifndef VERTICE_H
#define VERTICE_H

#include <vector>

class Vertice {
    public:
        Vertice();
        void adicionaSaida(Vertice& vertice);
    private:
        std::vector<Vertice&> saidas;
        int tempoDescobrimento;
        int tempoFinalizacao;
};

#endif