#ifndef TREENODE_CPP
#define TREENODE_CPP

#include <iostream>
using namespace std;

template <class T>
class TreeNode{
    public :
    T data;
    TreeNode<T> * left , *right;
    int height;

    TreeNode(T data) : data(data) , left(nullptr) , right(nullptr) , height(0) {}

    ~TreeNode(){
        delete left;
        delete right;
    }
};

#endif // TREENODE_CPP