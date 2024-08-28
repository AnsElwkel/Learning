/**
* Singly Linked List: insert and delete ->O(1) , access -> O(n)
*     Sequence of nodes , where each node contain data and link to the next node
      creating a dynamic connected chain values
      First node called "head" and the last node called tail
*/
#include <iostream>
class Node {
public:
      int data;
      Node *next;
      Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
      Node* head{ };
      Node* tail{ };
      int len{ };
public:
      void print() {
            Node* tmp = head;
            for(; tmp!=nullptr;tmp=tmp->next)
                  std::cout << tmp->data << ' ';
            std::cout << std::endl;
      }
      int size() {
            return len;
      }
      void insert_end(int val) {
            Node* item = new Node(val);
            len++;
            if(!head)
                  head = tail = item;
            else {
                  tail->next = item;
                  tail = tail->next;
            }
      }

      ~LinkedList(){};
};

int main(){
      LinkedList lst;
      lst.insert_end(5);
      lst.insert_end(10);
      lst.insert_end(15);
      lst.insert_end(20);
      lst.print();
      std::cout << lst.size();
}
