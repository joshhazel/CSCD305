#pragma once 

#include "Account.h"

Account::Account(string name) 
{
	withdrawCount = 0;
	this->name = name;
	
	this->balance = getAmount("Set Initial Balance: $");
}
Account::~Account()
{

}

Account & Account::operator=(const Account & rhs)
{
	this->withdrawCount = rhs.withdrawCount;
	this->name = rhs.name;
	this->balance = rhs.balance;

	return *this;
}
string Account::getName()
{
	return this->name;
}

void Account::printBalance()
{
	cout << endl << this->name << " Balance: $" << this->balance << endl;
}

void Account::withdraw(){} //virtual
void Account::withdraw(double amount)
{	
	if(amount <= 0)  //withrdraw is < $0  !!
	{
		cout << "\nWithdraw amount should be > $0.00" << endl;
	}
	else
	{
		this->withdrawCount ++;
		if(amount > this->balance)  //overdraft !!
		{
			cout << "Withdrawl amount $" << amount << " is more than current balance: $" << this->balance << endl;
			throw out_of_range("amount");
		}
		this->balance -= amount;  //make withdrawl
	}
}
void Account::deposit()
{
	double amount = this->getAmount("Amount to deposit: $");

	cout << "\nDepositing $" << amount << " into " << this->name << endl;
	this->balance += amount;
}

double Account::getAmount(string account)
{
	double amount = 0;

	cout << endl << account;
	cin >> amount;

	while(amount <= 0)
	{
		cout << endl << "Amount must be > $0.00" << endl << endl;
		cout << account;
		cin >> amount;
	}

	return amount;
}
