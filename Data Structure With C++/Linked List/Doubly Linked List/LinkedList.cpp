#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include "LinkedList.h"
//Handle operator overloading

namespace DLL {
    template<class T>
    LinkedList<T>::LinkedList() : head{}, tail{}, length(0) {
    }

    template<class T>
    void LinkedList<T>::print() const {
        for (Node<T> *node = head; node; std::cout << node->data << ' ', node = node->next);
    }

    template<class T>
    void LinkedList<T>::print_reverse() const {
        for (Node<T> *node = tail; node; std::cout << node->data << ' ', node = node->prev);
    }

    template<class T>
    void LinkedList<T>::print_list_format() const {
        if (!length) return std::cout << "<empty list>", void();
        for (Node<T> *node = head; node; node = node->next) {
            if (node == head)
                std::cout << "X\t<= [" << node->data << "]=>\t" << (node->next ? std::to_string(node->next->data) : "X")
                        << "\tHead";
            else if (node == tail)
                std::cout << node->prev->data << "\t<= [" << node->data << "]=>\tX\tTail";
            else
                std::cout << node->prev->data << "\t<= [" << node->data << "]=>\t" << (node->next
                    ? std::to_string(node->next->data)
                    : "");
            std::cout << std::endl;
        }
    }

    template<class T>
    void LinkedList<T>::link(Node<T> *first, Node<T> *second) {
        if (first)
            first->next = second;
        if (second)
            second->prev = first;
    }

    template<class T>
    void LinkedList<T>::insert_back(T val) {
        Node<T> *node = new Node<T>(val);
        length++;

        if (!head) {
            head = node;
            tail = head;
            head->prev = tail->prev = nullptr;
        } else {
            link(tail, node);
            tail = node;
        }
        tail->next = nullptr;
    }

    template<class T>
    void LinkedList<T>::insert_front(T val) {
        Node<T> *node = new Node<T>(val);
        length++;
        if (!head) {
            head = node;
            tail = head;
            tail->next = nullptr;
        } else {
            link(node, head);
            head = node;
        }
        head->prev = nullptr;
    }

    template<class T>
    void LinkedList<T>::embed_after(Node<T> *prev, int val) {
        if (!prev) return insert_front(val), void();
        Node<T> *item = new Node<T>(val), *next = prev->next;
        link(prev, item);
        link(item, next);
        length++;
    }

    template<class T>
    void LinkedList<T>::insert_sorted(T val) {
        if (!length || head->data >= val) return insert_front(val), void();
        if (tail->data <= val) return insert_back(val), void();
        for (Node<T> *node = head; node; node = node->next) {
            if (val <= node->data) {
                embed_after(node->prev, val);
                break;
            }
        }
    }

    template<class T>
    void LinkedList<T>::insert(T val, int index) {
        if (index < 0 || index > length) throw std::out_of_range("index out of range");
        if (index == length) return insert_back(val), void();
        int i = 0;
        for (Node<T> *node = head; node; node = node->next, ++i)
            if (i == index) return embed_after(node->prev, val);
    }

    template<class T>
    void LinkedList<T>::delete_node(Node<T> *node) {
        if (!length) return;
        Node<T> *tmp = node;

        if (node == head) {
            head = node->next;
            head->prev = nullptr;
        } else if (node == tail) {
            tail = node->prev;
            tail->next = nullptr;
        } else
            link(node->prev, node->next);

        delete tmp;
        length--;
        if (!length) tail = head = nullptr;
    }

    template<class T>
    void LinkedList<T>::delete_back() {
        delete_node(tail);
    }

    template<class T>
    void LinkedList<T>::delete_front() {
        delete_node(head);
    }

    template<class T>
    void LinkedList<T>::earse(int index) noexcept(false) {
        //0-based
        Node<T> *node = get_nth_node(index + 1);
        delete_node(node);
    }

    template<class T>
    Node<T> *LinkedList<T>::get_nth_node(int n) noexcept(false) {
        //1-based parameter
        if (n < 0 or n > length) throw std::out_of_range("n is out of range!");
        int i = 0;
        for (Node<T> *tmp = head; tmp; ++i, tmp = tmp->next)
            if (i == n - 1) return tmp;
        return nullptr;
    }

    template<class T>
    void LinkedList<T>::delete_first_val(int val) {
        if (!length) return;
        if (head->data == val) return delete_node(head), void();
        for (Node<T> *node = head; node; node = node->next) {
            if (node->data == val) {
                Node<T> *tmp = node->prev;
                delete_node(node);
                node = tmp;
                if (!node->next)
                    tail = node;
                break;
            }
        }
    }

    template<class T>
    void LinkedList<T>::delete_last_occ(int val) {
        if (!length) return;
        if (tail->data == val) return delete_node(tail), void();
        for (Node<T> *node = tail; node; node = node->prev) {
            if (node->data == val) {
                Node<T> *tmp = node->prev;
                delete_node(node);
                node = tmp;
                if (!node->prev)
                    head = node;
                break;
            }
        }
    }

    // To avoid memory leak
    template<class T>
    LinkedList<T>::~LinkedList() {
        //O(n) time , O(1) memory
        while (head) {
            Node<T> *current = head->next;
            std::cout << &head << ' ';
            delete head;
            head = current;
        }
    };

    template<class T>
    int LinkedList<T>::size() const {
        return this->length;
    }



    template<class T>
    void LinkedList<T>::delete_with_key(T val) {
        for(Node<T> * node = head ; node ;) {
            if(node->data == val) {
                Node<T> *tmp = node->next;
                delete_node(node);
                node = tmp;
            }else node = node->next ;
        }
    }


    template<class T>
    void LinkedList<T>::delete_even_position() {
        for(Node<T> *node = head ; node ;) {
            Node<T> *tmp = nullptr;
            if(node->next != nullptr) {
                tmp = node->next->next;
                delete_node(node->next);
                node = tmp;
            }else node = node->next;
        }
    }

    template<class T>
    void LinkedList<T>::delete_odd_position() {
        for(Node<T> *node = head->next ; node ;) {
            delete_node(node->prev);
            node = node->next;
            if(node == tail) {
                delete_back();
                break;
            }
            if(node)
                node=node->next;
            else
                break;
        }
    }

    template<class T>
    bool LinkedList<T>::is_palindrome_list() {

        for(Node<T> *front = head , *back = tail ; front && back ; front = front->next , back = back->prev) {
            if(front->data != back->data)
                return false;
        }

        return true;
    }


}

#endif
