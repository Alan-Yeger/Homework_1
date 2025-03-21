#include <iostream>
#include <vector>

using namespace std;

void mtx_nxn(vector<vector<int>>& mtx, int n) {
    int v = 1;
    //Recorremos para cada fila las n columnas y vamos asignando los valores de cada casilla en orden creciente.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mtx[i][j] = v;
            v++;
        }
    }
    //Imprimimos el resultado de la matriz ordenada
    for (int i = 0; i < n; ++i) {
        for (const int v: mtx[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return;
}



void mayor_menor(vector<vector<int>>& mtx, int n) {
    int f, c;
    //Usamos el típico truquito para recorrer una matriz con un solo for (aunque el orden sigue siendo O(n^2)) dividiendo
    //la coordenada en en su fila y su columna. Notemos que si numeramos las casillas en orden creciente desde 0 hasta n*n-1
    //el número de fila es nro_casilla/n y el número de columna es nro_casilla%n. Para recorrerla en orden decreciente empezamos
    //en la casilla n*n-1 y terminamos en la 0.
    for (int i = n * n - 1; i >= 0; --i) {
        f = i / n;
        c = i % n;

        cout << "M" << n << "[" << f << "][" << c << "] = " << mtx[f][c] << "\n";
    }

    return;
}