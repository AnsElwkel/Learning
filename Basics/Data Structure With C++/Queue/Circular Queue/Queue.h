#ifndef QUEUE_H
#define QUEUE_H
/** FIFO Data structure
 * First In First out
 * */

template<class T>
class Queue {
public:
    explicit Queue(int size); //O(n)

    bool is_empty() const; // O(1)

    bool is_full() const; // O(1)

    void enqueue(T item); // O(1)

    T dequeue(); // O(1)

    int next(int pos) const; //O(1)

    int size_() const; // O(1)

    void print() const; // O(n)

    ~Queue(); // O(n)

private:
    int size, added_element, *arr, front, back;
};


#include "Queue.cpp"

#endif //QUEUE_H
