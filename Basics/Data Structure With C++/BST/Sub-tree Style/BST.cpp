#ifndef BST_CPP
#define BST_CPP
#include <float.h>
#include "BST.h"

template<class T>
BST<T>::BST(T data) : data(data), left(nullptr), right(nullptr) {
}

template<class T>
BST<T>::BST() {
}

template<class T>
bool BST<T>::search(T val) {
    if (this->data == val)
        return true;
    if (this->data < val)
        return right && right->search(val);
    return left && left->search(val);
}

template<class T>
T BST<T>::find_kth_smallest(int &k) { // Partial traversal with counter parameter
    if(!k) return -1234;
    if(left) {
        int res = left->find_kth_smallest(k);
        if(!k) return res; //founded
    }

    --k;
    if(!k)
        return data;
    if(right)
        return right->find_kth_smallest(k);

    return -1234;
}

template<class T>
BST<T> &BST<T>::search_tree(T val) {
    if (this->data == val)
        return this;
    if (this->data < val)
        return right and right->search(val);
    return left and left->search(val);
}
template<class T>
bool BST<T>::find_chain(std::vector<BST<T>*>& ancestors , T target) {
    ancestors.push_back(this);

    if(data == target)
        return true;

    if(data > target)
        return left && left->find_chain(ancestors, target);

    return right && right->find_chain(ancestors, target);
}

template<class T>
BST<T>* BST<T>::get_next(std::vector<BST<T>*> &ancestors) {
    if(ancestors.empty())
        return nullptr;
    BST<T>* node = ancestors.back();
    ancestors.pop_back();
    return node;
}

template<class T>
std::pair<bool , T > BST<T>::successor(T target) {
    std::vector<BST<T>*> ancestors;

    if(!find_chain(ancestors , target)) {
        std::cout << "Chain not founded" ;
        return {false , 0};
    }

    BST<T>*  child = get_next(ancestors);
    if(child->right)
        return {true , child->right->min()};

    BST<T>* parent = get_next(ancestors);
    while(parent && parent->right == child)
        child = parent , parent = get_next(ancestors);

    if(parent)
        return {true , parent->data};

    return {false , 0};
}

template<class T>
T BST<T>::LCA(T x , T y) {
    if(x < this->data && y < this->data)
        this->left->LCA(x , y);
    if(x > this->data && y > this->data)
        this->right->LCA(x , y);
    return this->data;
}

template<class T>
bool BST<T>::is_BST() {
    bool left_bst = !left || left->data  < this->data && left->is_BST(),
         right_bst = !right || right->data > this->data && right->is_BST();
    return left_bst && right_bst ;
}

template<class T>
bool BST<T>::search_iterative(T val) {
    BST<T> *current = this;
    while (current) {
        if (current->data == val)
            return true;
        if (current->data < val)
            current = current->right;
        else
            current = current->left;
    }

    return false;
}

template<class T>
void BST<T>::insert(T val) {
    if (val > this->data) {
        if (right)
            right->insert(val);
        else
            right = new BST<T>(val);
    }
    if (val < this->data) {
        if (left)
            left->insert(val);
        else
            left = new BST<T>(val);
    }
}

template<class T>
BST<T>* BST<T>::min_node() {
    BST<T> *node = this;
    while(node && node->left)
        node = node->left;
    return node;
}

template<class T>
void BST<T>::remove(T val) {
    // if(data == val && !left && !right)
    // return ; // can't delete root
    delete_node(val , this);
}

template<class T>
BST<T>* BST<T>::delete_node(T val , BST<T>* node) {
    if(!node)
        return nullptr;

    if(node->data > val)
        node->left = delete_node(val, node->left);
    else if(node->data < val)
        node->right = delete_node(val, node->right);
    else { // reach target

        BST<T>* tmp = node;
        if(!node->left && !node->right) {
            node = nullptr;
            delete tmp;
        }
        else if(!node->right)
            node->special_delete(node->left);
        else if(!node->left)
            node->special_delete(node->right);
        else {
            BST<T>* mn = node->right->min_node();
            node->data = mn->data; // copy data and go to delete the successor
            node->right = delete_node(node->data , node->right);
        }
    }
    return node;
}

template<class T>
void BST<T>::special_delete(BST<T>* child) { // virtual delete to be able to handle case that if target is root
    data = child->data;
    left = child->left;
    right = child->right;
    delete child;
}


template<class T>
void BST<T>::print_inorder() {
    if (left)
        left->print_inorder();
    std::cout << data << ' ';
    if (right)
        right->print_inorder();
}

template<class T>
void BST<T>::clear() {
    if (left) {
        delete left;
        left = nullptr;
    }
    if (right) {
        delete right;
        right = nullptr;
    }
}

template<class T>
T BST<T>::max() {
    if (!right)
        return data;
    return right->max();
}

template<class T>
T BST<T>::min() {
    if (!left)
        return data;
    return left->min();
}

template<class T>
BST<T>::~BST() {
    clear();
}


#endif
