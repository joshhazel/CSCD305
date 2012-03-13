#pragma once

#include "Checking.h"
#include "Account.h"

Checking::Checking() : Account("Checking")
{
	//Call Account constructor
}
Checking::~Checking()
{

}
void Checking::withdraw()
{
	double amount = this->getAmount("Amount to write check for: $");

	try
	{
		cout << "\nWriting a check for $" << amount << " dollars"; //do not change
		
		//AFTER 6th withrawal, so on the 7th withdrawal
		if(this->withdrawCount > 6)
		{
			cout << "\nWithdrawal fee of $3.00 charged for withdrawal # " << this->withdrawCount << endl;
			this->balance -= 3.00;
		}
		cout << endl;

		Account::withdraw(amount);
	}
	catch (out_of_range &ex)
	{
		this->balance -= 35;
		this->balance -= amount;
		cout << endl 
			<< "Transferring funds from savings" << endl
			<< "Overdraft fee of $35 deducted from account, new balance is $" << this->balance << endl;
	}
}