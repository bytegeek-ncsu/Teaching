/**
 * @file assignment_example.cc
 * @author Shak (shak@bytegeek.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-20
 * 
 * @copyright Copyright (c) 2025
 * 
 * This demonstrates the assignment operator for my c-type string.
 */
#include <cstring>
#include <iostream>

using namespace std;

class CSTR{
private:
    char *str; //
public:
    CSTR();
    CSTR(const char *); //overloaed one-arg constructor
    CSTR(const CSTR &); //copy constrtor
    CSTR & operator=(const CSTR &); //assignment operator
    ~CSTR();

    void display() const;
    const char * get_str() const;
    int getLength() const;
    
};

CSTR::CSTR():str(nullptr){
    cout<<"------- Default constructor: emptry string"<<endl;
    str = new char[1];
    str[0] = '\0';

}

CSTR::CSTR(const char *arg){
    cout<<"------- single argument constructor: "<<endl;
    str = new char[strlen(arg)+1]; //+1 for null terminator
    strcpy(str, arg);
    
}

CSTR::CSTR(const CSTR &source){
    cout<<"------- Copy constructor: "<<endl;
    str = new char[strlen(source.str)+1];
    strcpy(str, source.str);
}

/**
 * @brief THis is an assignment operator
 * We need to three things.
 * 1. Check whether they are referencing the same: In that case just return *this.
 * 2. Deallocate the existing fields and resource.
 * 3. deep copy the rhs fields to the calling object
 * 
 * @return CSTR& 
 */

CSTR &CSTR::operator=(const CSTR &rhs){
    cout<<"------- copy assignment constructor: "<<endl;
    if (this == &rhs)
        return *this;
    delete [] this->str;
    str = new char[strlen(rhs.str)+1];
    strcpy(str, rhs.str);
    return *this;
}

CSTR::~CSTR(){
    cout<<"------- CSTR destructor: "<<endl;
    delete [] str;
}

void CSTR::display() const{
    cout<<"String is: "<<str<<endl;
}

const char * CSTR::get_str() const{
    return str;
}

int CSTR::getLength() const {
    return strlen(str);
}

int main(){
    CSTR a {"Vanakkam"};                // overloaded constructor
    CSTR b;                          // no-args contructor
    b = a;                           // copy assignment b.operator=(a)
                                                   
    b = "Yamiruka bayamen Nanba";            // b.operator=("This is a test");
    /**
     * In the above statement first create temp cstring object calling one argument constror.
     * and then it calls b.operator=(tempobject). This is where we can use move assignment instread
     * regualr copy assignemt operator. temp object is perfect canditate for r-reference. will implement next.
     * 
     */
    return 0;
}