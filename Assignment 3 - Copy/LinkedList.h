#pragma once
#include "Node.h"
#include "Customer.h"

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	friend ostream& operator<<(ostream& out, const LinkedList& rhs);

	void destroy(); //delete ptrs
	void add(Customer* data);
	bool remove(int);
	bool isEmpty();
	int getIndex(int);
	Customer* getData(int);
private:
	int size;
	Node* head;
	Node* tail;
};

