#include<iostream>
#include<string>

using namespace std;

//This example lists the constructors in string

int main(){

    //empty string constructor default

    string empty{};

    //c-style constructor

    string hi{"Hello"};

    //repeated character constructor

    string repeated_x(3, 'x');
    cout<<"Repeated char string  "<<repeated_x<<endl;

    //substring constructor

    string substr1(hi,1);
    string substr2(hi,1,3);

    cout<<"Substring type 1::"<<substr1<<endl;
    cout<<"SubString constructor 2::"<<substr2<<endl;


    return 0;
}
