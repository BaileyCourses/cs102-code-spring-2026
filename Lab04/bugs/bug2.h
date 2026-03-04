#ifndef BUG2_H
#define BUG2_H

class List {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* _head;
    int _length;

public:
    List();
    ~List();

    void append(int value);
    void prepend(int value);
    int length() const;
    int get(int index) const;
};

#endif
