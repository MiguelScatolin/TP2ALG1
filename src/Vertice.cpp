#include <iostream>
#include "Vertice.h"

Vertice::Vertice(int id) {
    this->id = id;
    this->saidas = std::vector<Vertice*>();
    this->entradas = std::vector<Vertice*>();
    this->tempoDescobrimento = 0;
    this->tempoFinalizacao = 0;
};

void Vertice::adicionaSaida(Vertice* vertice) {
    saidas.push_back(vertice);
};

void Vertice::adicionaEntrada(Vertice* vertice) {
    entradas.push_back(vertice);
};

std::vector<Vertice*> Vertice::descobre(int tempoDescobrimento) {
    this->tempoDescobrimento = tempoDescobrimento;
    return obtemSaidas();
};

void Vertice::finaliza(int tempoFinalizacao) {
    this->tempoFinalizacao = tempoFinalizacao;
};

void Vertice::imprime() {
    std::cout << "V" << this->obtemId() << std::endl;
    std::cout << "Tempo descoberta: " << this->tempoDescobrimento << std::endl;
    std::cout << "Saidas: ";
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

std::vector<Vertice*> Vertice::obtemEntradas() {
    return this->entradas;
};