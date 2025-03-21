#include <iostream>

using namespace std;


bool are_equal(const char* texto1, const char* texto2, int c) {
    //El caso base es si ambos caracteres comparados son \0 ya que este caracter es el que indica que finaliza un char*
    if (texto1[c] == '\0' && texto2[c] == '\0') return true;
    //Si los caracteres comparados son distintos ya sabemos que los char* no son iguales.
    if (texto1[c] != texto2[c]) return false;
    //Pasamos a comparar el caracter siguiente de cada char*
    return are_equal(texto1, texto2, c+1);
}