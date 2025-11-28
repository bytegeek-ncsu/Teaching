#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){

    string names[] = {"one", "four", "two", "three"};

    

    for (int i=0;i<2; i++)
        for(int j=0; j<2; j++)
            cout<<*(names+i*2+j)<<endl;




    return 0;
}