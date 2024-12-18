#ifndef BST_H
#define BST_H
#include <iostream>
#include <vector>
//sub tree style
template<class T>
class BST {
public:
    BST();
    explicit BST(T data);

    BST(std::vector<T> &array , int start , int end);

    void insert(T val);

    BST<T> *min_node();

    void remove(T val);

    BST<T> *delete_node(T val, BST<T> *node);

    void special_delete(BST<T> *child);

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
