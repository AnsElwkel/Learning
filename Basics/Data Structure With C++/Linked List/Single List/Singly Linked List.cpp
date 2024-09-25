/**
* Singly Linked List: insert and delete ->O(1) , access -> O(n)
*     Sequence of nodes , where each node contain data and link to the next node
      creating a dynamic connected chain values
      First node called "head" and the last node called tail
*/
#include<iostream>

class Node {
public:
      int data;
      Node *next;

      Node(int data) : data(data), next(nullptr) {
      }
};

class LinkedList {
      Node *head{}, *tail{};
      int len{};

public:
      void print() {
            for (Node *tmp = head; tmp; tmp = tmp->next)
                  std::cout << tmp->data << ' ';
            std::cout << std::endl;
      }

      int size() {
            return len;
      }

      void insert_end(int val) {
            Node *item = new Node(val);
            len++;
            if (!head)
                  head = tail = item;
            else {
                  tail->next = item;
                  tail = tail->next;
            }
      }

      int get_nth(int n) {
            if (n < 0 or n > len) throw std::out_of_range("n is out of range!");
            int i = 0;
            for (Node *tmp = head; tmp; ++i, tmp = tmp->next)
                  if (i == n - 1) return tmp->data;
      }

      int search(int val) {
            int idx = 0;
            for (Node *tmp = head; tmp; tmp = tmp->next, ++idx)
                  if (tmp->data == val) return idx;

            return -1; //Not found
      }

      int improved_search(int val) {// each find shift the element to left
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

      ~LinkedList() {
      };
};

int main() {
      LinkedList lst;
      lst.insert_end(5);
      lst.insert_end(10);
      lst.insert_end(15);
      lst.insert_end(20);
      lst.print();
      std::cout << lst.size() << std::endl;
      std::cout << lst.get_nth(2) << std::endl;
      std::cout << lst.search(15) << std::endl;
      std::cout << lst.improved_search(15) << std::endl;
}
