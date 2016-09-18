#include "Mesh Mem API/API.h"
#include "Mesh  Mem  Client/Client.h"
#include "Mesh Mem API/xType.h"
#include "Mesh Mem API/UUID.h"
using namespace std;
int main(){
    API memoria=API();
    string token=memoria.initialize("192.168.100.4", 8080);
    cout<<token<<endl;
    //memoria.xMalloc(5,0);
    cout<<"Exito..."<<endl;
    while(true){}

    return 0;
}
