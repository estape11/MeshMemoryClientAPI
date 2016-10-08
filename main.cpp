#include "Mesh Mem API/API.h"
using namespace std;

int main(){
    API memoria=API();
    cout<<"Iniciando conexion"<<endl;
    string token=memoria.initialize("172.26.109.10", 8080);
    cout<<"Token: "<<token<<endl;
    cout<<"xMalloc de 4 bytes"<<endl;
    xReference referencia= memoria.xMalloc(4,xType::INTEGER);
    int numero=44;
    memoria.xAssign(referencia, &numero);
    cout<<*(int*)(memoria.xDereference(referencia))<<endl;
    cout<<"xMalloc de 1 bytes"<<endl;
    xReference referencia2= memoria.xMalloc(1,xType::CHAR);
    memoria.xFree(referencia);
    cout<<"xMalloc de 2 bytes"<<endl;
    xReference referencia3=memoria.xMalloc(2,xType::INTEGER);
    int num=544;
    memoria.xAssign(referencia3,&num);
    cout<<*(int*)(memoria.xDereference(referencia3))<<endl;
    memoria.xFree(referencia2);
    cout<<"Exito..."<<endl;

}

