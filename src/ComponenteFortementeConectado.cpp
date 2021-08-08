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
    this->vertices = componenteConectados;
    for(int i = 0; i < this->vertices.size(); i++) {
        std::vector<Vertice*> saidasVertice = this->vertices[i]->obtemSaidas();
        for(int j = 0; j < saidasVertice.size(); j++) {
            if(!verticeEstaNaLista(saidasVertice[j], this->vertices))
                this->saidas.push_back(saidasVertice[j]);
        }
    }
};

void ComponenteFortementeConectado::imprime() {
    std::cout << "{ ";
    for(int i = 0; i < this->vertices.size(); i++)
        std::cout << vertices[i]->obtemId() << " ";
    std::cout << "}" << std::endl;
};

std::vector<Vertice*> ComponenteFortementeConectado::obtemSaidas() {
    return this->saidas;
};
std::vector<Vertice*> ComponenteFortementeConectado::obtemVertices() {
    return this->vertices;
};