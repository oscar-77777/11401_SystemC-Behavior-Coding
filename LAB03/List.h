#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List : public Node {
private:
    unsigned int length;

public:
    List();
    List(unsigned int _length);
    List(const List& other);
    ~List();
    List& operator=(const List& other);

    int setLength(unsigned int _length);
    unsigned int getLength() const;
    int setElement(unsigned int pos, long val);
    long getElement(unsigned int pos) const;

    List operator+(const List& other) const;
    List& operator+=(const List& other);
    List operator++();
    List operator++(int);
    List operator--();
    List operator--(int);

    friend ostream& operator<<(ostream& os, const List& lst);
    friend istream& operator>>(istream& is, List& lst);
};

#endif
