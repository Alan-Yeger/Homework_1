#include <iostream>
#include <sstream>
#include "homework_1.hpp"

/*
Para este problema hacemos uso de la sobrecarga de funciones para ingresar distintos tipos de mensajes.
En este caso se me dificultó que en la consigna el prototipo para cargar los tipo SECURITY solo reciben msj_acceso y usuario.
Para ello me creé el tipo ELSE y en este caso se usa para identificar los mensajes para security, pero se podría hacer directo con un tipo 
SECURITY como los demás. Aparte agregué el tipo NOTA para mostrar lo fácil que es agregar nuevos eventos.
*/


using namespace std;

//Usamos la sobrecarga de funciones por cantidad y tipo de argumento. 
void logMessage(const string msj, Severity nivel_svr);
void logMessage(string msj_error, string archivo, int linea);
void logMessage(string msj_acceso, string usuario);
Severity convert_str_to_svr(const string svr);

int main(){

    cout << "Ingrese distintos eventos. Si desea salir ingrese la línea: exit \n";

    while (true) {
        string input, svr, msj;
        int line = 0;
        //Acá tuve un problema ya que a veces el usuario ingresa 2 parámetros y a veces 3. La solución que encontré fue leer la línea completa
        //y usar un stringstream para dividir la línea en palabras.
        getline(cin, input);
        stringstream ss(input);
    
        ss >> svr;
        if (svr == "exit") break;
        
        ss >> msj;
        ss >> line;
        //Si se escribió una linea entonces es positiva y se llama a la función de error.
        if (line) {
            logMessage(svr, msj, line);
            continue;
        }
    
        Severity svr_class = convert_str_to_svr(svr);
        //Si la etiqueta Severity no es de las predeterminadas llamamos a la función para permitir/denegar acceso a un usuario.
        if (svr_class != Severity::ELSE) {
            logMessage(msj, svr_class);
        } else { //Sino llamamos a la misma función del a.
            logMessage(svr, msj);
        }
    }

    try {
        throw runtime_error("Error capturado en ejecución"); //Lanzamos un runtime_error y lo catcheamos para logear el error
    } catch (runtime_error e) {
        logMessage(e.what(), "homework_1.cpp", 53); //El archivo y la línea están hardcodeadas.
        return 1;
    }
    
    return 0;
}