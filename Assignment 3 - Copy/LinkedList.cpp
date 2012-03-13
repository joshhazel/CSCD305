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
		this->tail->setNext(temp);
	}
	this->tail = temp;

	temp = NULL;
	this->size++;
}
int LinkedList::getIndex(int customerNumber)
{
	if(isEmpty())
		return -1;
	Node* curr = this->head->getNext();
	for(int i = 0; i < this->size; i++)
	{
		if( ((Customer*)curr->getData())->getCustNumber() == customerNumber )
		{
			curr = NULL;
			return i;
		}
	}
	return -1;
}
bool LinkedList::remove(int customerNumber)
{
	if(isEmpty())
		return false;

	int index = this->getIndex(customerNumber);
	if(index == -1)
		return false;
	else if(index == 1)
	{
		delete this->head->getNext()->getData();
		delete this->head->getNext();
		this->head->setNext(NULL);
		this->tail = NULL;
		return true;
	}

	Node* curr = this->head->getNext();
	Node* prev = this->head;

	for(int i = 0; i <= index; i++)
	{
		prev = curr;
		curr = curr->getNext();
	}
	if(curr == this->tail)
	{
		this->tail = prev;
		prev->setNext(NULL);
	}
	else
	{
		prev->setNext(curr->getNext());
	}
	delete curr->getData();
	delete curr;
	curr = NULL;

	return true;
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
	curr = NULL;
	next = NULL;

	this->size = 0;
	this->head = NULL;
	this->tail = NULL;
}

ostream& operator<<(ostream& out, const LinkedList& rhs)
{
	Node* curr = rhs.head;
	while(curr->getNext() != NULL)
	{
		curr = curr->getNext();
		out << *(curr->getData());
	}
	curr = NULL;
	return out;
}
