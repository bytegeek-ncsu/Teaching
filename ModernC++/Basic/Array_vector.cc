#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
//Write a program which creates an empty vector of int and populates
//it with the values 4, 2, 3, 4, 1 in order

    vector<int> int_vector{4,2,3,4,1};

    cout<<int_vector[0]<<endl;

    for(auto el:int_vector)
        cout<<el<<" ,";
    cout<<endl;

    string hello{"Hello"};

    for (auto el: hello)
        cout<<el;

    hello[3] = 'b'; //or


for (auto el: hello)
        cout<<el;



    return 0;
}