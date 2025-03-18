#include <iostream>
#include <vector>
#include "homework_1.hpp"

using namespace std;

void mtx_nxn(vector<vector<int>>& mtx, int n);
void mayor_menor(vector<vector<int>>& mtx, int n);

int main(){

    int n = 0;

    while(n <= 1) {
        cout << "Ingrese un entero positivo mayor que 1 \n";
        cin >> n;
    }
    vector<vector<int>> mtx(n, vector<int>(n));
    
    mtx_nxn(mtx, n);
    mayor_menor(mtx, n);
}