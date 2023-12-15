#include <stdio.h>
#include <stdlib.h>

class Node{
public:    
    int value;
    Node * left;
    Node * right;
    Node(int value);
    ~Node();
    void insert(int value);
    Node* search(int value);
};

int main(){
    Node * root = NULL;
    root = new Node(10);
    
    root->insert(4);
    root->insert(1);
    root->insert(12);
    root->insert(8);

    Node* nodeWithValue = root->search(5);

    if(nodeWithValue) printf("Node no endereco:%p tem o valor %d\n", nodeWithValue ,nodeWithValue->value);
    else printf("O valor não existe na arvore.\n");

    nodeWithValue = root->search(4);

    if(nodeWithValue) printf("Node no endereco:%p tem o valor %d\n", nodeWithValue ,nodeWithValue->value);
    else printf("O valor não existe na arvore.\n");

    return 0;
}

Node::Node(int value){
    this->value = value;
    this->left = NULL;
    this->right = NULL;
}

void Node::insert(int value){    
    if (value < this->value)
        if (this->left) this->left->insert(value);
        else this->left = (Node*)new Node(value);
    else 
        if (this->right) this->right->insert(value);
        else this->right = (Node*)new Node(value);
}

Node* Node::search(int value){
    if (this->value == value) return this;

    if (value < this->value)
        if(this->left) return this->left->search(value);
    else 
        if(this->right) return this->right->search(value);
    
    return NULL;
}

Node::~Node()
{
    delete left;
    delete right;
}