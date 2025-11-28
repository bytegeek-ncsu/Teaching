#include<iostream>

class Vehicle{
    int max_speed;

public:
    Vehicle():max_speed(0){
        std::cout<<"I am in the default constructor of the Vechicle"<<std::endl;
    }
    Vehicle(int a_max_speed):max_speed(a_max_speed){
        std::cout<<"I am in the Single argument constructor of the Vechicle"<<std::endl;
    }

    void print(){
        std::cout<<"The maximum height of the of the plance is::"<<max_speed<<std::endl;
    }

};

class Aeroplane: public Vehicle{
    int max_height;

public:
    Aeroplane():Vehicle(5),max_height(0){
        std::cout<<"I am in the default constructor of the Aeroplane"<<std::endl;
    }
    Aeroplane(int a_max_height):Vehicle(10),max_height(a_max_height){
        std::cout<<"I am in the Single argument constructor of the Aeroplane"<<std::endl;
    }

    void print(){
        std::cout<<"The maximum height of the of the plance is::"<<max_height<<std::endl;
    }

};

class Fighterplane : public Aeroplane{
    int bombs_type;

public:
    Fighterplane():bombs_type(0){
        std::cout<<"I am in the default constructor of the Figher Plane"<<std::endl;
    }
    Fighterplane(int a_bomb_type):Aeroplane(100), bombs_type(a_bomb_type){
        std::cout<<"I am in the Single argument constructor of the Figher Plane"<<std::endl;
    }

    void print(){
        std::cout<<"The bomb type is::"<<bombs_type<<std::endl;
    }


};

int main(){
    Vehicle v;
    v.print();
    Aeroplane plane;
    plane.print();
    Fighterplane fplane;
    fplane.print();



    return 0;
}