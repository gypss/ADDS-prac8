#include "Node.h"
using namespace std;

Node::Node(int num, Node* ptr) {
	data = num;
	next = ptr;
}

int Node::getData() {
	return data;
}

void Node::setData(int num) {
	data = num;
}

Node* Node::getNext() {
	return next;
}

void Node::setNext(Node* ptr) {
	next = ptr;
}