#include<iostream>
#include<string>

#pragma once

 

class List{
private:
    class ListNode{
    public:
        std::string item;
        ListNode* next;
    public:
        ListNode():item(nullptr),next(nullptr){}

        ListNode(std::string item, ListNode *a_next):item(item), next(a_next){}

    };

    ListNode* head;
    ListNode *tail;

public:
    List();
    bool empty(){
        return head==nullptr;
    }

    void append(std::string item);

    bool remove (std::string &copy);


};
