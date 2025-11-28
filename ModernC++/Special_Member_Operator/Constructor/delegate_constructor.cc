#include<iostream>

using namespace std;

class Internet{
    public:
    void login(const string & id, const string &pwd ){
        cout<<"The logged in user name is::"<<id<<endl;
        cout<<"The passwd is::"<<pwd<<endl;
    }

};

class refrigerator{
    int temp{2};
    bool door_open{false};
    bool power_on{true};
    Internet internet;

    public:
    //default constructor

    refrigerator() : refrigerator(2, "me", "secret"){}

    //constructor using default login

    refrigerator(int temp_arg) : refrigerator(temp_arg, "me", "secret"){}

    //Constructor using default temperature
    refrigerator(const string &uid, const string &pwd) : refrigerator(2, uid, pwd){}
    refrigerator(int temp_arg, const string &uid, const string &pwd_arg): temp{temp_arg}{
        internet.login(uid,pwd_arg);
    }

    
    void print(){
        cout<<"Refrigerator temp::"<<temp<<endl;
        cout<<boolalpha;
        cout<<"door status::"<<door_open<<endl;
        cout<<"Powert status::"<<power_on<<endl;

    }


};

int main(){
    refrigerator fridge;
    fridge.print();
    return 0;
}