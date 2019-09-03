// Driver which tests the Node and LinkedList classes

#include "pch.h"
#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
using namespace std;

int main() {
	LinkedList<int> L;
	L.add(50);		  // Testing add function
	L.add(60);        // Testing add function
	L.add(45);        // Testing add function
	L.add(56);        // Testing add function
	cout << L << endl;// Testing overloaded extraction operator
	L.remove(60);     // Testing remove function
	L.remove(123);    // Testing exception for remove function
	L.remove_pos(0);  // Testing deletion at head
	L.remove_pos(1);  // Testing deletion
	cout << L << endl;
	L.insert(77, 0);  // Testing insertion at head
	L.insert(33, 1);  // Testing insertion within linked list
	L.insert(99, 3);  // Testing insertion at tail
	cout << L << endl;
	cout << L.return_element(1) << endl;  // Testing return function
	cout << L.return_element(9) << endl;  // Testing return function out of bounds
	L.insert(33, 7);  // Testing insertion out of bounds
	L.remove_pos(8);  // Testing deletion out of bounds (not working)
	cout << L << endl;

	if (L.search(50)) // Testing search function
		cout << "Found!" << endl;
	else
		cout << "Not Found!" << endl;

	if (L.search(99)) // Testing search function
		cout << "Found!" << endl;
	else
		cout << "Not Found!" << endl;

	LinkedList<int> L_copy(L); // Testing copy constructor
	cout << L_copy << endl;
	cout << L_copy.return_element(1) << endl;
	
	return 0;
}