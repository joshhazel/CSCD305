#pragma once

#include "main.h"

class Account
{
protected:
	//methods
	void withdraw(double);
	double getAmount(string);

	//variables
	double balance;
	int withdrawCount;

public:
	//Constructor
	Account();
	Account(string name);
	virtual ~Account();
	Account(const Account & orig);

	//Overloads
	Account & operator=(const Account & rhs);

	//Gets
	virtual string getName();
	void printBalance();
	
	//Actions
	virtual void withdraw();
	void deposit();

private:
	string name;
};