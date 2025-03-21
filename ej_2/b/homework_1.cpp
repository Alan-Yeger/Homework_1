#include <iostream>
#include <sstream>
#include "homework_1.hpp"

using namespace std;

void logMessage(const string msj, Severity nivel_svr);
void logMessage(string msj_error, string archivo, int linea);
void logMessage(string msj_acceso, string usuario);
Severity convert_str_to_svr(const string svr);

int main(){

    cout << "Ingrese distintos eventos. Si desea salir ingrese la línea: exit \n";

    while (true) {
        string input, svr, msj;
        int line = 0;
    
        getline(cin, input);  // Leer toda la línea completa
        stringstream ss(input);  // Convertir la línea en un stream para extraer valores
    
        ss >> svr;
        if (svr == "exit") break;
        
        ss >> msj;
        ss >> line;  // Si no hay número, `line` se queda en 0
    
        if (line) {
            logMessage(svr, msj, line);
            continue;
        }
    
        Severity svr_class = convert_str_to_svr(svr);
    
        if (svr_class != Severity::ELSE) {
            logMessage(msj, svr_class);
        } else {
            logMessage(svr, msj);
        }
    }
    
}