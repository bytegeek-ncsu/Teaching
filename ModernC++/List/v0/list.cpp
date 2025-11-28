#include<iostream>
#include"list.h"

List::List(){
    head = nullptr;
    tail = nullptr;
}

void List::append(std::string item){
    ListNode *temp=  new ListNode(item, nullptr);
    if (head == nullptr){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }

}

bool List::remove(std::string &copy){
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

    std::string item1 = "milk";
    std::string item2 = "egg";
    std::string item3 = "bread";
    

    l.append(item1);
    l.append(item2);
    l.append(item3);

    std::string copy;

    while(l.remove(copy))
        std::cout<<"Item removed is ::"<<copy<<std::endl;

    return 0;
}
