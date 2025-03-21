#include <iostream>
#include <chrono>
#include "homework_1.hpp"

using namespace std;

/*
Usando la librería chrono vemos que el código tarda 4700 nanosegundos aprox 
*/

bool are_equal(const char* texto1, const char* texto2, int c);

int main(){

    const char* texto1 = "El Club Atlético Los Andes es un club del sur del Gran Buenos Aires. Fue fundado en Lomas de Zamora, Buenos Aires el 1 de enero de 1917.";
    const char* texto2 = "El Club Atlético Los Andes es un club del sur del Gran Buenos Aires. Fue fundado en Lomas de Zamora, Buenos Aires el 1 de enero de 1917. ";

    auto startTime = chrono::high_resolution_clock::now();
    bool resultado = are_equal(texto1, texto2, 0);
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(
    endTime - startTime);
    std::cout << "A la comparación de textos le tomó: " << elapsedTime.count() << " nanosegundos" << endl;

    return 0;
}

