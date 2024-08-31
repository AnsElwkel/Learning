#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;


    Node(int data) : data(data), next(nullptr) {
    }
};

void printNodes(Node *node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void printNodes1(Node *node) { // Using for loop
    for(; node != nullptr; node = node->next) {
        cout << node->data << " ";
    }
    cout << endl;
}

void printNode2(Node *node) {
    if (node == nullptr) return;

    cout << node->data << " ";
    printNode2(node->next);
}

void printNode_reverse(Node *node) {
    if (node == nullptr) return;

    printNode_reverse(node->next);
    cout << node->data << ' ';
}

Node* find(int val , Node *node) {
    for(; node != nullptr; node = node->next)
        if(node->data == val) return node;
    return nullptr;
}

int main(){
    Node *node1 = new Node(0);
    Node *node2 = new Node(4);
    Node *node3 = new Node(10);
    Node *node4 = new Node(15);
    Node *node5 = new Node(23);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    cout << node1->data << " " << node2->data << " " << node3->data << ' ' << node4->data << " " << node5->data << endl;
    cout << node1->next->data << endl; // node2 4
    cout << node1->next->next->next->next->data << endl; // node5 23
    cout << node2->next->next->next->data << endl; // node5 23
    cout << node3->next->next->data << endl; // node5 23
    cout << node4->next->data << endl; // node5 23
    cout << node5->data << endl; // node5 23

    printNodes(node1);
    printNodes1(node1);
    printNode2(node1);
    cout << endl;
    printNode_reverse(node1);
    cout << endl;

    cout << find(23, node1)->data << endl;
    cout << find(14, node1)->data << endl; //Undefined behaviour
}