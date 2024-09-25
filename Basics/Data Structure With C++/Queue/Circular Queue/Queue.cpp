#ifndef QUEUE_CPPP
#define QUEUE_CPPP

#include <stdexcept>
#include "Queue.h"
#include <iostream>

template<class T>
Queue<T>::Queue(int size) : size(size), arr(new T[size]), added_element(0), back(0), front(0) {
}

template<class T>
int Queue<T>::next(int pos) const {
    if (pos + 1 == size) pos = 0;
    else ++pos;
    return pos;
}

template<class T>
int Queue<T>::size_() const {
    return added_element;
}

template<class T>
bool Queue<T>::is_empty() const {
    return added_element == 0;
}

template<class T>
bool Queue<T>::is_full() const {
    return added_element == size;
}

template<class T>
void Queue<T>::enqueue(T item) {
    if (is_full())
        throw std::out_of_range("Queue is full");
    ++added_element;
    arr[back] = item;
    back = next(back);
}

template<class T>
T Queue<T>::dequeue() {
    if (is_empty())
        throw std::out_of_range("Queue is full");
    --added_element;
    T item = arr[front];
    arr[front] = 0;
    front = next(front);
    return item;
}

template<class T>
void Queue<T>::print() const {
    if(is_empty())
        return std::cout << "Empty Queue" << std::endl , void();
    for(int i = front , cnt = 0; cnt < added_element ; cnt++) {
        std::cout << arr[i] << ' ';
        i = next(i);
        if(i == front)
            break;
    }
}

template<class T>
Queue<T>::~Queue() {
    delete [] arr;
}


#endif
