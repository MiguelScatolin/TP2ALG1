#ifndef VERTICE_H
#define VERTICE_H

#include <vector>

class Vertice {
    public:
        Vertice(int id) : id(id) {}
        Vertice(Vertice* vertice);
        void adicionaSaida(Vertice* vertice);
        std::vector<Vertice*> descobre(int tempoDescobrimento);
        void finaliza(int tempoFinalizacao);
        void imprime();
        bool jaFoiDescoberto();
        int obtemId();
        std::vector<Vertice*> obtemSaidas();

    private:
        std::vector<Vertice*> saidas;
        int id;
        int tempoDescobrimento;
        int tempoFinalizacao;
};

#endif