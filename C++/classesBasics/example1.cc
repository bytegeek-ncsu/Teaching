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
        Person(){
            cout<<"----- this is default constructor-----"<<endl;
        };

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

};

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

int main(){

    Person p;
    p.setName("Rishi");
    p.setAge(18);
    p.setGender('M');
    p.setWeight(130.8);

    p.displayPerson(p);

    //In the output out destructor is getting called two time even though we call constructor here one time?
    //The reason is when we are passing person object p in display person it is getting copied into person object in the stack.
    //When the function call ends it calls the person destructor. When we try to exit main the object p destructor called.
    //This will be explained more in copy constructor

    return 0;
}