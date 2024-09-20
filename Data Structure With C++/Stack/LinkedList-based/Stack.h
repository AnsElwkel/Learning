#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"

/** FILO Data Structure
* First In Last Out
*/
template<class T>
class Stack {
public:
    void push(int val); //O(1)

    T pop();//O(1)

    bool is_empty() const;//O(1)

    T peek();//O(1)

    void print() const;//O(n)

private:

    Node<T> *head{nullptr};
};

#include "Stack.cpp"


#endif //STACK_H
