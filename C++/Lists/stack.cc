/**
 * @file stack.cc
 * @author Shak (shak@bytegeek.com)
 * @brief
 * @version 0.1
 * @date 2025-12-24
 *
 * @copyright Copyright (c) 2025
 *
 * This simpilified example demonstrate stack data structure operations.
 * If we are using SLL kind of datastruture it is always good idea to push at the front because of 0(1)
 */
#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *head;
    int length = 0;

public:
    Stack(int);
    void printList();
    int peak();
    int getLength();
    void push(int value);
    void pop();

   };

Stack::Stack(int value)
{
    Node *newNode = new Node(value);
    head = newNode;
    length++;
}

void Stack::printList()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int Stack::peak()
{
    if(head)
     return head->value;
    return -1;
}


int Stack::getLength()
{
    return length;
}

void Stack::push(int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    
    length++;
}

void Stack::pop()
{
    if (length == 0)
        return;
    Node *temp = head;
    if (length == 1)
    {
        head = nullptr;
        
    }
    else
    {
        head = temp->next;
    }
    delete temp;
    --length;
}




int main()
{
    Stack stack(11);
    stack.push(8);
    cout<<stack.peak()<<endl;
    stack.pop();
    cout<<stack.peak()<<endl;
    return 0;
}
