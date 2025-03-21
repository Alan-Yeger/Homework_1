#include <iostream>
#include <fstream>

using namespace std;

//Definimos las distintas etiquetas para los tipos de mensaje.
enum class Severity {DEBUG, INFO, WARNING, ERROR, CRITICAL};

void logMessage(string msj, Severity nivel_svr) {

    string msj_final;
    //Usamos un switch para escribir los distintos tipos de mensaje.
    //En una situación real se podrían manejar las distintas etiquetas realizando distintas acciones
    //Por ejemplo se podrían lanzar alertas especiales para los casos ERROR y CRITICAL 
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

Severity convert_str_to_svr(const string svr) {
    //Convertimos la etiqueta ingresada a tipo Severity si existe en la clase.
    if (svr == "DEBUG") return Severity::DEBUG;
    else if (svr == "INFO") return Severity::INFO;
    else if (svr == "WARNING") return Severity::WARNING;
    else if (svr == "ERROR") return Severity::ERROR;
    else if (svr == "CRITICAL") return Severity::CRITICAL;
    else throw invalid_argument("Nivel de seguridad inválido");

}