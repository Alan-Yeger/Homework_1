#include <iostream>
#include "homework_1.hpp"

using namespace std;

/*
Para este problema uso enum class severity para distinguir los distintos tipos de mensaje. En este caso resulta medio ineficiente
porque tengo que convertir el string ingresado por consola a tipo Severity para luego escribirlo en el .txt pero a efectos prácticos 
muetra el manejo del enum class y del switch.
*/

//Prototipos de funciones
void logMessage(const string msj, Severity nivel_svr);
Severity convert_str_to_svr(const string svr);

int main(){
    
    cout << "Ingrese distintos eventos. Si desea salir ingrese la línea: exit \n";
    //Ingresamos los distintos eventos por consola.
    while(true) {
        string svr, msj;
        cin >> svr;
        if (svr == "exit") break;
        cin >> msj;

        Severity svr_class = convert_str_to_svr(svr);

        logMessage(msj, svr_class);
    }
}