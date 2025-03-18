#include <iostream>
#include "homework_1.hpp"

using namespace std;

void logMessage(const string msj, Severity nivel_svr);
Severity convert_str_to_svr(const string svr);

int main(){

    cout << "Ingrese distintos eventos. Si desea salir ingrese la línea: exit \n";

    while(true) {
        string svr, msj;
        cin >> svr;
        if (svr == "exit") break;
        cin >> msj;

        Severity svr_class = convert_str_to_svr(svr);

        logMessage(msj, svr_class);
    }
}