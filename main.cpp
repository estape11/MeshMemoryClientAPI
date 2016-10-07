#include "Mesh Mem API/API.h"
using namespace std;

int main(){
    API memoria=API();
    string token=memoria.initialize("192.168.0.22", 8080);
    cout<<token<<endl;
    xReference referencia= memoria.xMalloc(4,xType::INTEGER);
    int numero=44;
    memoria.xAssign(referencia, &numero);

    cout<<*(int*)(memoria.xDereference(referencia))<<endl;

    xReference referencia2= memoria.xMalloc(1,xType::CHAR);
    //char hola='h';
    //memoria.xAssign(referencia2, &hola);

    //char valor=*(char*)(memoria.xDereference(referencia2));

    //cout<<valor<<endl;

    cout<<"Exito..."<<endl;

}

