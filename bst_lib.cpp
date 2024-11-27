#include "nodo.h"
#include <iostream>
using namespace std;


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

void Node::inOrder() {
    Node* root = this;
    if (root == NULL) {
        return;
    }
    root->lchild->inOrder();
    cout<< root->data;
    root->rchild->inOrder();
}