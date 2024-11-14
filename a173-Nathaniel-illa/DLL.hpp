#ifndef DLL_HPP
#define DLL_HPP

#include "DLLNode.hpp"
// DLL class template definition
template <class T>
class DLL {
private:
    DLLNode<T>* head;      // Pointer to the head of the list
    DLLNode<T>* tail;      // Pointer to the tail of the list

public:
    // Constructor to initialize an empty list
    DLL() : head(nullptr), tail(nullptr) {}

    // Destructor to free all nodes in the list
    ~DLL() {
        while (!isEmpty()) {
            deleteNode(head->getData());
        }
    }

    // Get the head node pointer
    DLLNode<T>* getHead() const { return head; }

    // Get the tail node pointer
    DLLNode<T>* getTail() const { return tail; }

    // Check if the list is empty
    int isEmpty() const { return head == nullptr; }

    // Add a new node with given value to the tail of the list
    void addtoTail(T el) {
        DLLNode<T>* newNode = new DLLNode<T>(el);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->setNext(newNode);
            newNode->setPrev(tail);
            tail = newNode;
        }
    }

    // Delete the first occurrence of a node with the given value
    void deleteNode(T el) {
        if (isEmpty()) return; // No nodes to delete

        DLLNode<T>* current = head;

        // Find the node with the given value
        while (current != nullptr && current->getData() != el) {
            current = current->getNext();
        }

        if (current == nullptr) return; // Node not found

        // Update pointers
        if (current == head) {
            head = head->getNext();
            if (head != nullptr) head->setPrev(nullptr);
            else tail = nullptr; // List is now empty
        } else if (current == tail) {
            tail = tail->getPrev();
            if (tail != nullptr) tail->setNext(nullptr);
            else head = nullptr; // List is now empty
        } else {
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
        }

        delete current; // Free the memory of the deleted node
    }
};
#endif

