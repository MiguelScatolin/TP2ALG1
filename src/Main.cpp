#include <iostream>
#include <fstream>
#include <string>
#include "IO.h"
#include "Grafo.h"

#define STRING_TESTE (char *)"teste"

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
            int resultadoCalculado = rotasEntreAeroportos.calculaNumeroDeRotasFaltantes();

            int resultadoEsperado;
            std::string nomeArquivoDeSaida = "saidas/ct0" + std::to_string(i) + "-output.txt";
            std::ifstream saida(nomeArquivoDeSaida);
            saida >> resultadoEsperado;

            if(resultadoCalculado != resultadoEsperado) {
                std::cout << "Caso:" << i << std::endl;
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

int main(int argc, char* argv[]) {
    try {
        if(argc > 1 && checkEqual(argv[1], STRING_TESTE)) {
            test();
            return 0;
        }

        Grafo rotasEntreAeroportos = montarGrafoRotasEntreAeroportos();

        int numeroDeRotasASeremCriadas = rotasEntreAeroportos.calculaNumeroDeRotasFaltantes();

        std::cout << numeroDeRotasASeremCriadas;

        return 0;
    }
    catch (char exception[]) {
        std::cout << exception << std::endl;
    }
}