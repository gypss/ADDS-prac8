#include "LinkedList.h"
#include <iostream>
#include <limits>
using namespace std;

LinkedList::LinkedList() {
	head = NULL;		//A constructor with no parameters, which makes an empty list.
}

LinkedList::LinkedList(int arr[], int arrSize) {//A constructor that takes an array of integers and makes a linked list, 
												//containing all the elements of the array, 
												//in the same order.As the second parameter, it takes the size of the array.
	Node* prev = NULL;
	
	for (int i = 0; i < arrSize; i++) {
	
		Node * newNode = new Node(arr[i],NULL);

		if (prev == NULL) {
			head = newNode;
			prev = newNode;
		}
		else {
			prev->setNext(newNode);
			prev = newNode;

		}


	}

}




void LinkedList::addFront(int newItem) {// The function inserts a new node, containing the newItem, at the beginning of the list.

	Node* newNode = new Node(newItem, head);
	head = newNode;

}



void LinkedList::addEnd(int newItem) { // The function inserts a new node, containing the newItem, at the end of the list.

	Node* newNode = new Node(newItem, NULL);
	Node* temp = head;
	Node* prev;
	
	while (temp != NULL) {
		prev = temp;
		temp = temp->getNext();
	}

	prev->setNext(newNode);

}


void LinkedList::addAtPosition(int position, int newItem) {
	Node* newNode = new Node(newItem, NULL);

	if (position < 1) {
		this->addFront(newItem);
		return;
	}

	Node* prev;
	Node* temp = head;

	for (int i = 0; i < position-1; i++) {
		prev = temp;
		temp = temp->getNext();

		if (temp == NULL) {
			this->addEnd(newItem);
			return;
		}
	}

	prev->setNext(newNode);
	newNode->setNext(temp);
}	


int LinkedList::search(int item) {

	int index = 1;
	Node* temp = head;

	if (head == NULL) {
		cout << "0 ";
		return 0;
	}

	while (temp != NULL) {
		if (temp->getData() == item) {
			cout << index << " ";
			return index;
		}
		temp = temp->getNext();
		index++;
	}

	cout << "0 ";
	return 0;
}

void LinkedList::deleteFront() { //The function deletes the first element of the list.

	head = head->getNext();

}

void LinkedList::deleteEnd() { //The function deletes the last element of the list.

	Node* temp = head;
	int secondLast = 0;

	while (temp != NULL) {
		secondLast++;
		temp = temp->getNext();
	}

	this->deletePosition(secondLast);
}


void LinkedList::deletePosition(int position) { //The function deletes the element at the given position of the list.If the position < 1 
												//or it is larger than the size of the list, only print ”outside range”.
	if (position < 1) {
		cout << "outside range";
		return;
	}

	Node* prev;
	Node* temp = head;

	for (int i = 0; i < position - 1; i++) {
		prev = temp;
		temp = temp->getNext();

		if (temp == NULL) {
			cout << "outside range";
			return;
		}
	}

	prev->setNext(temp->getNext());
		
	}


int LinkedList::getItem(int position) {

	if (position < 1) {
		cout << numeric_limits < int >::min() << " ";
		return numeric_limits < int >::min();
	}

	Node* temp = head;

	for (int i = 0; i < position - 1; i++) {
		temp = temp->getNext();

		if (temp == NULL) {
			cout << numeric_limits < int >::max() << " ";
			return numeric_limits < int >::max();
		}
	}

	cout << temp->getData() << " ";
	return temp->getData();
}


void LinkedList::printItems(){
	Node* temp = head;

	if (head == NULL) {
		return;
	}

	while (temp != NULL) {
		cout << temp->getData() << " ";
		temp = temp->getNext();
	}

}

LinkedList::~LinkedList() { //A destructor that manually deletes all the elements that are still in the list.
	Node* temp = head;
	Node* current;

	while (temp != NULL) {
		current = temp;
		temp = temp->getNext();
		delete current;
	}
}
