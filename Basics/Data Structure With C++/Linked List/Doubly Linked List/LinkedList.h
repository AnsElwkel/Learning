#ifndef DLL_LINKEDLIST_H
#define DLL_LINKEDLIST_H
#include "Node.h"
/**
 *Doubly Linked List -> access in previous tail in O(1)
 *                   -> each node support next and prev
 *                   -> little more space than SLL
 **/
namespace DLL {
    template<class T>
    class LinkedList {
        Node<T> *head , *tail;
        int length;
        const int MAX_SIZE = 10000001;

    public:
        LinkedList();

        void print() const;

        void print_reverse() const;

        void print_list_format() const;

        int size() const;

        void link(Node<T>* first , Node<T>* second);

        void insert_front(T val);

        void insert_back(T val);

        void insert_sorted(T val);

        void insert(T val, int index);

        void delete_node(Node<T>* node);

        Node<T>* get_nth_node(int n) noexcept(false);

        void embed_after(Node<T>* prev , int val);

        void earse(int index);

        void delete_front();

        void delete_back();

        void delete_first_val(int val);

        void delete_last_occ(int val);

        void delete_with_key(T val);

        void delete_even_position();

        void delete_odd_position();

        bool is_palindrome_list();

        ~LinkedList();
    };

}
#include "LinkedList.cpp"

#endif //DLL_LINKEDLIST_H
