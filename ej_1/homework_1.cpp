#include <iostream>
#include <vector>
#include "homework_1.hpp"

using namespace std;

/*
En este ejercicio hago uso del contenedor vector, ya que estoy acostumbrado a usarlo en los problemas de competitiva.
Lo único que se hace en este archivo es recibir un entero n por consola, armar un contenedor de nxn y llamar a las 
funciones para armar la matriz e imprimirla de mayor a menor.
*/

void mtx_nxn(vector<vector<int>>& mtx, int n); //Prototipos de funciones que reciben la referencia de la matriz y el entero n.
void mayor_menor(vector<vector<int>>& mtx, int n);

int main(){

    int n = 0;

    // Se recibe el número solo cuando sea mayor que 1.
    while(n <= 1) {
        cout << "Ingrese un entero positivo mayor que 1 \n";
        cin >> n;
    }
    //Defino un vector de vectores de nxn como mi contenedor para la matriz.
    vector<vector<int>> mtx(n, vector<int>(n));
    
    //Invocación de las funciones
    mtx_nxn(mtx, n);
    mayor_menor(mtx, n);
}