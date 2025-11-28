#include<iostream>

using namespace std;

class refrigerator{
    int temp{2};
    bool door_open{false};
    bool power_on{true};

    public:
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