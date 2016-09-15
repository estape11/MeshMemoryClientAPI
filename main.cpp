#include "Mesh Mem API/API.h"
#include "Mesh  Mem  Client/Client.h"
using namespace std;
int main(){
    API memoria=API();
    memoria.initialize("192.168.24.104", 8080);
    cout<<"Exito..."<<endl;
    while(true){}
    return 0;
}
