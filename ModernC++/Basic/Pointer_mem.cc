#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int x = 10;
    int *p = &x;

    cout<<p<<endl;
    cout<<*p<<endl;

    int *ptr = new int[20];

    for (int i=0; i<20; i++)
        *(ptr+i) = i;
    
    for (int i=0; i<20; i++)
        cout<<*(ptr+i)<<" , ";
    cout<<endl;

    delete[] ptr; //Make sure you delete with this kind of [] syntax when you delete the array pointer
    



    return 0;
}