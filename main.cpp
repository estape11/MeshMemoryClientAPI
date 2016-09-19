#include "Mesh Mem API/API.h"
using namespace std;

int main(){
    API memoria=API();
    string token=memoria.initialize("192.168.100.3", 8080);
    cout<<token<<endl;
    //xReference referencia= memoria.xMalloc(5,xType::INTEGER);
    while(true){}
    cout<<"Exito..."<<endl;
}

