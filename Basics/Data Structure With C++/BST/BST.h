#ifndef BST_H
#define BST_H
#include <iostream>
#include <vector>

template<class T>
class BST {
public:
    BST();
    explicit BST(T data);

    BST(std::vector<T> &array , int start , int end);

    void insert(T val);

    void remove(T val);

    bool search(T val);

    bool search_iterative(T val);

    void print_inorder();

    bool is_BST();

    T find_kth_smallest(int &k); // Important idea


    void clear();

    T max();

    T min();

    T LCA(T x , T y);


    BST<T> &search_tree(T val);

    bool find_chain(std::vector<BST *> &ancestors, T target);

    BST<T> *get_next(std::vector<BST<T> *> &ancestors);

    std::pair<bool, T> successor(T target);

    ~BST();

private:
    T data;
    BST<T> *left, *right;
};

#include "BST.cpp"


#endif //BST_H
