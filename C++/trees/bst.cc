/**
 * This code demonstrates basic binary tree operation
 */

#include <iostream>

using namespace std;

class Node{
public:
    int value;
    Node* left;
    Node* right;

    Node(int value):value(value), left(nullptr), right(nullptr){}

};

class BST{
public:
    Node* root;

    BST(){
        root = nullptr;
    }

    bool lookup(int value);
    bool insert(int value);
    bool remove(int value);
    void printTree(Node*);
    void print();

};

bool BST::lookup(int value){
    Node* temp = root;
    while(temp){
        if(value < temp->value)
            temp = temp->left;
        else if(value > temp->value)
            temp = temp->right;
        else{
            return true;
        }
    }

    return false;
    
}

bool BST::insert(int value){
    Node *newNode = new Node(value);
    if (root == nullptr){
        root = newNode;
        return true;
    }
    Node* temp = root;
    while(true){
        if (value < temp->value){
            if(temp->left == nullptr){
                temp->left = newNode;
                return true;
            }
            temp = temp->left;
        }else if (value > temp->value){
            if(temp->right == nullptr){
                temp->right = newNode;
                return true;
            }
            temp = temp->right;
        }
        else{
            return false;
        }
    }

}

void BST::printTree(Node* temp){
    if (temp->left != nullptr)
       printTree(temp->left);
    cout<<temp->value<<", ";
    if(temp->right != nullptr)
       printTree(temp->right);
    
}

void BST:: print(){
    if (!root) return;
    printTree(root);
}

int main(){
    BST bst;
    bst.insert(7);
    bst.insert(12);
    bst.insert(5);
    bst.insert(15);
    bst.insert(28);
    bst.insert(20);
    bst.insert(32);

    bst.print();

    return 0;
}