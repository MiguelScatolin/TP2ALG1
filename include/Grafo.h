
#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "Vertice.h"
#include "ComponenteFortementeConectado.h"

class Grafo {
    public:
        Grafo(int numeroDeVertices);
        int calculaNumeroDeRotasFaltantes();
        void adicionaAresta(int origem, int destino);
        void imprimeVerticesEArestas();
        void salvaGrafoTransposto(Grafo* grafoTransposto);

    private:
        Grafo* transposto;
        int tempo;
        std::vector<int> indicesPorOrdemDeFinalizacao;
        std::vector<Vertice*> vertices;
        std::vector<ComponenteFortementeConectado> encontraComponentesFortementeConectados();
        void exploraVertice(Vertice* vertice, std::vector<Vertice*> componenteConectado);
        std::vector<std::vector<Vertice*> > realizaBuscaEmProfundidade(std::vector<int> indices);
};

#endif