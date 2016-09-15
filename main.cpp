
//////////////////////////////Prueba DE xREFERENCE//////////////////////7
/*

#include <iostream>
#include "Mesh Mem API/xReference.h"
#include "Mesh Mem API/Token.h"

int main() {
    int num=12;
    int * numPTR=&num;
    bool flag;
    xReference prueba(12,numPTR);
    xReference prueba2(13,numPTR);
    if (prueba==prueba2){
        cout<<"son iguales"<<endl;
    }
    if (prueba!=prueba2){
        cout<<"son diferentes"<<endl;
    }
    return 0;
}
*/
///////////////////////////PRUEBA DE JSON//////////////////////////////////////7

/*
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/prettywriter.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/rapidjson.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include "rapidjson/include/rapidjson/document.h"

using namespace std;
using namespace rapidjson;

int main(){

    const char* json= "{ \"hello\": \"world\",\"t\":true,"
            "\"f\": false,\"a\": [1, 2, 3, 4]}";
    Document document;
    StringStream s(json);
    document.ParseStream(s);
    //document["hello"].IsString();
    cout<<document["t"].GetBool()<<endl;
    return 0;

        StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("nodo");
    writer.String("ASDAS");
    writer.EndObject();
    cout<<s.GetString()<<endl;
    string output= s.GetString();
}
*/

/// //////////////////PRUEBA DE TOKEN///////////////////////////////
/*

#include "Mesh Mem API/HexConverter.h"
#include "Mesh Mem API/Token.h"
#include <iostream>
#include "stdio.h"
using namespace std;
int main(){
    Token* toke1=new Token();
    toke1->setToken();
    cout<<toke1->getToken()<<endl;
    HexConverter prueba2(toke1->getToken());
    prueba2.StringToHex();
    prueba2.hexToString();
    cout<<prueba2.getStr()<<endl;

    return 0;
}
*/

 /////////////////////PRUEBA SERVIDOR/CLIENTE ////////////////////////////


#include "Mesh  Mem  Client/Client.h"
#include <pthread.h>
using namespace std;
Client* cliente;
string entrada;

int main(){
    cliente = new Client();
    cliente->setConnection("172.26.98.52","8080");
    cliente->readData();
    cliente->writeData("hola");
    //thread read=thread(readLoop);
    //read.detach();
    //Declaracion de los threads
    //thread writeThread = thread(writeLoop);
    //writeThread.join();
    return 0;
}



/////////////////////////PRUEBA DE BASE64////////////////////////////////

/*
#include "Mesh Mem API/base64.h"
#include <iostream>
#include "stdio.h"
#include <string>
using namespace std;

int main(){
    string STR="Esoo cracks";
    string code;
    code= encode(STR,STR.length());
    cout<<code<<endl;
    cout<<decode(code)<<endl;
return 0;
}
*/
////////////////////////PRUEBA DE UUID/////////////////////////////////////
/*
#include "Mesh Mem API/UUID.h"
#include <iostream>
#include "stdio.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    UUID id=  UUID();
    cout<<id.getUUID()<<endl;
return 0;
}

*/

////////////////////////// PRUEBA DE API xMALLOC /////////////////////////////

/*
#include "Mesh Mem API/API.h"
#include <iostream>
#include "stdio.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    int po=99;
    int* ptr= &po;
    API prueba= API();
    API prueba2= API();
    API prueba3= API();


    prueba.xMalloc(8);
    cout<<*(prueba.xMalloc(8,ptr))<<endl;
    prueba2.xMalloc(9);
    prueba3.xMalloc(10);
    return 0;
}
 */