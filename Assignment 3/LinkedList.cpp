#pragma once
#include "LinkedList.h"


LinkedList::LinkedList()
{
	this->size = 0;
	this->head = new Node();
}


LinkedList::~LinkedList()
{
	this->destroy();
}


bool LinkedList::isEmpty() 
{
	return this->size == 0;
}
void LinkedList::add(Customer* data)
{
	Node* temp = new Node(data);
	if(isEmpty())
	{
		this->head->setNext(temp);
	}
	else
	{
		Node* curr = this->head;
		while(curr->getNext() != NULL)
		{
			curr = curr->getNext();
		}
		curr->setNext(temp);
	}
/*	else
	{
		this->tail->setNext(temp);
	}
	this->tail = temp;*/

//	temp = NULL;
	this->size++;
}
int LinkedList::getIndex(int customerNumber)
{
	if(isEmpty())
		return -1;
	Node* curr = this->head->getNext();
	for(int i = 0; i < this->size; i++)
	{
		if( curr->getData()->getCustNumber() == customerNumber )
		{
			//curr = NULL;
			return i;
		}
	}
	return -1;
}
bool LinkedList::remove(int customerNumber)
{
	if(isEmpty())
		return false;

	Node* curr = this->head->getNext();
	Node* prev = this->head;
	
	for(int i = 0; i < this->size; i++)
	{
					
		if(curr->getData()->getCustNumber() == customerNumber) 
		{
			if(i == this->size-1)
			{
				prev->setNext(NULL);
			}
			else
			{
				prev->setNext(curr->getNext());
			}
			delete curr->getData();
			delete curr;
			this->size = this->size - 1;
			return true;
		}//end if
		prev = curr;
		curr = curr->getNext();
	}//end loop
	return false;
}
bool LinkedList::removeAll(int custNumber)
{
	bool removed = false;
	while(remove(custNumber) == true)
	{
		removed = true;
	}
	return removed;
}
vector<Customer*> LinkedList::findCustomerOrders(int customerNumber)
{
	vector<Customer*> customers;
	if(isEmpty())
	{
		return customers;
	}

	Node* curr = this->head;
	while(curr->getNext() != NULL)
	{
		curr = curr->getNext();
		if(curr->getData()->getCustNumber() == customerNumber)
		{
			customers.push_back(curr->getData());
		}
	}

	return customers;
}

Customer* LinkedList::getData(int customerNumber)
{
	if(isEmpty())
		return NULL;

	int index = this->getIndex(customerNumber);
	if(index == -1)
		return NULL;
	else if(index == 1)
	{
		return this->head->getNext()->getData();
	}

	Node* curr = this->head->getNext();
	for(int i = 0; i <= index; i++)
	{
		curr = curr->getNext();
	}

	return curr->getData();
}

void LinkedList::destroy()
{
	Node* curr = this->head;
	Node* next;
	while(curr->getNext() != NULL)
	{
		next = curr->getNext();
		delete curr->getData();
		delete curr;
		curr = next;
	}
	this->size = 0;
}

vector<Customer*> LinkedList::getAll()
{
	vector<Customer*> customers;
	if(isEmpty())
	{
		return customers;
	}

	Node* curr = this->head;
	while(curr->getNext() != NULL)
	{
		curr = curr->getNext();
		customers.push_back(curr->getData());
	}

	return customers;
}


ostream& operator<<(ostream& out, const LinkedList& rhs)
{
	Node* curr = rhs.head;
	while(curr->getNext() != NULL)
	{
		curr = curr->getNext();
		out << *(curr->getData());
	}
	return out;
}


