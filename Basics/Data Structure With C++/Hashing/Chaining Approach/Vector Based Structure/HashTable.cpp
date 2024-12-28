#ifndef HashTable_CPP
#define HashTable_CPP
#include "HashTable.h"

template<class T>
HashTable<T>::HashTable(int size): size(size), table(vector<vector<T>>(size)) {}

template<class T>
void HashTable<T>::insert(T val , int hashCode){
    int index = hashCode % size;
    for(auto &x : table[index]){
        if(x == val){ // for any non primitive object we need to overload the == operator !!
            x = val; // exist so update only
            return;
        }
    }

    table[index].push_back(val);
}   

template<class T>
void HashTable<T>::insert(T val){
    int index = val.hash() % size; // for any non primitive object we need to make the hash function in its class !!
    for(auto &x : table[index]){
        if(x == val){
            x = val; // exist so update only
            return;
        }
    }
    table[index].push_back(val);
}   


template<class T>
bool HashTable<T>::remove(T val , int hashCode){
    int index = hashCode % size;
    for(int i = 0 ; i < (int)table[index].size() ;i++){
        if(table[index][i] == val){
            // Instead of deleting the element in O(n) we can swap it with the last element and pop the last element in O(1) !!
            swap(table[index].back() , table[index][i]);
            table[index].pop_back();
            return true;
        }
    }

    return false;
}


template<class T>
bool HashTable<T>::remove(T val){
    int index = val.hash() % size;
    for(int i = 0 ; i < (int)table[index].size() ;i++){
        if(table[index][i] == val){
            // Instead of deleting the element in O(n) we can swap it with the last element and pop the last element in O(1) !!
            swap(table[index].back() , table[index][i]);
            table[index].pop_back();
            return true;
        }
    }

    return false;
}

template<class T>
bool HashTable<T>::get(T& val , int hashCode) const{
    int index = hashCode % size;
    for(auto x : table[index]){
        if(x == val){ // for any non primitive object we need to overload the == operator !!
            val = x;
            return true;
        }
    }
    return false;
}


template<class T>
bool HashTable<T>::get(T& val) const{
    int index = val.hash() % size; // for any non primitive object we need to make the hash function in its class !!
    for(auto x : table[index]){
        if(x == val){ // for any non primitive object we need to overload the == operator !!
            val = x;
            return true;
        }
    }
    return false;
}

template<class T>
void HashTable<T>::printTable() const {
    for(int i = 0 ; i < size ; i++){
        if(table[i].empty()) continue;
        cout <<"Hash " << i << " : ";
        for(auto x : table[i]){
            cout << x.toString() << " "; // for any non primitive object we need to make the toString function in its class !!
        }
        cout << '\n';
    }
}

template<class T>
void HashTable<T>::printTablePrimitive() const{
    for(int i = 0 ; i < size ; i++){
        if(table[i].empty()) continue;
        cout <<"Hash " <<i << " : ";
        for(auto x : table[i]){
            cout << x << " ";
        }
        cout << '\n';
    }
}

#endif // HashTable_CPP