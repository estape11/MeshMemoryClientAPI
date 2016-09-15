//
// Created by jeanpolalvarado on 09/09/16.
//

#include "tcpClient.h"
#include "../rapidjson/include/rapidjson/prettywriter.h"
#include <cstdio>
#include "../rapidjson/include/rapidjson/document.h"

using namespace std;
using namespace rapidjson;

ssize_t send(int string, const char *i, unsigned long i1);

void tcpClient::init() {
    const char* json= "{ \"hello\": \"world\"}";
    //document["hello"].IsString();
    int sock;
    struct sockaddr_in server;
    char message[1000], server_reply[1000];
    int len;

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("192.168.0.14");//127.0.0.1
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    //Connect to remote server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect failed. Error");
    }

    puts("Connected\n");

    Document document;

    document.Parse<0>(json);

    StringBuffer strbuf;
    strbuf.Clear();

    Writer<StringBuffer> writer(strbuf);
    document.Accept(writer);

    const char *koko = strbuf.GetString();
    cout<<koko<<endl;
    const char *str1  = koko;
    cout<<str1<<endl;

    //keep communicating with server
    while ((len = recv(sock, server_reply, sizeof(server_reply), 0)) > 0) {
        printf("Server reply: %.*s", len, server_reply);
        printf("Enter message :");
        if ((&str1, sizeof(&str1), stdin) == NULL)
            break;
        //Send some data
        cout<<" Bytes enviados "<<send(sock,str1,strlen(str1),0)<<endl;
        if ((send(sock, str1,strlen(str1),0)<0)){
            puts("Send failed");
        }
    }
    close(sock);
}

ssize_t send(int string, const char *i, unsigned long i1) {
    return 0;
}


