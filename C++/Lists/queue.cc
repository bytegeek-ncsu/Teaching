/**
 * @file queue.cc
 * @author Shak (shak@bytegeek.com)
 * @brief
 * @version 0.1
 * @date 2025-12-24
 *
 * @copyright Copyright (c) 2025
 *
 * This simpilified example demonstrate SinglyLinkedList operations.
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

class Queue
{
private:
    Node *head;
    Node *tail;
    int length = 0;

public:
    Queue(int);
    void printList();
    Node *getHead();
    Node *getTail();
    int getLength();

    void enqueue(int);
    int dequeue();
    
};

Queue::Queue(int value)
{
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length++;
}

void Queue::printList()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *Queue::getHead()
{
    return head;
}

Node *Queue::getTail()
{
    return tail;
}

int Queue::getLength()
{
    return length;
}

void Queue::enqueue(int value)
{
    Node *newNode = new Node(value);
    if (length == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}



int Queue::dequeue()
{
    if (length == 0)
        return -1;
    Node *temp = head;
    int rValue = head->value;
    if (length == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = temp->next;
    }
    delete temp;
    --length;
    return rValue;
}



int main()
{
    Queue queue(11);
    queue.enqueue(8);
    queue.enqueue(6);
    queue.printList();
    queue.dequeue();
    queue.printList();

    return 0;
}
