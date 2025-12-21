/**
 * @file example5.cc
 * @author Shak (shak@bytegeek.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-18
 * 
 * @copyright Copyright (c) 2025
 * 
 * This example demonstrates Copy constructor.
 * Copy constructor called when we pass object as a value, return object and intialize an object using another
 * object during declaration.
 * Refer: Rule of 3.
 * Normally it is synthezied by the compiler
 * 
 */

#include <iostream>
#include <string>

using namespace std;

class Person{
    private:
        string name;
        int age;
        char gender;
        float weight;
    public:
        Person(string name="none", int age=0, char gender='-', float weight=0.0);

        //Reference parameter to avoid recursive copy constructor call
        //Const to avoid modifying source values
        Person(const Person &person);
        

        //Person(string);
        //Person(string, int);
        //Person(string, int, char);
        //Person(string, int, char, float);

        ~Person(){
            cout<<"------ This is default destructor -----"<<endl;
        }

        string getName();
        void setName(string);

        int getAge();
        void setAge(int);

        char getGender();
        void setGender(char);

        float getWeight();
        void setWeight(float);

        void displayPerson(Person);
        void displayPerson();

};


Person::Person(string name, int age, char sex, float wt):name(name), age(age), gender(sex), weight(wt){
    cout<<"------ Four Arg constructor: "<<name<<", "<<age<<", "<<gender<<", "<<weight<<endl;
}

Person::Person(const Person &person){
    cout<<"------ Copy constructor: ----------"<<endl;
    this->name = person.name;
    this->age = person.age;
    this->gender = person.gender;
    this->weight = person.weight;
}

string Person::getName(){
    return this->name;
}

void Person::setName(string name){
    this->name = name;
}

int Person::getAge(){
    return this->age;
}

void Person::setAge(int age){
    this->age = age;
}

char Person::getGender(){
    return this->gender;
}

void Person::setGender(char sex){
    this->gender = sex;
}

float Person::getWeight(){
    return this->weight;
}

void Person::setWeight(float wt){
    this->weight = wt;
}

void Person::displayPerson(Person person){
    cout<<"name: "<<person.name<<endl;
    cout<<"age: "<<person.age<<endl;
    cout<<"Gender: "<<person.gender<<endl;
    cout<<"Weight: "<<person.weight<<endl;
}

void Person::displayPerson(){
    cout<<"name: "<<this->name<<endl;
    cout<<"age: "<<this->age<<endl;
    cout<<"Gender: "<<this->gender<<endl;
    cout<<"Weight: "<<this->weight<<endl;
}

int main(){

    Person p;
    Person p1("Jo");
    Person p2{"Nila", 12};
    p.setName("Rishi");
    p.setAge(18);
    p.setGender('M');
    p.setWeight(130.8);

    

    p.displayPerson(p);
    p1.displayPerson();
    p2.displayPerson();

   

    return 0;
}