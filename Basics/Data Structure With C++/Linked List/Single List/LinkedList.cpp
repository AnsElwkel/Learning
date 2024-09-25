#include "LinkedList.h"

//modular code skill -> if there is logic want to handle in function and there is function you created handle this logic .. Use the function
namespace SLL {
    LinkedList::LinkedList() {
    }

    //Printing all data with sequence format
    void LinkedList::print() {
        //O(n)
        for (Node *tmp = head; tmp; tmp = tmp->next)
            std::cout << tmp->data << ' ';
        std::cout << std::endl;
    }

    //Printing all data with Linked format
    void LinkedList::print_list_format() {
        //O(n)
        int cnt = 0;
        for (Node *node = head, *prv = nullptr; ; prv = node, node = node->next) {
            if (!node) {
                if (prv)
                    std::cout << prv->data << " -> X Tail" << std::endl;
                else
                    std::cout << "Empty !" << std::endl;
                break;
            }

            if (!prv)continue;
            std::cout << prv->data << " -> " << node->data;
            if (++cnt == 1) std::cout << " Head";
            std::cout << std::endl;
        }
    }

    //Return number of nodes in linked list
    int LinkedList::size() {
        //O(1)
        return length;
    }

    //Add new element in the end of linked list
    void LinkedList::insert_end(int val) {
        //O(1)
        Node *item = new Node(val);
        length++;
        if (!head)
            head = tail = item;
        else {
            tail->next = item;
            tail = tail->next;
            tail->next = nullptr;
        }
    }

    void LinkedList::insert_front(int val) {
        //O(1)
        Node *item = new Node(val), *tmp = head;
        length++;
        if (!head)
            head = tail = item;
        else {
            head = item;
            head->next = tmp;
        }
    }

    void LinkedList::insert(int val, int idx) noexcept(false) {
        if (idx > length || idx < 0) throw std::out_of_range("Index is out of range");
        if (idx == length) return insert_end(val), void();
        if (!idx) return insert_front(val), void();
        Node *item = new Node(val), *prv = get_nth_node(idx), *next = prv->next;
        prv->next = item;
        item->next = next;
        ++length;
    }

    void LinkedList::delete_front() noexcept(false) {
        if (!head) throw std::out_of_range("Empty list");
        Node *tmp = head;
        head = head->next;
        delete tmp;
        if (!head) tail = nullptr;
        --length;
    }

    void LinkedList::delete_back() {
        if (length <= 1) return delete_front(), void();
        Node *prv = get_nth_back_node(2);
        delete tail;
        tail = prv;
        tail->next = nullptr;
        --length;
    }

    void LinkedList::erase(int idx) noexcept(false) {
        if (idx >= length || idx < 0) throw std::out_of_range("Index out of range");
        if (idx == 0) return delete_front(), void();
        if (idx == length - 1) return delete_back(), void();
        Node *prv = get_nth_node(idx), *tmp = get_nth_node(idx + 1);
        prv->next = tmp->next;
        delete tmp;
        length--;
    }

    //Return value of n-th node in linked list
    int LinkedList::get_nth(int n) {
        //O(n)
        if (n < 0 or n > length) throw std::out_of_range("n is out of range!");
        int i = 0;
        for (Node *tmp = head; tmp; ++i, tmp = tmp->next)
            if (i == n - 1) return tmp->data;
    }

    Node *LinkedList::get_nth_node(int n) noexcept(false) {
        if (n < 0 or n > length) throw std::out_of_range("n is out of range!");
        int i = 0;
        for (Node *tmp = head; tmp; ++i, tmp = tmp->next)
            if (i == n - 1) return tmp;
        return nullptr;
    }

    int LinkedList::get_nth_back(int n) {
        if (length < n) throw std::out_of_range("n is out of range!");
        int idx = length - n, i = 0;
        for (Node *node = head; node; node = node->next, ++i)
            if (i == idx) return node->data;
        return -1;
    }

    Node *LinkedList::get_nth_back_node(int n) {
        if (length < n)
            return nullptr;
        int idx = length - n, i = 0;
        for (Node *node = head; node; node = node->next, ++i)
            if (i == idx) return node;
        return nullptr;
    }

    //Return in the index of first node contain val
    int LinkedList::search(int val) {
        //O(n)
        int idx = 0;
        for (Node *tmp = head; tmp; tmp = tmp->next, ++idx)
            if (tmp->data == val) return idx;

        return -1; //Not found
    }

    //A little bit efficient search that each find shift the element to left
    int LinkedList::improved_search(int val) {
        //O(n)
        int idx = 0;
        for (Node *tmp = head, *prv = nullptr; tmp; prv = tmp, tmp = tmp->next) {
            if (tmp->data == val) {
                if (!prv) return idx;
                std::swap(prv->data, tmp->data);
                return idx - 1;
            }
            ++idx;
        }

        return -1;
    }

    bool LinkedList::is_same_list(const LinkedList &other) {
        bool same = true;
        Node *tmp1 = head, *tmp2 = other.head;
        if (!tmp1 || !tmp2 || length != other.length) same = false;
        for (; tmp1 and tmp2 and same; tmp1 = tmp1->next, tmp2 = tmp2->next)
            if (tmp1->data != tmp2->data) same = false;
        return same;
    }

    void LinkedList::debug() {
        if (!length) {
            assert(!head);
            assert(!tail);
        } else {
            assert(head);
            assert(tail);
            if (length == 1)
                assert(head == tail);
            else
                assert(head != tail);
            assert(!tail->next);
        }
        int len = 0;
        for (Node *node = head; node; node = node->next, ++len)
            assert(len < MAX_SIZE); // Consider infinite cycle
        assert(len == length);
        // assert(len == (int)debug_data.size());
    }

    std::string LinkedList::debug_to_string() {
        if (length == 0)
            return "";
        std::ostringstream oss;
        for (Node *node = head; node; node = node->next) {
            oss << node->data;
            if (node->next)
                oss << ' ';
        }
        return oss.str();
    }

    // To avoid memory leal
    LinkedList::~LinkedList() {
        //O(n) time , O(1) memory
        while (head) {
            Node *current = head->next;
            std::cout << &head << ' ';
            delete head;
            head = current;
        }
    };

    void LinkedList::print_without_tail_and_length() {
        for (Node *node = head; node; node = node->next)
            std::cout << node->data << ' ';
        std::cout << std::endl;
    }

    void LinkedList::add_without_tail_and_length(int val) {
        //O(n) or implement in reversed order -> O(1)
        length++;
        for (Node *node = head, *prv = nullptr; ; prv = node, node = node->next) {
            if (!node) {
                node = new Node(val);
                if (prv)
                    prv->next = node;
                else
                    head = node;
                break;
            }
        }
    }

    int LinkedList::get_tail() {
        if (!head) throw std::out_of_range("Empty list");

        Node *tmp = head;
        for (; tmp->next; tmp = tmp->next);
        return tmp->data;
    }

    void LinkedList::delete_first_val(int val) {
        for (Node *node = head, *prv = nullptr; node; prv = node, node = node->next) {
            if (node->data == val) {
                if (!prv)
                    return delete_front(), void();

                delete_next(prv);
                break;
            }
        }
    }

    void LinkedList::swap_pairs() {
        int i = 0;
        for (Node *node = head; node; node = node->next, ++i) {
            if (!(i & 1) and node->next) std::swap(node->data, node->next->data);
        }
    }

    void LinkedList::reverse() {
        if (length <= 1) return;
        tail = head;
        Node *prev = head, *next = nullptr;
        head = head->next;
        while (head) {
            next = head->next;
            head->next = prev;

            prev = head;
            head = next;
        }
        head = prev;
        tail->next = nullptr;
    }

    void LinkedList::delete_next(Node *node) {
        if (!node || !node->next) return;
        Node *tmp = node->next;
        node->next = tmp->next;
        delete tmp;
        --length;
    }

    void LinkedList::delete_even_positions() {
        if (length <= 1) return;
        for (Node *node = head->next, *prv = head; node;) {
            delete_next(prv);
            if (!prv->next) break;
            prv = prv->next;
            node = prv->next;
        }
    }

    Node *LinkedList::max_node() {
        Node *node = head;
        for (Node *tmp = node; tmp; tmp = tmp->next) {
            if (tmp->data >= node->data)
                node = tmp;
        }

        return node;
    }

    Node *LinkedList::min_node() {
        Node *node = head;
        for (Node *tmp = node; tmp; tmp = tmp->next) {
            if (tmp->data < node->data)
                node = tmp;
        }
        return node;
    }

    void LinkedList::insert_sorted(int val) {
        if (!length || tail->data <= val) return insert_end(val), void();
        if (val <= head->data) return insert_front(val), void();
        for (Node *node = head, *prv = nullptr; node; prv = node, node = node->next) {
            if (val <= node->data) {
                Node *tmp = new Node(val);
                tmp->next = node;
                prv->next = tmp;
                ++length;
                break;
            }
        }
    }

    void LinkedList::swap_head_tail() {
        if (length <= 1) return;
        Node *tmp1 = get_nth_node(length - 1);
        tail->next = head->next;
        tmp1->next = head;
        head->next = nullptr;
        std::swap(head, tail);
    }

    void LinkedList::left_rotate(int cnt) {
        if (cnt <= 0 || length <= 1 || cnt % length == 0) return;
        cnt %= length;
        while (cnt--) {
            Node *tmp = head->next;
            tail->next = head;
            tail = tail->next;
            tail->next = nullptr;
            head = tmp;
        }
    }

    void LinkedList::unique_unsorted() {
        if (length <= 1) return;
        for (Node *node = head; node; node = node->next) {
            for (Node *tmp = node->next, *prv = node; tmp;) {
                if (tmp->data == node->data) {
                    delete_next(prv);
                    tmp = prv->next;
                } else prv = tmp, tmp = tmp->next;
            }
        }
    }

    void LinkedList::remove_last_occurrence(int val) {
        if (!length) return;
        reverse();
        delete_first_val(val);
        reverse();
    }

    void LinkedList::move_all_val_to_end(int val) {
        if (length <= 1) return;
        int len = length;
        for (Node *node = head, *prv = nullptr; len--;) {
            if (node->data == val) {
                Node *tmp = node->next;
                if (prv)
                    delete_next(prv);
                else delete_front();

                insert_end(val);
                node = tmp;
            } else prv = node, node = node->next;
        }
    }

    int LinkedList::max(Node *head, bool first) {
        if (first) return max(this->head, false);

        if (!head) return INT_MIN;

        return std::max(head->data, max(head->next, first));
    }


    void testLinkedList_structure() {
        //To check structure work well or not
        LinkedList lst;
        lst.insert_front(100);

        lst.insert_end(10);
        lst.insert_end(20);
        lst.insert_end(30);
        lst.insert_end(40);

        lst.debug();
        std::string excepcted = "100 10 20 30 40", result = lst.debug_to_string();
        if (excepcted != result) {
            std::cout << "No match:\nExcepcted: " << excepcted << "\nResult: " << result << std::endl;
            assert(false);
        }
        std::cout << "Linked List Format:" << std::endl;
        lst.print_list_format();
        std::cout << "**************" << std::endl;
        std::cout << "No RTE , Testing is Done!" << std::endl;
    }
} // SLL :)
