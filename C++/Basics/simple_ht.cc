/**
 * This class demonstrates simple hash table implementation
 */
#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
        string key;
        int value;
        Node *next;

        Node(string key, int value){
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};
class HT{
private:
    static const int SIZE = 13; //We normally choose HT size as prime numbers. So that keys will be distributed randomly
    Node *dataMap[SIZE]{nullptr};

public:
    int hash(string);
    void set(string, int);
    int get(string);
    void printTable();


};

int HT::hash(string key){
    int hash = 0;
    for (int i=0; i<key.length(); i++){
        int asciivalue = int(key[i]);
        hash = (hash+asciivalue * 17) % SIZE;
    }

    return hash;
}

void HT::set(string key, int value){
    int index = hash(key);
    Node* newNode = new Node(key, value);
    if (dataMap[index] == nullptr){
        dataMap[index] = newNode;
        return;
    }

    Node *temp = dataMap[index];
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
    

}

int HT::get(string key){
    int index = hash(key);
    Node *temp = dataMap[index];
    while(temp){
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }

    return 0; //couldn't find the given key.
}

void HT::printTable(){
    for (int i=0; i < SIZE; i++){
        cout<<"Index :"<<i<<" ";
        Node *temp = dataMap[i];
        while(temp){
            cout<<temp->key<<":"<<temp->value<<", ";
            temp = temp->next;
        }
        cout<<endl;
    

    }
}

int main(){

    HT ht;
    ht.printTable();
}