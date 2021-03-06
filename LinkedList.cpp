// LinkedList class functions

#include "pch.h"
#include <iostream>
#include "LinkedList.h"
using namespace std;

// Prints the elements of the list
template<class T>
ostream& operator<<(ostream& output, const LinkedList<T>& list)
{
	Node<T>*p = list.head; // Copy of head

	// Sends each element to the extraction operator until the tail is reached. The output is then returned
	for (p; p != NULL; p = p->getNext()) {
		output << p->getElement() << " ";
	}
	return output;
}

// Copy constructor
template<class T>
LinkedList<T>::LinkedList(const LinkedList& copy) {
	head = NULL;  // Sets head of copy to null initially
	Node<T>* curr = copy.head;  // Current node used for copying
	Node<T>* tail = NULL; // Tail of copied linked list

	// While the copy of the head pointer is not null, copies the nodes to the new linked list
	while (curr)
	{
		Node<T>* copy = new Node<T>();  // Copy node for assigning elements of the linked list nodes
		copy->setElement(curr->getElement()); // Sets the data for each node

		// Assigns the head of the copied linked list initially, then assigns the tail for every new copied node
		if (!head) {
			head = copy;
			tail = head;
		}
		else {
			tail->setNext(copy);
			tail = copy;
		}

		curr = curr->getNext(); // Repeat for the next node in the linked list
	}
}

// Adds an element to the end of the list
template<class T>
void LinkedList<T>::add(T item) {
	Node<T>* new_node = new Node<T>(item, NULL);  // Node to be added

	// If the linked list is empty, set the new node to head. Otherwise set the new node to the end of the linked list
	if (tail == NULL)
	{
		head = new_node;
	}
	else
	{
		tail->setNext(new_node);
	}
	tail = new_node; // Assigns the tail address to the new node
}

// Removes an element from the list
template<class T>
void LinkedList<T>::remove(T item) {
	Node<T>* curr = head; // Start the current node in search at the head of the linked list
	Node<T>* prev = NULL; // Previous node in linked list

	try {
		if (head == NULL)  // Return exception for empty linked list
			throw "Linked list is empty";

		// While the tail is not reached in the loop. Search for the item entered
		while (curr != NULL)
		{
			// If the item is found, remove said item from the linked list
			if (curr->getElement() == item)
			{
				// Sets new head if the item is located at the head
				// Otherwise removes the item from the linked list
				if (prev == NULL)
					head = curr->getNext();
				else
					prev->setNext(curr->getNext());
				curr = curr->getNext();
				return;
			}
			// If the item is not found, continue to search through the list
			else
			{
				prev = curr;
				curr = curr->getNext();
			}
		}
		throw item; // Throws exception if item is not found
	}
	catch (char* str) {
		cout << "Exeption occurred: " << str << endl;
	}
	catch (T) {
		cout << "Exception occurred: Item entered is not in the list" << endl;
	}
}

// Removes an element from a certain position
template<class T>
void LinkedList<T>::remove_pos(int index) {
	Node<T>* curr = head; // Current node
	Node<T>* prev = NULL; // Previous node

	// Moves the curr pointer to the index entered
	// Sets the previous pointer to the position before the index
	for (int i = 1; i < index && curr != NULL; ++i) {
		prev = curr;            
		curr = curr->getNext();
	}
	// If the index entered is not located in the list, return message
	if (curr == NULL) {
		cout << "Position not found" << endl;
		return;
	}
	// If the index entered is zero, remove the head
	else if (prev == NULL) {
		head = curr->getNext();
	}
	// If the position is not located at the head, remove the node from the linked list
	else {
		prev->setNext(curr->getNext());
	}
	if (tail == curr) // Updates the tail if required
		tail = prev; 
	delete curr;
}

// Inserts an element at a certain position
template<class T>
void LinkedList<T>::insert(T item, int pos) {
	Node<T>* prev = NULL; // Previous node
	Node<T>* curr = head; // Current node, starts at head
	Node<T>* new_node = new Node<T>(item, NULL); // Node to be inserted
	
	int index = 0;
	if (head != NULL)
	{
		while (curr->getNext() != NULL && index != pos) // Searches for the position to insert the new node
		{
			prev = curr;
			curr = curr->getNext();
			index++;
		}
		if (pos == 0) // Adds the node at head
		{
			new_node->setNext(head);
			head = new_node;
		}
		else if (curr->getNext() == NULL && pos == index + 1) // Adds the node at the tail
		{
			this->add(item);
		}
		else if (pos > index + 1) {  // If the position exceeds the size of the linked list, throw exception
			cout << "Position is out of bounds" << endl;
		}
		else  // Add node at the corresponding position
		{
			prev->setNext(new_node);
			new_node->setNext(curr);
		}
	}
}

// Returns the value of an element at a certain position
template<class T>
T LinkedList<T>::return_element(int pos) const {
	Node<T>* curr = head; // Start search at head 
	int index = 0;
	
	// Searches for the element
	while (curr != NULL) {
		if (index == pos) // If the node is found, return the element
			return curr->getElement();
		index++;
		curr = curr->getNext();
	}

	return NULL; // If not found, return 0
}

// Searches for an element in the linked list
template<class T>
bool LinkedList<T>::search(T item) {  
	Node<T>*curr = head; // Starts the search at head

	while (curr != NULL && curr->getElement() != item) // Searches for the element
	{
		curr = curr->getNext();
	}
	if (curr != NULL) { // If the element is found, return true
		return true;
	}
	else { // If the element is not found, return false
		return false;
	}
}
