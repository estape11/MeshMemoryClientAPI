#include "Mesh Mem API/API.h"
using namespace std;

int main(){
    API memoria=API();
    string token=memoria.initialize("192.168.1.6", 8080);
    cout<<token<<endl;
    xReference referencia= memoria.xMalloc(4,xType::INTEGER);
    int numero=44;
    int* ptr=&numero;
    while(true) {
        string hola;
        cin >> hola;
        if (hola == "1") {
            memoria.xAssign(referencia, ptr);
        }
    }
    cout<<"Exito..."<<endl;
}

