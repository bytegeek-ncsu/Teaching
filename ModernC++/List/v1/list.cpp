#include<iostream>
#include"list.h"

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

int main(){

    List l;

    Item item1 = "milk";
    Item item2 = "egg";
    Item item3 = "bread";
    

    l.append(item1);
    l.append(item2);
    l.append(item3);

    Item copy;

    while(l.remove(copy))
        std::cout<<"Item removed is ::"<<copy.getString()<<std::endl;

    return 0;
}
