#include <iostream>
#include "IO.h"
#include "Grafo.h"


int main(int argc, char* argv[]) {
    try {
        Grafo rotasEntreAeroportos = montarGrafoRotasEntreAeroportos();

        return 0;
    }
    catch (char exception[]) {
    }
}
