#include <iostream>
using namespace std;

struct node{
    int data;
    int dupl;
    node* lchild, *rchild;

    node(int key){
        data=key;
        lchild=nullptr;
        rchild=nullptr;
        dupl=1;
    }
};

bool search(node* root, int key){
    if(root == nullptr){
        return false;
    }
    if(root ->data == key){
        return true;
    }

    if(key < root->data){
        return search(root->lchild, key);
    } else {
        return search(root -> rchild, key);
    }
}

node* inserisci(node* radice, int val) {
    node* dad{nullptr};    
    node* current{radice}; 
    bool is_left{false};   

    while (current != nullptr) {
        if (val == current->data) {
            current->dupl++;
            return radice; 
        }
        dad = current; 

        if (val < current->data) {
            current = current->lchild;
            is_left = true;
        }
        else {
            current = current->rchild;
            is_left = false;
        }
    }

    node* nuovo = new node(val);  

    if (dad == nullptr) {
        return nuovo;
    }

    if (is_left) {
        dad->lchild = nuovo;
    } else {
        dad->rchild = nuovo;
    }

    return radice;
}

node* insert(node* root, int key){
    if (root == nullptr) {
        return new node(key);
    }

    if (root->data == key) {
        root->dupl++; 
    } else if (key < root->data) {

        root->lchild = insert(root->lchild, key);
    } else {
        root->rchild = insert(root->rchild, key);
    }
    return root; 
};

node* cancellaFoglia(node* radice, int key) {
    if (radice == nullptr) {
        return nullptr; 
    }

    if (key < radice->data) {
        radice->lchild = cancellaFoglia(radice->lchild, key);
    }
    else if (key > radice->data) {
        radice->rchild = cancellaFoglia(radice->rchild, key);
    }
    else {
        if (radice->lchild == nullptr && radice->rchild == nullptr) {
            delete radice; 
            return nullptr; 
        }
    }

    return radice;
}

void visitaInOrder(node* radice) {
    if (radice != nullptr) {
        visitaInOrder(radice->lchild); 
        cout << radice->data << " (dup: " << radice->dupl << ") "; 
        visitaInOrder(radice->rchild); 
    }
}

void visitaPreOrder(node* radice) {
    if (radice != nullptr) {
        cout << radice->data << " (dup: " << radice->dupl << ") "; 
        visitaPreOrder(radice->lchild); 
        visitaPreOrder(radice->rchild); 
    }
}

void visitaPostOrder(node* radice) {
    if (radice != nullptr) {
        visitaPostOrder(radice->lchild); 
        visitaPostOrder(radice->rchild); 
        cout << radice->data << " (dup: " << radice->dupl << ") "; 
    }
}

bool verificaBST(node* radice, int min, int max) {
    if (radice == nullptr) {
        return true;
    }

    if (radice->data <= min || radice->data >= max) {
        return false;
    }

    return verificaBST(radice->lchild, min, radice->data) &&  
           verificaBST(radice->rchild, radice->data, max);   
}
