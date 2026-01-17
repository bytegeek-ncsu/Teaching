/**
 * Write a method swapPairs() that swaps every two adjacent nodes in a singly linked list.
 * The method should not create new nodes.
 * You must update the node connections (i.e., .next pointers) to perform the swap.
 * This method should modify the list in place.
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
    Node *findMiddleNode();
    bool hasLoop();
    void removeDuplicates();
    int binaryToDecimal();
    void partitionList(int x);
    void reverseBetween(int x, int y);
    void swapPairs();
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
    // Node* temp;
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
        Node *before = get(length - 2); // Get the node just before the tail;
        // temp = tail;
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
        Node *before = get(index - 1);
        Node *temp = before->next;
        before->next = temp->next;
        delete temp;
        return true;
    }
}

Node *SLL::findMiddleNode()
{
    Node *slow, *fast;
    slow = head;
    fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool SLL::hasLoop()
{
    Node *slow, *fast;
    slow = head;
    fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
            return true;
    }

    return false;
}

void SLL::removeDuplicates()
{
    Node *current, *runner, *prev;
    current = runner = head;

    if (length == 0)
        return;

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            prev = runner;
            runner = runner->next;
            if (current->value == runner->value)
            {
                prev->next = runner->next;
                // need to implement delete.
                length--;
            }
        }

        current = current->next;
        runner = current;
    }
}

int SLL::binaryToDecimal(){
    int result = 0;
    Node *current = head;
    while(current){
        result = result*2 + current->value;
        current=current->next;
    }

    return result;
}

void SLL::partitionList(int x){
    Node *temp1 = new Node(0);
    Node *temp2 = new Node(0);
    Node *temp, *prev1, *prev2;
    prev1 = temp1;
    prev2 = temp2;
    temp = head;
    while(temp){
        if (temp->value < x){
            prev1->next = temp;
            prev1 = temp;
        }else{
            prev2->next = temp;
            prev2 = temp;
        }
        temp = temp->next;
    }
    prev1->next = temp2->next;
    head = temp1->next;
    prev2->next = nullptr;
}

/**
 * 1. create a dummy node. add the dummy node before head.
 * 2. create a new pointer prev and move it just before index x.
 * 3. Mark the current pointer to index x.
 * 4. Mark the the pointer to move index x+1.
 * 5. Loop count y - x. 
 * 6. Inside the the loop: 
 *      current->next = to_move->next;
        to_move->next = prev->next;
        prev->next = to_move;
        to_move = current->next;
 * 7. head = temp->next;
 * free temp;
 */

void SLL::reverseBetween(int x, int y){
    if(length == 0) return;
    Node *temp = new Node(0);
    temp->next = head;
    Node *prev, *current, *to_move;
    int index = 0;
    prev = temp;

    while (index++<x)
        prev = prev->next;
    current = prev->next;
    to_move = current->next;
    int loop_count = y - x;
    for (int i=0; i<loop_count;i++){
        current->next = to_move->next;
        to_move->next = prev->next;
        prev->next = to_move;
        to_move = current->next;
    }

    head = temp->next;
    delete temp;
}

/**
 * 1. create a dummy Node and make dummy->next point to head
 * 2. Before Loop initialization
 *     a)prev = dummy
 *     b)first = prev->next
 * 3.Loop:
 *      Loop Condition:
 *      first and first->next is not null
 *      Loop Body:
 *          second = first->next
 *          :Swap
 *          temp = second->next
 *          second->next = first
 *          first->next = temp
 *          prev->next = second
 *          :reinit
 *          prev = first
 *          first = prev->next
 * 4. head = dummy->next
 * 5. Free dummy
 */
void SLL::swapPairs(){
    Node *temp = new Node(0);
    Node *prev, *first, *second, *temp1;
    temp->next = head;
    prev = temp;
    first = prev->next;
    
    while(first && first->next){
        second = first->next;
        temp1 = second->next;
        second->next = first;
        first->next = temp1;
        prev->next = second;

        prev = first;
        first=first->next;
    }

    head = temp->next;
    delete temp;
}

int main()
{
    SLL sll(1);
    sll.append(2);
    sll.append(3);
    sll.append(4);
    sll.append(5);
    sll.append(6);
    
    sll.printList();
    sll.swapPairs();
    sll.printList();
   

    return 0;
}