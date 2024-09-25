#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <ostream>

template<class T>
//Node of DLL
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data);

    void set(T* next , T* prev);

    ~Node();
};

#include "Node.cpp"

#endif //NODE_H
