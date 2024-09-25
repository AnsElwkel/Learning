#ifndef NODE_CPP
#define NODE_CPP
#include "Node.h"

template<class T>
Node<T>::Node(T data) : data(data) {}

template<class T>
void Node<T>::set(T *next, T *prev) {
    next(next) , prev(prev);
}

template<class T>
Node<T>::~Node() {
    std::cout << "Destructor of node" << this << " and its data-> " << this->data << std::endl;
}

#endif
