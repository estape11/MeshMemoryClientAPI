//
// Created by alecm on 10/09/16.
//

#include "UUID.h"
/**
 * Ejecuta linea de comando de la terminal que permite obtener un UUID
 * @param cmd Linea de comando a ejecutar
 * @return Retorna el valor del UUID en formato String
 */
string UUID::sendGetCmd(const char *cmd){
    char buffer[128];
    string result = "";
    shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer, 128, pipe.get()) != NULL)
            result += buffer;
        }
    return result;
}
/**
 * Obtiene el UUID invocando al metodo sendGetCmd()
 * @return Retorna el valor del UUID en formato String
 */
string UUID::getUUID() {return sendGetCmd("uuidgen");}
