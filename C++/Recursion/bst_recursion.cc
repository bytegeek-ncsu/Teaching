/*
* This code demonstrates BST with recursive implementation. It include BFS and DFS tree traversal.
*/

#include <iostream>
#include <queue>

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

    bool rLookup(int );
    bool rLookup(Node *, int);
    void rInsert(int );
    Node * rInsert(Node *, int );
    Node * removeNode(Node *, int);
    void removeNode(int);
    void BFS();
    void DFS_preorder(Node*);
    void DFS_preorder();
    void DFS_postorder(Node *);
    void DFS_postorder();
    void DFS_inorder(Node *);
    void DFS_inorder();
    void printTree(Node*);
    void print();
    int minValue(Node *);

};

bool BST::rLookup(int value){
    return rLookup(root, value);
}

bool BST::rLookup(Node *currentNode, int value){
    if (currentNode == nullptr) return false;
    if (value < currentNode->value)
       return rLookup(currentNode->left, value);
    else if(value > currentNode->value)
        return rLookup(currentNode->right, value);
    else{
        return true;
    }
}

void BST::rInsert(int value){
    if (root == nullptr){
        root = new Node(value);
    }
    rInsert(root, value);
}

Node * BST::rInsert(Node *currentNode, int value){
    Node *newNode = new Node(value);
    if(currentNode == nullptr)
        return newNode;
    if (value < currentNode->value)
        currentNode->left = rInsert(currentNode->left, value);
    else if(value > currentNode->value)
        currentNode->right = rInsert(currentNode->right, value);
    return currentNode;

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
    cout<<endl;
}

void BST::BFS(){
    queue<Node *> q;
    Node *temp;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        cout<<temp->value<<" ";
        if (temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        q.pop();
    }
    cout<<endl;
}

void BST::DFS_preorder(Node *temp){
    cout<<temp->value<<"  ";
    if(temp->left)
        DFS_preorder(temp->left);
    if(temp->right)
        DFS_preorder(temp->right);
}

void BST::DFS_preorder(){
    if (root == nullptr) return;
    DFS_preorder(root);
    cout<<endl;
}

void BST::DFS_postorder(Node *temp){
    if(temp->left)
        DFS_postorder(temp->left);
    if(temp->right)
        DFS_postorder(temp->right);
    cout<<temp->value<<"  ";

}

void BST::DFS_postorder(){
    if (root == nullptr) return;
    DFS_postorder(root);
    cout<<endl;
}

void BST::DFS_inorder(Node *temp){
    if(temp->left)
        DFS_inorder(temp->left);
    cout<<temp->value<<"  ";
    if(temp->right)
        DFS_inorder(temp->right);
}

void BST::DFS_inorder(){
    if (root == nullptr) return;
    DFS_inorder(root);
}

//Since we are finding minvalue we search 
//node-left till we hit the nullptr
int BST::minValue(Node *currentNode){
    while(currentNode->left != nullptr)
        currentNode = currentNode->left;
    return currentNode->value;
}

Node * BST::removeNode(Node *currentNode, int value){
    if (currentNode == nullptr) return nullptr;
    if(value < currentNode->value){
        currentNode->left = removeNode(currentNode->left, value);
    }else if(value > currentNode->value)
        currentNode->right = removeNode(currentNode->right, value);
    else{//This block value matches
        //use case 1: node to be removed is leaf node
        if(currentNode->left == nullptr && currentNode->right == nullptr){
            delete(currentNode);
            return nullptr;
        }else if (currentNode->right == nullptr){ //left subtree exists
            Node* temp = currentNode->left;
            delete(currentNode);
            return temp;
        }else if(currentNode->left == nullptr){ //right subtree exists
            Node *temp = currentNode->right;
            delete(currentNode);
            return temp;
        }else{ //both right and left subtree exists. Complex case. we approach minvalue in RST and replace with node that has deleted value.
            //Need MinValue function. We can approach the other way also find Max in LST. I will do this non-recursive BST code.
            int RSTMinValue = minValue(currentNode->right);
            currentNode->value = RSTMinValue;
            //Now two nodes has RSTMinValue. we need to delete the node exists in the RST.
            currentNode->right = removeNode(currentNode->right, RSTMinValue);
        }
    }

    return currentNode;
}
    

int main(){
    BST bst;
    bst.rInsert(17);
    bst.rInsert(12);
    bst.rInsert(5);
    bst.rInsert(15);
    bst.rInsert(28);
    bst.rInsert(20);
    bst.rInsert(32);

    bst.print();

    cout<<bst.rLookup(35)<<endl;
    cout<<bst.rLookup(28)<<endl;

    bst.rInsert(32);
    bst.print();
    bst.BFS();
    bst.DFS_preorder();
    bst.DFS_postorder();
    bst.DFS_inorder();

    

}