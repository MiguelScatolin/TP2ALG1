#ifndef VERTICE_H
#define VERTICE_H

#include <vector>

class Vertice {
    public:
        Vertice(int id);
        void adicionaSaida(Vertice* vertice);
        void adicionaEntrada(Vertice* vertice);
        std::vector<Vertice*> descobre(int tempoDescobrimento);
        void finaliza(int tempoFinalizacao);
        void imprime();
        bool jaFoiDescoberto();
        int obtemId();
        std::vector<Vertice*> obtemSaidas();
        std::vector<Vertice*> obtemEntradas();

    private:
        std::vector<Vertice*> saidas;
        std::vector<Vertice*> entradas;
        int id;
        int tempoDescobrimento;
        int tempoFinalizacao;
};

#endif