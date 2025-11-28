#include<iostream>

class Shape{

public:
    virtual void draw() = 0;

};

class Rectangle: public Shape{

public:
    virtual void draw() override{
        std::cout<<"Rectangle::draw"<<std::endl;
    }
};

class Square: public Rectangle{

public:
     void draw() override{
        std::cout<<"Square::draw"<<std::endl;
    }
};

class Circle: public Shape{

public:
     void draw() override{
        std::cout<<"Circle::draw"<<std::endl;
    }
};

int main(){
    Shape *s = new Rectangle();
    s->draw();

    s = new Square();
    s->draw();

    s = new Circle();
    s->draw();

}
