/*
    Namespace basically scope verifier for the identities in the C++
    programm. If we are including multiple libraries then offen
    we may encounter same identifier names and this will lead to ambiguity
    in our programm compilation. To avoid this we generally encompass our class
    names, functions and consts in a namespace. There is a globalnamespace
    provided by C++.

*/

#include<iostream>

using namespace std;

int x{45};

namespace shak{
    int x = 25;

}

int main(){

    cout<<"The value of the x from shak: "<<shak::x<<endl;
    cout<<"the value of the X from global name: "<<::x<<endl;

    return 0;
}