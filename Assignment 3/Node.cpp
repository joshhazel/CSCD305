#pragma once
#include "Node.h"


Node::Node()
{
	this->data = NULL;
	this->next = NULL;
}
Node::Node(Customer* data)
{
	this->data = data;
	this->next = NULL;
}
Node::Node(Customer* data, Node* next)
{
	this->data = data;
	this->next = next;
}
Node::~Node()
{
}


Node* Node::getNext()
{
	return this->next;
}
void Node::setNext(Node* next)
{
	this->next = next;
}
Customer* Node::getData()
{
	return this->data;
}