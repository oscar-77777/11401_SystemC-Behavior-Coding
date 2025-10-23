#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

// Base class Node
class Node {
protected:
    long* _Node; // Pointer to a long array

public:
    Node();
    Node(unsigned int _length);
    virtual ~Node();

    long* reCreate(unsigned int _length);
    long* getPtr();
    void setElement(unsigned int pos, long val);
    long getElement(unsigned int pos) const;
};

#endif
