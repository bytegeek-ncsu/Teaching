#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Template is way you can do do generic programming in C++
//The code and everything is same but the data it operates is different
//Instead of specific data type we use generic data type
//The compiler will actually insert the new class type when we instantiate
//new type.

//CTAD
//Constructor template argument deduction is the feautre in c++17 will identifiy 
//based on the values and we don't need to provide specfic type during
//instantiation
// vector<int> vec = {1,3,5}
//But in new c++ 17 we can do something like this
//vector vec{1,3,5}

template <class T>
T Min(const T& a , const T& b){

    if (a<b)
        return a;
    else
        return b;
}

int main(){

    double a = 3.14;
    double b = 1.34;

    cout<<"The templace function test: "<<Min(a,b)<<endl;



    return 0;
}