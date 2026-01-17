/**
 * Implement a member function called reverse() that reverses the order of the nodes in the list.
 * Input:
 * The function is a member of the DoublyLinkedList class, which has a head and a tail pointer, as well as a length attribute.
 */
#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node *next;
        Node *prev;

        Node(int value){
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DLL{
    private:
        Node* head;
        Node* tail;
        int length = 0;

    public:
        DLL(int);
        void printList();
        Node* getHead();
        Node* getTail();
        int getLength();

        void append(int);
        void insertAtHead(int value);
        void deleteFirst();
        void deleteLast();
        Node* get(int);
        bool set(int, int);
        bool insert(int, int);
        bool remove(int);
        bool isPalindrome();
        void reverse();
};

DLL::DLL(int value){
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length++;
}

void DLL::printList(){
    Node* temp = head;
    while(temp){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* DLL::getHead(){
    return head;
}

Node* DLL::getTail(){
    return tail;
}

int DLL::getLength(){
    return length;
}

void DLL::append(int value){
    Node* newNode = new Node(value);
    if (length == 0){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
}

void DLL::insertAtHead(int value){
    Node* newNode = new Node(value);
    if(length == 0){
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length++;
}

void DLL::deleteFirst(){
    if(length == 0) return;
    Node* temp = head;
    if (length == 1){
        head = nullptr;
        tail = nullptr;
    }else{
        head = temp->next;
        head->prev = nullptr;
    }
    delete temp;
    --length;
}

void DLL::deleteLast(){
    if (length == 0) return;
    Node *temp = tail;
    if (length == 1){
        head = nullptr;
        tail = nullptr;
    }else{
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    --length;
}

Node* DLL::get(int index){
    Node* temp = nullptr;
    if (index<0 || index >= length) return nullptr;
    if (index < length/2){//first half of the list: start from head
        temp = head;
        for(int i=0; i < index; i++){
            temp = temp->next;
        }
    }else { //2nd of the list;
        temp = tail;
        for(int i=length-1; i > index; i--){
            temp = temp->prev;
        }
    }
    return temp;
}

bool DLL::set(int index, int value){
    Node* temp = get(index);
    if(temp){
        temp->value = value;
        return true;
    }
    return false;
}

bool DLL::insert(int index, int value){
    if (index < 0 || index > length) return false; //out of range
    if (index == 0){
        insertAtHead(value);
        return true;
    }else if (index == length){
        append(value);
        return true;
    }else{
        Node* newNode = new Node(value);
        Node* before = get(index - 1);
        Node* after  = before->next;
        before->next = newNode;
        newNode->prev = before;
        after->prev = newNode;
        newNode->next = after;
        return true;
    }
}

bool DLL::remove(int index){
    if (index < 0 || index >= length) return false; //out of range
    if(index == 0){
        deleteFirst();
        return true;
    }else if (index == length - 1){
        deleteLast();
        return true;
    }else {
        Node* temp = get(index);
        Node* before = temp->prev;
        Node* after = temp->next;
        before->next = after;
        after->prev = before;
        delete temp;
        return true;
    }

}
/**
 * isPalindrome:
 * 1. Calculate the number of iterations
 *  if length is given number of iterations is length/2 (integer division is enough)
 * 2. Initialize two pointer. 
 *   forward = head; backward = tail.
 *   check both forward->value == backward->value
 *   if true for entire iteration then it is a palindrome.
 * 3. Corner cases:
 *    empty or one node then it is already palindrome 
 */


bool DLL::isPalindrome(){
    if (length ==0 || length == 1)
        return true;
    int loop_count = length/2;
    Node *forward = head;
    Node *backward = tail;
    for (int i=0; i<loop_count; i++){
        if (forward->value != backward->value)
            return false;
        forward = forward->next;
        backward = backward->prev;
    }

    return true;
}

/**
 * In this method all previous pointers should point next and vice versa.
 * Init:
 * start with temp which is previous of head point null at the begninging
 * current = head
 * in the loop:
 *  if current is null exit the loop.
 *  Loop body:
 *      temp = current->previous
 *      current->previous = current->next;
 *      current->next = temp;
 *          
 *      current = current->previous (to move forward)
 *      
 */

void DLL::reverse(){
    Node *current, *temp;
    temp = nullptr;
    current = head;

    while(current){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
        //temp = current->prev;
        
    }
    temp = head;
    head = tail;
    tail = temp;
}




int main(){
    DLL dll(1);

    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.printList();
    cout<<"Is palindrom ? :"<<dll.isPalindrome()<<endl;
    dll.reverse();
    dll.printList();

    return 0;
}