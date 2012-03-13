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
	bool removeAll(int custNumber);
	bool isEmpty();
	int getIndex(int);
	Customer* getData(int);
	vector<Customer*> findCustomerOrders(int customerNumber);
	vector<Customer*> LinkedList::getAll();

private:
	int size;
	Node* head;
};

