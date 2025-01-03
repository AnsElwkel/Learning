#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<bits/stdc++.h>
using namespace std;

/** Probing (Open Addressing , Closed Hashing)
- Open addressing is a method of collision resolution in hash tables.
- In open addressing, when a new obj is inserted, the hash table is searched for the next available slot.
- The search starts from the slot where the obj should be placed.
- If the slot is empty, the obj is placed in the slot.
- If the slot is occupied, the search continues to the next slot.
- The search continues until an empty slot is found.

- Using a circular array to represent the hash table.

Intsertion : (We insert in empty slot or in the slot of the deleted obj)
    Start from idx where idx = initial_hash % size
    while table[idx] is not empty
        idx = (idx + 1) % size
    table[idx] = obj

Searching:
    Start from idx where idx = initial_hash % size
    while table[idx] is not empty and table[idx] != obj
        idx = (idx + 1) % size
    if table[idx] == obj
        return idx
    return -1

Deletion:
    Start from idx where idx = initial_hash % size
    while table[idx] is not empty and table[idx] != obj
        idx = (idx + 1) % size
    if table[idx] == obj
        table[idx] = -1 (or any value to indicate that the slot is deleted X)

Rehashing:
- When the load factor exceeds a certain threshold, the hash table is rehashed.
- Rehashing is the process of creating a new hash table with a larger size.
- The keys in the old hash table are reinserted into the new hash table.
- The size of the new hash table is usually twice the size of the old hash table.
- In probing , when the array has many deleted keys, we should rehash the table to avoid the clustering problem.


i -> 0, 1, 2, 3 ,...
- Linear Probing : idx = (initial_hash + i) % size
- Quadratic Probing : idx = (initial_hash + i*i) % size
- Double Hashing : idx = (initial_hash1 + initial_hash2*i) % size
                   where initial_hash1 = hash1(obj) % size
                    and initial_hash2 should should have several characteristics
*/

//T -> object type
template<typename T>
class HashTable{
    int size , probing_type;
    vector<T*> table;
    T* deleted;
    int nextIdx(int initial_hash , int i) const;
public:
    //probing_type : 0 -> Linear Probing , 1 -> Quadratic Probing , 2 -> Double Hashing
    HashTable(int size , int probing_type = 0 , T* deleted = NULL);
    bool insert(T obj , int hashCode); // true if inserted , false if the table is full
    bool insert(T obj); // true if inserted , false if the table is full

    bool remove(T obj , int hashCode);
    bool remove(T obj);

    bool get(T& obj , int hashCode) const;
    bool get(T& obj) const;

    void printTable() const;
    void printTablePrimitive() const;

    ~HashTable();
};

#include "HashTable.cpp"

#endif // HASHTABLE_H