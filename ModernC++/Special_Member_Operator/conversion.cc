#include<iostream>

class A{
    int x;

public:
    A():x(0){}
    A(int ax=0):x(ax){}

    //After adding conversion operator
    operator int() {return x;}


};


int main(){
    A a = 5;
    //The below code will be error since there is no conversion operator.

    //std::cout<<a<<std::endl;

    //int x = a; This code will fail there is no conversion operator

    //after implementiong conversion operator
    std::cout<<a<<std::endl;

    
}