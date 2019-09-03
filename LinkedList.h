// Header file for the class LinkedList

#pragma once
#include "Node.h"
#include <iostream>
#include <iomanip>
using namespace std;

template<class T>
class LinkedList {

	template<class T>
	friend ostream& operator<<(ostream&, const LinkedList<T>&);  // Prints the elements of the list

private:
	Node<T> *head, *tail;                         // Node pointers to head and tail

public:
	LinkedList() : head(0), tail(NULL) {};  // Default constructor
	LinkedList(const LinkedList<T>&);             // Copy constructor
	~LinkedList() {delete head; delete tail;}  // Destructor

	void add(T item);                        // Adds an element to the end of the list
	void remove(T item);                     // Removes an element from the list (throws an exception if not in list)
	void remove_pos(int pos);                // Removes an element from a certain position
	void insert(T item, int pos);            // Inserts an element at a certain position
	T return_element(int pos) const;       // Returns the value of an element at a certain position
	bool search(T item);                     // Searches for an element in the linked list
};