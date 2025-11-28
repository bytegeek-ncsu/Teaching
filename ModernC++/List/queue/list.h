#include<iostream>
#include<string>
#include "item.h"

#pragma once

 

class List{
private:
    class ListNode{
    public:
        Item item;
        ListNode* next;
    public:
        ListNode():item(nullptr),next(nullptr){}

        ListNode(Item aitem, ListNode *a_next=nullptr):item(aitem), next(a_next){}

    };

    ListNode* head;
    ListNode *tail;

public:
    List();
    bool empty(){
        return head==nullptr;
    }

    void append(Item item);

    bool remove (Item &copy);

    class Iterator{
        public: ListNode * node;

        Iterator():node(nullptr){}

        Iterator(ListNode *n): node(n){}

        Item& getItem(){
            return node->item;
        }

        void increment(){
            node=node->next; //move to the next node from the current node
        }

        bool end(){
            return node == nullptr;
        }

    };

    Iterator begin();

    void insertAfter(Iterator,Item);
    void removeAfter(Iterator);


};
