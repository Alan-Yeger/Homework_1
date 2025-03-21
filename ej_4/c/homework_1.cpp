#include <iostream>
#include <chrono>
#include "homework_1.hpp"

using namespace std;

/*
Finalmente cambiamos las variables por constexpr y vemos que ahora la ejecución del código toma ahora 200 nanosegundos (al menos en mi compu)

CONCLUSIÓN: Al utilizar constexpr precomputamos el resultado en tiempo de compilación y al ejecutar el código la función ya fue precomputada
Por este motivo la ejecución del código es considerablementa más rápida en este caso, ya que no hace falta calcular nuevamente el resultado
de la función are_equal.
*/

constexpr bool are_equal(const char* texto1, const char* texto2, int c);

int main(){

    constexpr const char* texto1 = "El Club Atlético Los Andes es un club del sur del Gran Buenos Aires. Fue fundado en Lomas de Zamora, Buenos Aires el 1 de enero de 1917.";
    constexpr const char* texto2 = "El Club Atlético Los Andes es un club del sur del Gran Buenos Aires. Fue fundado en Lomas de Zamora, Buenos Aires el 1 de enero de 1917. ";

    auto startTime = chrono::high_resolution_clock::now();
    constexpr bool resultado = are_equal(texto1, texto2, 0);
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(
    endTime - startTime);
    std::cout << "A la comparación de textos le tomó: " << elapsedTime.count() << " nanosegundos" << endl;

    return 0;
}

