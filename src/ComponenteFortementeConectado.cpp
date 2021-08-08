#include <iostream>
#include "ComponenteFortementeConectado.h"

bool verticeEstaNaLista(Vertice* vertice, std::vector<Vertice*> lista) {
    for(int i = 0; i < lista.size(); i++) {
        if(lista[i] == vertice)
            return true;
    }
    return false;
}

ComponenteFortementeConectado::ComponenteFortementeConectado(std::vector<Vertice*> componenteConectados) {
    this->numeroDeEntradasESaidas = 0;
    this->vertices = componenteConectados;
    for(int i = 0; i < this->vertices.size(); i++) {
        std::vector<Vertice*> saidasVertice = this->vertices[i]->obtemSaidas();
        for(int j = 0; j < saidasVertice.size(); j++) {
            if(!verticeEstaNaLista(saidasVertice[j], this->vertices)) {
                numeroDeEntradasESaidas++;
            }
        }
    }
};