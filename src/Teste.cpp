#include <fstream>
#include <iostream>
#include <string>
#include "Grafo.h"
#include "Teste.h"
#include "IO.h"

bool checkEqual(char string1[], char string2[]) {
    return strcmp(string1, string2) == 0;
}

void test() {
    try {
        for(int i = 0; i < 8; i++) {
            std::string nomeArquivoDeEntrada = "entradas/ct0" + std::to_string(i) + ".txt";
            std::ifstream entrada(nomeArquivoDeEntrada);
            std::cin.rdbuf(entrada.rdbuf());
            Grafo rotasEntreAeroportos = montarGrafoRotasEntreAeroportos();
            int resultadoCalculado = rotasEntreAeroportos.calculaArestasParaConectarFortemente();

            int resultadoEsperado;
            std::string nomeArquivoDeSaida = "saidas/ct0" + std::to_string(i) + "-output.txt";
            std::ifstream saida(nomeArquivoDeSaida);
            saida >> resultadoEsperado;

            if(resultadoCalculado != resultadoEsperado) {
                std::cout << "Caso: ct0" << i << std::endl;
                std::cout << "Esperado:" << resultadoEsperado << std::endl;
                std::cout << "Calculado:" << resultadoCalculado << std::endl;
                break;
            }
        }
    }
    catch (char exception[]) {
        std::cout << exception << std::endl;
    }
}