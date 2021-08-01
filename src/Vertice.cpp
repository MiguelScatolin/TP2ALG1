#include <iostream>
#include "Vertice.h"

void Vertice::adicionaSaida(Vertice* vertice) {
    saidas.push_back(vertice);
};

void Vertice::imprimeSaidas() {
    std::cout << "Saidas: ";
    for(int i = 0; i < saidas.size(); i++) 
        std::cout << "V" << saidas[i]->id << " ";
    std::cout << std::endl;
};