//
// Created by jeanpolalvarado on 13/09/16.
//

#include "Client.h"
void error(const char *msg){
    perror(msg);
    exit(0); }

/**
 * Inicia la comunicacion con el servidor
 * @param ip Ip del servidor
 * @param port PUerto por el que comunicara
 * @param data Informacion que enviara
 */
void Client::setConnection(string ip, string port) {
    portno = atoi(port.c_str());
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        error("ERROR opening socket");
    server = gethostbyname(ip.c_str());
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    setVariables();
}

/**
 * Inicia variables necesarias para la comunicacion
 */
void Client::setVariables(){
    bzero((char*) &ip_adress, sizeof(ip_adress));
    ip_adress.sin_family = AF_INET;
    bcopy(server->h_addr,
          (char *)&ip_adress.sin_addr.s_addr,
          server->h_length);
    ip_adress.sin_port = htons(portno);
    if (connect(sock,(struct sockaddr *) &ip_adress,sizeof(ip_adress)) < 0)
        error("ERROR connecting");
}

/**
 * Invoca al metodo write() el cual envia el mensaje al servidor
 * @param data Mensaje a enviar
 * @return Retorna True si logro enviar el mensaje
 */
bool Client::writeData(string data){
    data+='\n';
    n = send(sock,data.c_str(),data.length(),0);
    if (n < 0){
        error("ERROR writing to socket");
        return false;}
    return true;
}

/**
 * Lee lo que el servidor envia por medio del metodo read()
 * @return Retorna el mensaje enviado por parte del Servidor
 */
string Client::readData(){
    char buffer[1];
    string reply;
    if( recv(sock , buffer , sizeof(buffer) , 0) < 0){
        puts("recv failed");
    }
    reply = buffer;
    return reply;

}

string Client::read2(){
    string message="";
    string character="";
    while(true) {
        character = readData();
        message+= character;
        if(character=="\n"){
            break;
        }
    }
    return message;
}
