#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<assert.h>
#include<sstream>
#include<string>
//Node structure for Singly Linked List (SLL)
class Node {
public:
    int data;
    Node *next;

    Node(int val);

    ~Node();
};


#endif //NODE_H
