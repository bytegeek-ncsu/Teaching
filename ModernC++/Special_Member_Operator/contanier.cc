#include<iostream>
#include<vector>
class Shape{

public:
    void draw(){
        std::cout<<"Shape::draw"<<std::endl;
    }

};



class Circle: public Shape{

public:
    void draw(){
        std::cout<<"Circle::draw"<<std::endl;
    }


};

void draw_shape(Shape& shape){
    shape.draw();
}

void draw_shape(Circle& circle){
    circle.draw();
}

int main(){
    std::vector<Shape *> shapes;
    shapes.push_back(new Circle());

    for(auto e:shapes)
        e->draw();
    
    for (auto e:shapes)
        delete e;
    
    Circle circle;
    Shape& shape = circle;

    draw_shape(circle);
    draw_shape(shape);


    return 0;
}