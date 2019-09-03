// Header file for the class Node
#pragma once

template<class T>
class Node {
	T element;  // Represents the content of a node
	Node<T>* next;   // Represents a pointer to the next node

public:
	Node(): element(NULL), next(NULL) {};   // Default constructor
	Node(T item, Node<T>* next) : element(item), next(next) {}; // Constructor which assigns certain data to the Node object
	Node(const Node<T>& copy) : element(copy.element), next(copy.next ? new Node<T>(*copy.next) : NULL) {} ; // Copy constructor
	~Node() {}; // Destructor

	// Setters
	void setElement(T item) { element = item; };
	void setNext(Node<T>* item) { next = item; }
	// Getters
	T getElement() { return element; };
	Node<T> *getNext() { return next; };
};