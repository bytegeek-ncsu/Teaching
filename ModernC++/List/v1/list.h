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

        ListNode(Item aitem, ListNode *a_next):item(aitem), next(a_next){}

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


};
