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
* Assignment operator is a special member function used
* used to initialize the object from another existing '
* Object. The intersting aspect is we declare the object in one place
* and then inialize in a different statment.
*/

#include<iostream>

using namespace std;

class Rectangle{
    int len;
    int width;

    public:
    Rectangle():len{2}, width{2}{}
    Rectangle(int arg_len, int arg_wid):len{arg_len}, width{arg_wid}{}

    //Assignment Operator
    /*
    *  format: className& operator = (const className& obj)
    * The we have to use reference otherwise it will lead infinite
    * Recursion
    */

    Rectangle& operator = (const Rectangle& rec){
        this->len = rec.len;
        this->width = rec.width;
        return *this;
    }

    void print(){
        cout<<"Length::"<<len<<" Width::"<<width<<endl;
    }
    
};

int main(){
    Rectangle rec(10,10);
    Rectangle rec1;

    rec1 = rec; //Assignment operator called
    rec1.print();
};