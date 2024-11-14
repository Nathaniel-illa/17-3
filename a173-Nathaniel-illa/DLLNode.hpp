#ifndef DLLNODE_HPP
#define DLLNODE_HPP
// DLLNode class template definition
template <class T>
class DLLNode {
private:
    T data;                        // Data stored in the node
    DLLNode<T>* prev;              // Pointer to the previous node
    DLLNode<T>* next;              // Pointer to the next node

public:
    // Default constructor
    DLLNode() : prev(nullptr), next(nullptr) {}

    // Constructor with data
    DLLNode(T el) : data(el), prev(nullptr), next(nullptr) {}

    // Constructor with data, previous and next pointers
    DLLNode(T el, DLLNode<T>* p, DLLNode<T>* n) : data(el), prev(p), next(n) {}

    // Get the data stored in the node
    T getData() const { return data; }

    // Get the previous node pointer
    DLLNode<T>* getPrev() const { return prev; }

    // Get the next node pointer
    DLLNode<T>* getNext() const { return next; }

    // Set the previous node pointer
    void setPrev(DLLNode<T>* p) { prev = p; }

    // Set the next node pointer
    void setNext(DLLNode<T>* n) { next = n; }
};

#endif