#include <iostream>
#include <fstream>

using namespace std;

enum class Severity {DEBUG, INFO, WARNING, ERROR, CRITICAL};

void logMessage(string msj, Severity nivel_svr) {

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
        default:
            cout << "No debería entrar acá porque ya se hizo la verificación del input \n";
            return;
    }

    ofstream outFile("logs.txt", ios::app);
    if(outFile.is_open()) {
        outFile << msj_final;
        outFile.close();
    } else
        cerr << "Error abriendo el archivo \n";

    return;
}

Severity convert_str_to_svr(const string svr) {

    if (svr == "DEBUG") return Severity::DEBUG;
    else if (svr == "INFO") return Severity::INFO;
    else if (svr == "WARNING") return Severity::WARNING;
    else if (svr == "ERROR") return Severity::ERROR;
    else if (svr == "CRITICAL") return Severity::CRITICAL;
    else throw invalid_argument("Nivel de seguridad inválido");

}