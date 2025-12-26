/**
 * @file ctr_assign_example.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-22
 * 
 * @copyright Copyright (c) 2025
 * 
 * This code demonstrate the base class and derived class constructors and assignment operators
 */
#include <iostream>
using namespace std;

class Base{

private:
    int value;

public:
    Base():value(0){
        cout<<"Base class default no-arg constructor"<<endl;
    }

    Base(int value):value(value){
        cout<<"Base class Single arg overloaded constructor"<<endl;
    }

    Base(const Base &other){
        cout<<"Base class copy constructor"<<endl;
        this->value = other.value;
    }

    Base & operator=(const Base &rhs){
        cout<<"Base class copy assignment operator method"<<endl;
        if (this != &rhs){
            this->value = rhs.value;
        }

        return *this;
    }

    ~Base(){
        cout<<"Base class destructor"<<endl;
    }

};

class Derived: public Base{

private:
    int doubleValue;

public:
    Derived():Base(),doubleValue(0){
        cout<<"Derived class default no-arg constructor"<<endl;
    }

    Derived(int dValue):Base(dValue), doubleValue(dValue){
        cout<<"Derived class Single arg overloaded constructor"<<endl;
    }

    Derived(const Derived &other): Base(other){
        cout<<"Derived class copy constructor"<<endl;
        this->doubleValue = other.doubleValue;
    }

    Derived & operator=(const Derived &rhs){
        cout<<"Derived class copy assignment operator method"<<endl;
        if (this != &rhs){
            Base::operator=(rhs);
            this->doubleValue = rhs.doubleValue;
        }

        return *this;
    }

    ~Derived(){
        cout<<"Derived class destructor"<<endl;
    }

};

int main(){

    Base base{100};
    Base base1{base};
    base = base1;

    Derived d{2000};
    Derived d1{d};
    d = d1;

    return 0;
}