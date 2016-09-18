#include "Mesh Mem API/API.h"
#include "Mesh Mem API/base64.h"
using namespace std;

int main(){/*
    API memoria=API();
    string token=memoria.initialize("192.168.100.3", 8080);
    cout<<token<<endl;
    memoria.xMalloc(5,xType::INTEGER);
    cout<<"Exito..."<<endl;
    */
    string test= "Hola anos de la vida";
    string b64=encode(test);
    cout<<b64<<endl;
    string str=decode(b64);
    cout<<str<<endl;
}
