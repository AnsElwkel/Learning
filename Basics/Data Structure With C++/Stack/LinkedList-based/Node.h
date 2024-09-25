#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
  public:
    T data{};
    Node *next{};
    Node(T data) : data(data), next(nullptr) {}
};


#endif //NODE_H
