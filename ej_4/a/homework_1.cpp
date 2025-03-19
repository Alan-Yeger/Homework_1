#include <iostream>
#include "homework_1.hpp"

using namespace std;

bool are_equal(const char* texto1, const char* texto2, int c);

int main(){

    const char* texto1 = "El Club Atlético Los Andes es un club del sur del Gran Buenos Aires. Fue fundado en Lomas de Zamora, Buenos Aires el 1 de enero de 1917.";
    const char* texto2 = "El Club Atlético Los Andes es un club del sur del Gran Buenos Aires. Fue fundado en Lomas de Zamora, Buenos Aires el 1 de enero de 1917. ";

    cout << (are_equal(texto1, texto2, 0) ? "Los textos son iguales\n" : "Los textos no son iguales\n");
    return 0;
}