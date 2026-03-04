#include "bug2.h"
#include <stdexcept>

List::List() {
    _head = nullptr;
    // BUG: _length is never initialized
}

List::~List() {
    Node* current = _head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void List::append(int value) {
    Node* newNode = new Node{value, nullptr};
    if (_head == nullptr) {
        _head = newNode;
    } else {
        Node* current = _head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    // BUG: forgot to increment _length
}

void List::prepend(int value) {
    Node* newNode = new Node{value, _head};
    _head = newNode;
    _length++;
}

int List::length() const {
    return _length;
}

int List::get(int index) const {
    if (index < 0 || index >= _length) {
        throw std::out_of_range("Index out of bounds");
    }
    Node* current = _head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}
