#ifndef  QUEUE_CPP
#define QUEUE_CPP
#include "Queue.h"
#include <iostream>

template<class T>
Queue<T>::Queue() : list(new DLL::LinkedList<T>())  {}

template<class T>
bool Queue<T>::is_empty() const {
    return list->empty();
}

template<class T>
int Queue<T>::size() const {
    return list->size();
}

template<class T>
void Queue<T>::print() const {
    list->print();
}

template<class T>
void Queue<T>::enqueue(T value) {
    list->insert_back(value);
}
template<class T>
void Queue<T>::dequeue() {
    list->delete_front();
}

template<class T>
Queue<T>::~Queue() {
    delete this->list;
}



#endif
