/*
* First of all some of the members of the classes are called special
* Members. The reason is if we don't explicitly implement those members
* Compiler will implement for us.
* Special members are:
* default construction and destructor
* copy constructor and assignment operator
* move semantics
*/

/*
* When do you need copy constructor. Copy constructor called
* during object declaration and instialiaztion using other objects.
* When we are passing objects to funtion or returning objects
* from a function
*/

#include<iostream>

using namespace std;

class Rectangle{
    int len;
    int width;

    public:
    Rectangle():len{2}, width{2}{}
    Rectangle(int arg_len, int arg_wid):len{arg_len}, width{arg_wid}{}

    //Copy constructor
    /*
    *  format: className(const className& obj)
    * The we have to use reference otherwise it will lead infinite
    * Recursion
    */

    Rectangle(const Rectangle& rec){
        this->len = rec.len;
        this->width = rec.width;
    }

    void print(){
        cout<<"Length::"<<len<<" Width::"<<width<<endl;
    }
    
};

int main(){
    Rectangle rec;

    Rectangle rec1 = rec; //Copy constructor called
    rec1.print();
};