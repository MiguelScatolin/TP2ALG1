#include <iostream>
#include "Vertice.h"

Vertice::Vertice(Vertice* vertice) {
    this->id = vertice->id;
    this->saidas = vertice->saidas;
};

void Vertice::adicionaSaida(Vertice* vertice) {
    saidas.push_back(vertice);
};

std::vector<Vertice*> Vertice::descobre(int tempoDescobrimento) {
    this->tempoDescobrimento = tempoDescobrimento;
    return obtemSaidas();
};

void Vertice::finaliza(int tempoFinalizacao) {
    this->tempoFinalizacao = tempoFinalizacao;
};

void Vertice::imprime() {
    std::cout << "Saidas V" << this->obtemId() << ": ";
    for(int i = 0; i < saidas.size(); i++) 
        std::cout << "V" << saidas[i]->id << " ";
    std::cout << std::endl;
};

bool Vertice::jaFoiDescoberto() {
    return this->tempoDescobrimento > 0;
};

int Vertice::obtemId() {
    return this->id;
};

std::vector<Vertice*> Vertice::obtemSaidas() {
    return this->saidas;
};