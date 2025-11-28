#include<iostream>

#include "list.h"

typedef List::Iterator iterator;


class Queue{
private:
    List l;

public:
    Queue(){
        l = List();
    }

    void push(Item item){
        l.append(item);
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

    Queue queue;

    queue.push("milk");
    queue.push("eggs");
    queue.push("bread");

    std::cout<<queue.peek().getString()<<std::endl;
    queue.pop();
    std::cout<<queue.peek().getString()<<std::endl;
    queue.pop();
    std::cout<<queue.peek().getString()<<std::endl;
    queue.pop();
    
    return 0;
}