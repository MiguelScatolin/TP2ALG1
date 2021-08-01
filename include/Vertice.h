
#ifndef VERTICE_H
#define VERTICE_H

#include <vector>

class Vertice {
    public:
        Vertice(int id) : id(id) {}
        void adicionaSaida(Vertice* vertice);
        void imprimeSaidas();

    private:
        std::vector<Vertice*> saidas;
        int id;
        int tempoDescobrimento;
        int tempoFinalizacao;
};

#endif