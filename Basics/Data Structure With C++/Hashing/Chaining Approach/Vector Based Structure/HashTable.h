#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class HashTable{
    int size;
    vector<vector<T>> table;

    public :
        HashTable(int size);

    void insert(T val , int hashCode);
    void insert(T val);
    bool remove(T val , int hashCode); // true if the value is removed , false if not found
    bool remove(T val);
    bool search(T val , int hashCode); // true if the value is found , false if not found
    bool search(T val);

    bool get(T& val , int hashCode) const; // update the argument with the value if found and return true , false if not found
    bool get(T& val) const;

    void printTable() const;
    void printTablePrimitive() const;
};
#include "HashTable.cpp"
#endif // HASHTABLE_H