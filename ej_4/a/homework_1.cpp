#include <iostream>
#include "homework_1.hpp"

using namespace std;

/*
Para este ej usé char* por la simplicidad de trabajar con un array de char que ya sé cómo funcionan.
El string de c++ no sé del todo cómo está implementado así que supuse que iba a ser más lento.
Además, en el punto c tenía que trabajar con constexpr así que no tenía sentido hacerlo con string
si después iba a tener que usar char* sí o sí.
*/

bool are_equal(const char* texto1, const char* texto2, int c);

int main(){

    const char* texto1 = "El Club Atlético Los Andes es un club del sur del Gran Buenos Aires. Fue fundado en Lomas de Zamora, Buenos Aires el 1 de enero de 1917.";
    const char* texto2 = "El Club Atlético Los Andes es un club del sur del Gran Buenos Aires. Fue fundado en Lomas de Zamora, Buenos Aires el 1 de enero de 1917.";
    const char* texto3 = " El Club Atlético Los Andes es un club del sur del Gran Buenos Aires. Fue fundado en Lomas de Zamora, Buenos Aires el 1 de enero de 1917.";
    //Comparamos los textos 1 y 2 que son iguales y luego 1 y 3 que no lo son
    //Usamos el operador ternario para mostrar un mensaje más claro.
    cout << (are_equal(texto1, texto2, 0) ? "Los textos son iguales\n" : "Los textos no son iguales\n");
    cout << (are_equal(texto1, texto3, 0) ? "Los textos son iguales\n" : "Los textos no son iguales\n");
    return 0;
}