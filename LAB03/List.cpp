#include "List.h"
#include <iomanip>

List::List() : Node() {
    length = 0;
}

List::List(unsigned int _length) : Node(_length) {
    length = _length;
}

List::List(const List& other) : Node(other.length) {
    length = other.length;
    for (unsigned int i = 0; i < length; ++i)
        _Node[i] = other._Node[i];
}

List::~List() {
    length = 0;
}

List& List::operator=(const List& other) {
    if (this != &other) {
        if (length != other.length) {
            delete[] _Node;
            _Node = new long[other.length];
        }
        length = other.length;
        for (unsigned int i = 0; i < length; ++i)
            _Node[i] = other._Node[i];
    }
    return *this;
}

int List::setLength(unsigned int _length) {
    if (length == 0) {
        reCreate(_length);
        length = _length;
        return 1;
    } else {
        cout << "Error: length already set.\n";
        return 0;
    }
}

unsigned int List::getLength() const {
    return length;
}

int List::setElement(unsigned int pos, long val) {
    if (pos < length) {
        _Node[pos] = val;
        return 1;
    } else {
        cout << "Error: invalid position.\n";
        return 0;
    }
}

long List::getElement(unsigned int pos) const {
    if (pos < length)
        return _Node[pos];
    cout << "Error: invalid position.\n";
    return -99999;
}

List List::operator+(const List& other) const {
    unsigned int newLen = (length < other.length) ? length : other.length;
    List result(newLen);
    for (unsigned int i = 0; i < newLen; ++i)
        result._Node[i] = _Node[i] + other._Node[i];
    return result;
}

List& List::operator+=(const List& other) {
    unsigned int newLen = (length < other.length) ? length : other.length;
    for (unsigned int i = 0; i < newLen; ++i)
        _Node[i] += other._Node[i];
    return *this;
}

List List::operator++() {
    for (unsigned int i = 0; i < length; ++i)
        ++_Node[i];
    return *this;
}

List List::operator++(int) {
    List temp(*this);
    for (unsigned int i = 0; i < length; ++i)
        ++_Node[i];
    return temp;
}

List List::operator--() {
    for (unsigned int i = 0; i < length; ++i)
        --_Node[i];
    return *this;
}

List List::operator--(int) {
    List temp(*this);
    for (unsigned int i = 0; i < length; ++i)
        --_Node[i];
    return temp;
}

ostream& operator<<(ostream& os, const List& lst) {
    os << "List(length=" << lst.length << "): ";
    for (unsigned int i = 0; i < lst.length; ++i)
        os << lst._Node[i] << " ";
    os << endl;
    return os;
}

istream& operator>>(istream& is, List& lst) {
    unsigned int len;
    is >> len;
    lst.setLength(len);
    for (unsigned int i = 0; i < len; ++i)
        is >> lst._Node[i];
    return is;
}
