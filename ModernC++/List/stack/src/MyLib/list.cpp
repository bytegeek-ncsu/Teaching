#include<iostream>
#include"list.h"

typedef List::Iterator iterator;

List::List(){
    head = nullptr;
    tail = nullptr;
}

void List::append(Item item){
    ListNode *temp=  new ListNode(item, nullptr);
    if (head == nullptr){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }

}

bool List::remove(Item &copy){
    if (!empty()){
        ListNode* tmp = head;
        head = tmp->next;


        if(head == nullptr)//removed the last item in the list
            tail = head;
        copy = tmp->item;
        delete tmp;

        return true;

    }
    return false;
}

iterator List::begin(){
    return Iterator(head);
}

void List::insertAfter(iterator iter, Item item){
    if(iter.node == nullptr){ //It means we are inserting at head
        ListNode *tmp = new ListNode(item,head); // Here we are instating the new node with head as the next node
        if (head == nullptr){
            head = tmp;
            tail = tmp;
        }

        head = tmp;
    }else{
        ListNode *tmp = new ListNode(item, iter.node->next);
        iter.node->next = tmp;
        if(iter.node == tail)
            tail = tmp;
    }
}

void List::removeAfter(iterator it){
    if (empty() || it.node == tail)
        return; // Nothing to remove; Either the list is empty or iterator pointing the tail node nothing 
        //to remove after the tail.
    else if(it.node == nullptr){
        //Removing the head
        ListNode * remove = head;
        head = remove->next;
        delete remove;
        if (head == nullptr)
            tail = nullptr;// we remove the last member from the list
    }else{
        //Either removing in the middle or tail
        ListNode *tmp = it.node;
        ListNode *remove = tmp->next;
        tmp->next = remove->next;
        if (remove == tail)
            tail = tmp;
        delete remove;
    }
}

