#pragma once

#include "Savings.h"
#include "Account.h"

Savings::Savings() : Account("Savings")
{
	//Call Account constructor
}
Savings::~Savings()
{

}
void Savings::withdraw()
{
	double amount = this->getAmount("Amount to withdrawl from savings: $");

	try
	{
		cout << "\nWithdrawing $" << amount << " from savings" << endl; //do not change
		Account::withdraw(amount);

		//AFTER 6th withrawal, so on the 7th withdrawal
		if(this->withdrawCount > 6)
		{
			cout << "\nWithdrawal fee of $3.00 charged for withdrawal # " << this->withdrawCount << endl;
			this->balance -= 3.00;
		}
	}
	catch (out_of_range)
	{
		cout << "Withdrawl is incomplete... no fees charged" << endl ;
	}
}