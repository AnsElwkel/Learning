#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"


template<class T>
Stack<T>::Stack(int size) : size(size), top(-1) {
    arr = new T[size];
}

template<class T>
T Stack<T>::get_top() const {
    if (is_empty())
        throw std::out_of_range("Stack is empty");
    return arr[top];
}

template<class T>
int Stack<T>::get_size() const {
    return size;
}

template<class T>
void Stack<T>::push(T val) {
    if (is_full())
        throw std::out_of_range("Stack is full");
    arr[++top] = val;
}

template<class T>
int Stack<T>::pop() {
    if (is_empty())
        throw std::out_of_range("Stack is empty");
    return arr[top--];
}

template<class T>
bool Stack<T>::is_empty() const {
    return top == -1;
}

template<class T>
bool Stack<T>::is_full() const {
    return top == size - 1; // 0 - based
}

template<class T>
void Stack<T>::print() const noexcept {
    for (int i = top; ~i; i--)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template<class T>
Stack<T>::~Stack() {
    delete[] arr;
}

#endif