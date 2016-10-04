#include "Mesh Mem API/API.h"
using namespace std;

int main(){
    API memoria=API();
    string token=memoria.initialize("192.168.100.3", 8080);
    cout<<token<<endl;
    xReference referencia= memoria.xMalloc(4,xType::INTEGER);
    int numero=44;
    int* ptr=&numero;
    memoria.xAssign(referencia, ptr);
    //memoria.xDereference(referencia);
    cout<<"Exito..."<<endl;
}

