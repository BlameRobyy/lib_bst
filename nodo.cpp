#include "nodo.h"



Node* Node::insertR(int k) {
    Node* root = this;
    if (root == NULL) {
        return new Node(k);
    }
    if (root->data == k) {
        root->count++;
        return root;
    }
    if (k < root->data) {
        root->lchild = root->lchild->insertR(k);
    } else {
        root->rchild = root->rchild->insertR(k);
    }
    return root;
}

bool Node::searchI (int k){
    Node* root = this;
    if (root == NULL) {
        return false;
    }
    bool check = false;
    if (root->data == k){
        check = true;
    } else if (root->data > k){
        root = root->lchild;
    } else {
        root = root->rchild;
    }

    while (!check && root!= NULL)
    if (root->data == k){
        check = true;
    } else if (root->data > k){
        root = root->lchild;
    } else {
        root = root->rchild;
    }
    
    return check;

}

bool Node::searchR(int k) {
    if (this->data == k) {   
        return true;   
    }

    if (k < this->data) {   
         
        return this->lchild != nullptr && this->lchild->searchR(k);
    } else {   
         
        return this->rchild != nullptr && this->rchild->searchR(k);
    }
}

void Node::inOrder() {
     if (lchild != nullptr) {
            lchild->inOrder();  
        }

        std::cout << data << " ";  

        if (rchild != nullptr) {
            rchild->inOrder();  
        }
    }

Node* Node::insertI(int k) {                                 
    Node* current = this;
    Node* dad{ nullptr };
    bool is_left;
    while (current != nullptr) {
        if (current->data == k) {
            current->count++;
            return this;
        }
        if (k < current->data) {
            dad = current;
            current = current->lchild;
            is_left = true;
        }
        else if (k > current->data) {
            dad = current;
            current = current->rchild;
            is_left = false;
        }
    }
    if (is_left) {
        dad->lchild = new Node(k);
    }
    else if (!is_left) {
        dad->rchild = new Node(k);
    }
    return this;
}

ostream& operator<<(ostream&os, Node& c){
    os << c.data << " " << c.count;
    return os;
}

istream& operator>>(istream&is, Node& c){
    is >> c.data >> c.count;
    return is;
}


void Node::preOrder() {
     cout << data << " ";

     if (lchild != nullptr) {
        lchild->preOrder();
    }

     if (rchild != nullptr) {
        rchild->preOrder();
    }
}

void Node::postOrder() {
     if (lchild != nullptr) {
        lchild->postOrder();
    }

     if (rchild != nullptr) {
        rchild->postOrder();
    }

     cout << data << " ";
}


bool Node::isBst()
{

    if(this->lchild != nullptr && this->lchild->data > this->data) {
        cout << "This is not a BST" << endl;
        return false;
    }
    if(this->rchild != nullptr && this->rchild->data < this->data) {
        cout << "This is not a BST" << endl;
        return false;
    }
    return this -> lchild -> isBst() && this -> rchild -> isBst();

}

Node* Node::deleteNode(int k) {
    if (k == this->data) {
        if (this->lchild == NULL && this->rchild == NULL) {
            delete this;
            return nullptr;
        } else if (this->lchild == NULL) {
            this->data = this->rchild->data;
            this->rchild = nullptr;
            delete this->rchild;
            return this;
        } else if (this->rchild == NULL) {
            this->data = this->lchild->data;
            this->lchild = nullptr;
            delete this->lchild;
            return this;
        }
    }
    if (k < this->data) {
        this->lchild = this->lchild->deleteNode(k);
    } else {
        this->rchild = this->rchild->deleteNode(k);
    }
    return this;
}