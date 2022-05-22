#ifndef NODE_H
#define NODE_H

class Node {
public:
	Node(int num, Node* ptr);
	int data;
	Node* next;

	int getData();
	void setData(int num);

	Node* getNext();
	void setNext(Node* ptr);
};

#endif