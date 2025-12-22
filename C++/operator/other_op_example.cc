/**
 * @file other_op_example.cc
 * @author Shak(shak@bytegeek.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-21
 * 
 * @copyright Copyright (c) 2025
 * 
 * In this class we further extend our c-type string class to add two operators == and + concatinator
 * 
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
    CSTR & operator=(const CSTR &); //copy assignment operator
    CSTR & operator=(CSTR &&); //assignment operator
    ~CSTR();

    bool operator==(CSTR &);
    CSTR operator+(CSTR &);

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

CSTR &CSTR::operator=(CSTR &&rhs){
    cout<<"------- move assignment constructor: "<<endl;
    if (this == &rhs)
        return *this;
    delete [] this->str;
    str = rhs.str;
    rhs.str = nullptr;
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

bool CSTR::operator==(CSTR &rhs){
    return strcmp(str, rhs.str) == 0;
}

CSTR CSTR::operator+(CSTR &rhs){
    char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff,rhs.str);
    CSTR temp{buff};
    delete [] buff;
    return temp;
}

int main(){
    CSTR a {"Vanakkam"};                // overloaded constructor
    a = CSTR("Yenna aga poguthu");      //Here it is calling overloaded single arg constructor to create temp object.
    //Then use move assignment operator to assign the value. 
    CSTR b {"Vanakkam"};                
    cout<<"Are they equal: "<<(a == b)<<endl;  
    CSTR cat =  a+b;
    cout<<"Concat string is :"<<cat.get_str()<<endl;       
    a = "Yamiruka bayamen Nanba";            // b.operator=("This is a test");
   
     
    return 0;
}