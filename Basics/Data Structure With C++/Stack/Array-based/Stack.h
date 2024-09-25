#ifndef STACK_H
#define STACK_H
//Stack array based

#include <iostream>
#include <stdexcept>
template<class T>
class Stack {
public:
    explicit Stack(int size); //O(n) memory and time

    Stack(const Stack<T> &other) = delete;

    Stack(Stack<T> &&other) = delete;

    Stack<T> &operator=(const Stack<T> &other) = delete;

    Stack<T> &operator=(Stack<T> &&other) = delete;

    T get_top() const; //O(1)

    int get_size() const; //O(1)

    void push(T val); //O(1)

    int pop(); //O(1)

    bool is_empty() const; //O(1)

    bool is_full() const; //O(1)

    void print() const noexcept; //O(n) time

    ~Stack(); //O(n) time

private:
    int top{};
    int size{};
    T *arr;
};

#include "Stack.cpp"

#endif //STACK_H
