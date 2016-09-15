#include "Mesh Mem API/API.h"
#include "Mesh  Mem  Client/Client.h"
using namespace std;
int main(){
    API memoria=API();
    string token=memoria.initialize("192.168.24.104", 8080);
    cout<<token<<endl;
    cout<<"Exito..."<<endl;
    while(true){}
    return 0;
}
