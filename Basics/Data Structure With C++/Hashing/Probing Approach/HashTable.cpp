#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include "HashTable.h"

template<typename T>
HashTable<T>::HashTable(int size , int probing_type , T* deleted)
:size(size) , deleted(!deleted ? new T() : deleted) , probing_type(probing_type){
     table.resize(size);
}

template<typename T>
int HashTable<T>::nextIdx(int initial_hash , int i) const{
    return (probing_type == 0 ? (initial_hash + i) % size : probing_type == 1 ? (initial_hash + i*i) % size : (initial_hash + i* (1 + (initial_hash % (size - 1))) ) % size);
}


template<typename T>
bool HashTable<T>::insert(T obj , int hashCode){
    int init_idx , idx;
    init_idx = idx = hashCode  % size;

    for(int step = 1; step <= size ; ++step){
        if(table[idx] == deleted || !table[idx]){
            table[idx] = new T(obj); // shoulb be implement the copy constructor
            return true;
        }else if (*table[idx] == obj){ // should be implement the == operator
            *table[idx] = obj; // update the value
            return true;
        }

        idx = nextIdx(init_idx , step);
    }

    return false ; // table is full
}

template<typename T> 
bool HashTable<T>::insert(T obj){
    int init_idx , idx;
    init_idx = idx = obj.hash()  % size;

    for(int step = 1; step <= size ; ++step){
        if(table[idx] == deleted || !table[idx]){
            table[idx] = new T(obj); // shoulb be implement the copy constructor
            return true;
        }else if (*table[idx] == obj){ // should be implement the == operator
            *table[idx] = obj; // update the value
            return true;
        }

        idx = nextIdx(init_idx , step);
    }

    return false ; // table is full
}

template<typename T>
bool HashTable<T>::remove(T obj , int hashCode){
    int init_idx , idx;
    init_idx = idx = hashCode  % size;

    for(int step = 1; step <= size ; ++step){
        if(!table[idx])
            break;

        if(table[idx] != deleted && *table[idx] == obj){ // should be implement the == operator
            table[idx] = deleted;
            return true;
        }

        idx = nextIdx(init_idx , step);
    }
    return false;
}

template<typename T>
bool HashTable<T>::remove(T obj){
    int init_idx , idx;
    init_idx = idx = obj.hash()  % size;

    for(int step = 1; step <= size ; ++step){
        if(!table[idx])
            break;

        if(table[idx] != deleted && *table[idx] == obj){ // should be implement the == operator
            table[idx] = deleted;
            return true;
        }

        idx = nextIdx(init_idx , step);
    }
    return false;
}

template<typename T>
bool HashTable<T>::get(T& obj , int hashCode) const{
    int init_idx , idx;
    init_idx = idx = hashCode  % size;

    for(int step = 1; step <= size ; ++step){
        if(!table[idx])
            break;

        if(table[idx] != deleted && *table[idx] == obj){ // should be implement the == operator
            obj = *table[idx]; // update the value // should be implement the = operator
            return true;
        }

        idx = nextIdx(idx , step);
    }
    return false;
}

template<typename T>
bool HashTable<T>::get(T& obj) const{
    int init_idx , idx;
    init_idx = idx = obj.hash()  % size;

    for(int step = 1; step <= size ; ++step){
        if(!table[idx])
            break;

        if(table[idx] != deleted && *table[idx] == obj){ // should be implement the == operator
            obj = *table[idx]; // update the value // should be implement the = operator
            return true;
        }

        idx = nextIdx(init_idx , step);
    }
    return false;
}

template<typename T>
void HashTable<T>::printTable() const{
    cout << "======= Hash Table =======\n";
    for(int i = 0; i < size; i++){
        cout << "Hash " << i << " : ";
        if(table[i] == deleted)
            cout << " Deleted " ;
        else if(!table[i])
            cout << " Empty ";
        else 
            cout << table[i]->toString(); // implement the toString function
        cout << '\n';
    }
    cout << "==========================\n";
}

template<typename T>
void HashTable<T>::printTablePrimitive() const{
    cout << "======= Hash Table =======\n";
    for(int i = 0; i < size; i++){
        cout << "Hash " << i << " : ";
        if(table[i] == deleted)
            cout << " Deleted " ;
        else if(!table[i])
            cout << " Empty ";
        else 
            cout << *table[i] ; // implement the toString function
        cout << '\n';
    }
    cout << "==========================\n";
}



template<typename T>
HashTable<T>::~HashTable(){
    for(int i = 0; i < size; i++)
        if(table[i] != deleted)
            delete table[i];
    delete deleted;
}

#endif // HASHTABLE_CPP