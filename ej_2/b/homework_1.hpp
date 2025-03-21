#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Agregamos la etiqueta NOTA para mostrar un evento nuevo.
enum class Severity {DEBUG, INFO, WARNING, ERROR, CRITICAL, SECURITY, ELSE, NOTA};

void logMessage(string msj, Severity nivel_svr) {
    //Misma función que en el a pero con el agregado del evento NOTA
    string msj_final;

    switch (nivel_svr) {
        case Severity::DEBUG:
            msj_final = "[DEBUG] <" + msj + "> \n";
            break;
        case Severity::INFO:
            msj_final = "[INFO] <" + msj + "> \n";
            break;
        case Severity::WARNING:
            msj_final = "[WARNING] <" + msj + "> \n";
            break;
        case Severity::ERROR:
            msj_final = "[ERROR] <" + msj + "> \n";
            break;
        case Severity::CRITICAL:
            msj_final = "[CRITICAL] <" + msj + "> \n";
            break;
        case Severity::NOTA: 
            if (msj == "aprobado") msj_final = "[NOTA] <" + msj + ", felicitaciones!> \n";
            else msj_final = "[NOTA] <" + msj + ", mal ahí, la próxima será> \n";
            break;
        default:
            cout << "No debería entrar acá porque ya se hizo la verificación del input \n";
            return;
    }
    //Escribimos el mensaje final en el archivo "logs.txt. Usamos el modo ios::app para agregar al final del archivo".
    //Usamos el ejemplo para escribir en un archivo que vimos en la clase.
    ofstream outFile("logs.txt", ios::app);
    if(outFile.is_open()) {
        outFile << msj_final;
        outFile.close();
    } else
        cerr << "Error abriendo el archivo \n";

    return;
}

void logMessage(string msj_error, string archivo, int linea) {
    //Escribimos la estructura para logear errores.
    string msj_final = msj_error + " on " + archivo + " at line: " + to_string(linea) + "\n";
    //Escribimos el mensaje final en el archivo "logs.txt. Usamos el modo ios::app para agregar al final del archivo".
    //Usamos el ejemplo para escribir en un archivo que vimos en la clase.
    ofstream outFile("logs.txt", ios::app);
    if(outFile.is_open()) {
        outFile << msj_final;
        outFile.close();
    } else
        cerr << "Error abriendo el archivo \n";

    return;
}

void logMessage(string msj_acceso, string usuario) {
    //Escribimos la estructura para logear accesos.
    string msj_final = "[SECURITY] <" + msj_acceso + " to user: " + usuario + ">\n";
    //Escribimos el mensaje final en el archivo "logs.txt. Usamos el modo ios::app para agregar al final del archivo".
    //Usamos el ejemplo para escribir en un archivo que vimos en la clase.
    ofstream outFile("logs.txt", ios::app);
    if(outFile.is_open()) {
        outFile << msj_final;
        outFile.close();
    } else
        cerr << "Error abriendo el archivo \n";

    return;
}

Severity convert_str_to_svr(const string svr) {
    //Convertimos la etiqueta ingresada a tipo Severity si existe en la clase.
    if (svr == "DEBUG") return Severity::DEBUG;
    else if (svr == "INFO") return Severity::INFO;
    else if (svr == "WARNING") return Severity::WARNING;
    else if (svr == "ERROR") return Severity::ERROR;
    else if (svr == "CRITICAL") return Severity::CRITICAL;
    else if (svr == "SECURITY") return Severity::SECURITY;
    else if (svr == "NOTA") return Severity::NOTA;
    else return Severity::ELSE;

}