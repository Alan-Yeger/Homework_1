#include <iostream>
#include <vector>

using namespace std;

void mtx_nxn(vector<vector<int>>& mtx, int n) {
    int v = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mtx[i][j] = v;
            v++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int v: mtx[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return;
}



void mayor_menor(vector<vector<int>>& mtx, int n) {
    int f, c;

    for (int i = n * n - 1; i >= 0; --i) {
        f = i / n;
        c = i % n;

        cout << "M" << n << "[" << f << "][" << c << "] = " << mtx[f][c] << "\n";
    }

    return;
}