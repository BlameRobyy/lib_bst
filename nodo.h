
#include <iostream>
using namespace std;


class Node {
    private:
        int data;
        int count;
        Node* lchild;
        Node* rchild;
    public:
        Node(int k)
            : data{k}, count{1}, lchild{nullptr}, rchild{nullptr} {};
        Node* insertR(int k);
        Node* insertI(int k);
        void inOrder();
        void preOrder();
        void postOrder();
        bool searchI (int k);
        bool searchR (int k);
        Node* deleteNode(int k);
        bool isBst();


    friend ostream& operator <<(ostream&os, Node& c);


    friend istream& operator >>(istream&os, Node& c);

};

