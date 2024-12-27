#include "AVL_Tree.h"

void test(){
    AVL_Tree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    tree.insert(35);
    tree.insert(45);
    tree.insert(55);
    tree.print();
    tree.delete_node(10);
    tree.print();
}