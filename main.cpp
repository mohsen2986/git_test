#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Singleton class
class MyDb {
private:
    static MyDb* iInstance;
    ifstream *ifstramLogin;
public:
    static MyDb* GetInstance();
    int * getUsersData();
private:
// private constructor
    MyDb();
};

MyDb* MyDb::iInstance = NULL;
MyDb::MyDb()
{
    this->ifstramLogin = new ifstream("../log.dat" , ios::in);
    if(!ifstramLogin){
        cout<< "the file not exist!!";
        exit(-1);
    }
}
MyDb* MyDb::GetInstance()
{
    if ( iInstance == NULL ) {
        iInstance = new MyDb();
    }
    return iInstance;
}
int* MyDb::getUsersData(){
    int age;
    static int ages[10];

    int i=0;
    while(!ifstramLogin->eof()){
        *ifstramLogin >> age;
        ages[i] = age;
        i++;
    }
    return ages;
}

int main() {
    MyDb* obj;
    obj = MyDb::GetInstance();

    int *a = obj->getUsersData();


    for(int i=0; *(a+i) != NULL; i++){
        cout<< *(a+i)<<endl;
    }

    system("pause");

    return 0;
}