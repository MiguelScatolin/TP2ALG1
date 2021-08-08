#include <iostream>
#include "Grafo.h"
#include "IO.h"
#include "Teste.h"

int main(int argc, char* argv[]) {
    try {
        if(argc > 1 && checkEqual(argv[1], STRING_TESTE)) {
            test();
            return 0;
        }

        Grafo rotasEntreAeroportos = montarGrafoRotasEntreAeroportos();

        int numeroDeRotasASeremCriadas = rotasEntreAeroportos.calculaArestasParaConectarFortemente();

        std::cout << numeroDeRotasASeremCriadas;

        return 0;
    }
    catch (char exception[]) {
        std::cout << exception << std::endl;
    }
}