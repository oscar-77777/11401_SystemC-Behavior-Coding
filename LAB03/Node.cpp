#include "Node.h"

Node::Node() {
    _Node = nullptr;
}

Node::Node(unsigned int _length) {
    _Node = new long[_length];
}

Node::~Node() {
    delete[] _Node;
    _Node = nullptr;
}

long* Node::reCreate(unsigned int _length) {
    delete[] _Node;
    _Node = new long[_length];
    return _Node;
}

long* Node::getPtr() {
    return _Node;
}

void Node::setElement(unsigned int pos, long val) {
    _Node[pos] = val;
}

long Node::getElement(unsigned int pos) const {
    return _Node[pos];
}
