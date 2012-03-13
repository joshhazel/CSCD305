#pragma once

#include "Customer.h"

class Node
{
public:
	Node();
	Node(Customer* data);
	Node(Customer* data, Node* next);
	~Node();

	Node* getNext();
	void setNext(Node*);
	Customer* getData(); //   cast:  (Customer*)data


private:
	Customer* data;
	Node* next;
};

