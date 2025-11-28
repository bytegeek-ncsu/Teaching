#include<iostream>

#include "list.h"

typedef List::Iterator iterator;


class Stack{
private:
    List l;

public:
    Stack(){
        l = List();
    }

    void push(Item item){
        iterator it;
        l.insertAfter(it, item);
    }

    void pop(){
        iterator it;
        l.removeAfter(it);
    }

    Item& peek(){
        auto it = l.begin();
        return it.getItem();
    }

    bool empty(){
        return l.empty();
    }


};

int main(){

    Stack stack;

    stack.push("milk");
    stack.push("eggs");
    stack.push("bread");

    std::cout<<stack.peek().getString()<<std::endl;
    stack.pop();
    std::cout<<stack.peek().getString()<<std::endl;
    stack.pop();
    std::cout<<stack.peek().getString()<<std::endl;
    stack.pop();
    
    return 0;
}