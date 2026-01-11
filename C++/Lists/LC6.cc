/**
 * Implement the partitionList member function for the LinkedList class, 
 * which partitions the list such that all nodes with values less than x come
 * before nodes with values greater than or equal to x.
 * Note:  This linked list class does NOT have a tail which will make this method easier to implement.
 * The original relative order of the nodes should be preserved.
 * Function Signature:
 * void partitionList(int x)
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

int main()
{
    SLL sll(3);
    sll.append(8);
    sll.append(5);
    sll.append(10);
    sll.append(2);
    sll.append(1);
       
    sll.printList();
    sll.partitionList(5);
    sll.printList();
   

    return 0;
}
