#ifndef VECTOR_H
#define VECTOR_H
/**
 *ADT -> Abstract Data Type
 *Operator Overloading [] for get,set
 *Operator Overloading << for print
 *handle more exceptions
 */
#include <iostream>
using namespace std;
class Vector {
private:
    int size {0}, capacity {} , MAX = 1e8;
    int* arr{nullptr};
    void expand();
public:
    Vector(int size);
    void push_back(int val) noexcept(true);
    void pop_back() noexcept(false);
    int find(int val) const noexcept(true);
    void set(int val , int index) noexcept(false);
    int get(int index) const noexcept(false);
    int front() const noexcept(false);
    int back() const noexcept(false);
    void print() const noexcept(true);
    void insert(int index , int val);
    int Size() const;
    ~Vector() ;
    //Homework
    void rightRotate(int count) noexcept(true);
    void leftRotate(int count) noexcept(true);
    int pop(int index);
};



#endif //VECTOR_H
