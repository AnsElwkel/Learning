#include "Node.h"
Node::Node(int val) : data(val){}
Node::~Node() {
    std::cout << "Destructor Node: " << data << " at address " << this << std::endl; // Optionally to trace
}