#include <iostream>

using namespace std;


bool are_equal(const char* texto1, const char* texto2, int c) {

    if (texto1[c] == '\0' && texto2[c] == '\0') return true;

    if (texto1[c] != texto2[c]) return false;

    return are_equal(texto1, texto2, c+1);

    return true;
}