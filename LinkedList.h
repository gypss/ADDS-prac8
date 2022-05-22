#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"


class LinkedList {
public:
	Node * head;

	LinkedList();
	LinkedList(int arr[], int arrSize);

	

	void addFront(int newItem);// The function inserts a new node, containing the newItem, at the beginning of the list.

	
	void addEnd(int newItem); // The function inserts a new node, containing the newItem, at the end of the list.

	
	void addAtPosition(int position, int newItem);
	
	int search(int item); 

	
	void deleteFront();


	void deleteEnd();


	void deletePosition(int position);

	int getItem(int position);


	void printItems(); 

	~LinkedList(); //A destructor that manually deletes all the elements that are still in the list.
};

#endif