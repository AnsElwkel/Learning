#ifndef SINGLELINKEDLIST_STRUCTURE_H
#define SINGLELINKEDLIST_STRUCTURE_H
#include "Node.h"
#include<iostream>
#include<assert.h>
#include<sstream>
#include<string>
#include<vector>
#include <climits>
/**
* Singly Linked List (SLL) : insert back or front and delete back or front -> O(1) , access -> O(n)
*     Sequence of nodes , where each node contain data and link to the next node
      creating a dynamic connected chain values
      First node called "head" and the last node called tail

    we gain flexibility in memory growth (no need for vector reallocations)
*/
namespace SLL {
    class LinkedList {
        Node *head{}, *tail{};
        int length{};
        const int MAX_SIZE = 100001;

    public:
        LinkedList();

        LinkedList(const LinkedList &other) = delete;

        LinkedList &operator=(const LinkedList &other) = delete;

        void print();

        void print_list_format();

        int size();

        void insert_end(int val);

        void insert_front(int val);

        void insert(int val, int idx);

        void delete_front();

        void delete_back();

        void erase(int idx);

        int get_nth(int n);

        Node *get_nth_node(int n);

        int get_nth_back(int n);

        Node *get_nth_back_node(int n);

        int search(int val);

        int improved_search(int val);

        bool is_same_list(const LinkedList &other);

        void debug();

        std::string debug_to_string();

        ~LinkedList();

        //addition
        void print_without_tail_and_length();

        void add_without_tail_and_length(int val);

        int get_tail();

        void delete_first_val(int val);

        void swap_pairs();

        void reverse();

        void delete_next(Node *node);

        void delete_even_positions();

        Node *max_node();

        Node *min_node();

        void insert_sorted(int val);

        int max(Node *head = nullptr, bool first = true);

        void swap_head_tail();

        void left_rotate(int cnt);

        void unique_unsorted();

        void remove_last_occurrence(int val);

        void move_all_val_to_end(int val);
    };

    void testLinkedList_structure();
} // SLL

#endif //SINGLELINKEDLIST_STRUCTURE_H
