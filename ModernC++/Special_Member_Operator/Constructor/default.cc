#include<iostream>

using namespace std;

class refrigerator{
    int temp;
    bool door_open;
    bool power_on;

    public:
    void print(){
        cout<<"Refrigerator temp::"<<temp;
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