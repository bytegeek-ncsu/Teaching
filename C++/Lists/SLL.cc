/**
 * @file SLL.cc
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

class SLL
{
private:
    Node *head;
    Node *tail;
    int length = 0;

public:
    SLL(int);
    void printList();
    Node *getHead();
    Node *getTail();
    int getLength();

    void append(int);
    void insertAtHead(int value);
    void deleteFirst();
    void deleteLast();
    Node *get(int);
    bool set(int, int);
    bool insert(int, int);
    bool remove(int);
};

SLL::SLL(int value)
{
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length++;
}

void SLL::printList()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *SLL::getHead()
{
    return head;
}

Node *SLL::getTail()
{
    return tail;
}

int SLL::getLength()
{
    return length;
}

void SLL::append(int value)
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

void SLL::insertAtHead(int value)
{
    Node *newNode = new Node(value);
    if (length == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    length++;
}

void SLL::deleteFirst()
{
    if (length == 0)
        return;
    Node *temp = head;
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
}

Node *SLL::get(int index)
{
    Node *temp = nullptr;
    if (index < 0 || index >= length)
        return nullptr;
    temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    return temp;
}

void SLL::deleteLast()
{
    //Node* temp;
    if (length == 0)
        return;
    Node *temp = tail;
    if (length == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node* before  = get(length - 2); //Get the node just before the tail;
        //temp = tail;
        before->next = nullptr;
        tail = before;
        
    }
    delete temp;
    --length;
}



bool SLL::set(int index, int value)
{
    Node *temp = get(index);
    if (temp)
    {
        temp->value = value;
        return true;
    }
    return false;
}

bool SLL::insert(int index, int value)
{
    if (index < 0 || index > length)
        return false; // out of range
    if (index == 0)
    {
        insertAtHead(value);
        return true;
    }
    else if (index == length)
    {
        append(value);
        return true;
    }
    else
    {
        Node *newNode = new Node(value);
        Node *before = get(index - 1);
        Node *after = before->next;
        before->next = newNode;
        newNode->next = after;
        return true;
    }
}

bool SLL::remove(int index)
{
    if (index < 0 || index >= length)
        return false; // out of range
    if (index == 0)
    {
        deleteFirst();
        return true;
    }
    else if (index == length - 1)
    {
        deleteLast();
        return true;
    }
    else
    {
        Node *before = get(index-1);
        Node *temp = before->next;
        before->next = temp->next;
        delete temp;
        return true;
    }
}

int main()
{
    SLL sll(11);

    sll.append(8);
    sll.append(5);
    sll.insertAtHead(7);
    sll.printList();
    sll.deleteLast();
    sll.deleteLast();
    sll.printList();

    return 0;
}
