/*
* This is a model class  behaves cstring
*/

/*
* How to use this class:
    cstr c = "Hello";

    c.get(0) = 'p'

    c.get(100) = 'X'

    c.print()
*/

/*
1. Default constructor creates nullptr
2. One that create blank string with given size
3. one that initializes literal character string

4. access or modify the string specific index
5. Out of bounds handled silently. Weird spec.
*/

/*
* Copy constructor: The default copy constructor will just copy
shallow copy only. Where as we need deep copy. So we need to implement
Copy constructor
*/

#include<iostream>
#include<string.h>

using namespace std;

class cstr{

    char* array;
    int size;
    char dummy; // This is for handling out-of-bound access

public:
    cstr():array{nullptr}, size{0}{}
    cstr(int len): size{len}{
        array = new char[size+1];
        for (int i=0; i<size+1; ++i){
            array[i] = ' ';
            array[size+1] = 0; //null termiator
        }
    }
    cstr(const char* str){
        size = strlen(str);
        strcpy(array,str);

    }
    ~cstr(){
        delete [] array;
    }

    cstr(const cstr& other){
        size = other.size;
        array = new char[size+1];
        strcpy(array,other.array);
    }

    /*
    * Assignment operator
    * When we are implementing assignment operator we need to focus
    * few things.
    * 1. if we are self referencing then we should not create a and
    * new one which will lead nasty bugs
    * 2. If the object has already initialized we need to first cleanup
    * and then allocate new memory and other setup.
    */

    cstr& operator = (const cstr& other){
        if (this == &other)
            return *this;
        if (size > 0)
            delete [] array;
        size = other.size;
        array = new char [size+1];
        strcpy(array,other.array);
        return *this;

    }

    char& get(int index){
        if (index < 0 || index >= size)
         return dummy;
        return array[index];
    }

    //We can implement the above function has operator
    // we need to overload operator []
    //so user can do cstr[index]

    char& operator [] (int index){
        if (index < 0 || index >= size)
         return dummy;
        return array[index];
    }


    void print(){
        cout<<"Length of the string::"<<size<<endl;
        cout<<"String field is::"<<array<<endl;
    }

};

int main(){

    cstr example = "Hello";

    example.print();

    example.get(0) = 'P';

    cstr c1 = example;

    example.print();

    c1.get(1) = 'X';
    c1[2] = 'Z';

    c1.print();

    return 0;
}