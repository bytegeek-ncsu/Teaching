#include<iostream>
#include<string>

using namespace std;

/*
* This program illustrates construction and destruction of classes
* in various scopes. Global, Local and Heap. The intersting aspect is 
* destruction never happends to objects in the heap unless it is explici
called.
*/

class Verbose{
    string msg;

    public:
        Verbose(string scope){
            msg = scope;
            cout<<"I am born  in this scope "<<msg<<endl;
        }

        ~Verbose(){
            cout<<"I am dead  in this scope "<<msg<<endl;
        }
};

Verbose global("Global");

int main(){
    cout<<"main starts here"<<endl;
    Verbose local("Local");
    Verbose *heap = new Verbose("Heap");
    delete heap;
    cout<<"Main ends here"<<endl;
    return 0;
}