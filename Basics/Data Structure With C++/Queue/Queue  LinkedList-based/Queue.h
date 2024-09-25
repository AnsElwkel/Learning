#ifndef QUEUE_H
#define QUEUE_H
#include "/home/anaselwkel/CLionProjects/untitled2/DLL/LinkedList.h"
template<class T>
class Queue {
public:
    Queue();

    int size() const;

    bool is_empty() const;

    void enqueue(T value);

    void dequeue();

    void print() const;

    ~Queue();

private:
    DLL::LinkedList<T> *list;
};

#include "Queue.cpp"

#endif //QUEUE_H
