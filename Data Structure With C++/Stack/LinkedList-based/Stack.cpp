#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.h"

template<class T>
void Stack<T>::push(int val) {
    Node<T>* node = new Node(val);
    node->next = head;
    head = node;
}


template<class T>
T Stack<T>::pop() {
    if(is_empty()) throw std::out_of_range("Stack is empty");
    Node<T>* temp = head;
    head = head->next;
    return temp->data;
}

template<class T>
bool Stack<T>::is_empty() const {
    return head == nullptr;
}

template<class T>
T Stack<T>::peek() {
    if(is_empty())
        throw std::out_of_range("Stack is empty");
    return head->data;
}

template<class T>
void Stack<T>::print() const {
    if(this->is_empty())
        throw std::out_of_range("Stack is empty");
    for(Node<T>* node = head ; node ; node = node->next) {
        std::cout << node->data << ' ' ;
    }
}

#endif