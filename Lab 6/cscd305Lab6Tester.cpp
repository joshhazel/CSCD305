/*
Joshua Hazel
CSCD305 C++
Stu Steiner
Lab 6

Notes:  
	Do not need to use static fee, per Stu

	Assumptions made:		(assignment unclear)
	Withdrawal fee:
		Applies to both CHECKING and SAVINGS
		Applies --ONLY-- applied when money is ACTUALLY REMOVED from the balance
			No fee for $0.00 withdrawals, 
			Declined SAVINGS withdrawal --DO NOT-- cause an OVERDRAFT fee
		Allowed to cause a negative SAVINGS balance

/***************************************************************************
This is the driver file for an inheritance hierarchy that involves a base
class called Account which is abstract.  Account has two derived classes,
Checking and Savings, which are both concrete.  This file will allow the
user to choose the type of account to create, then provide options for
working with the account.  Polymorphic behavior is demonstrated through
the constructs in this driver.

NOTE: You'll need to make appropriate changes below so the vector works
properly
***************************************************************************/
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#pragma warning (disable : 4018)
void notes();

int main(void)
{
	notes();
	vector<Account*> pAccounts(10); //dynamic array
	int i = 0, j; //loop control vars

	char choice; //menu selection from user


	do
	{
		cout << "What type of account would you like?" << endl
		    << "  1. Checking" << endl
			<< "  2. Savings" << endl
			<< "Enter choice: ";
		cin >> choice;

		//create appropriate object
		if (choice == '1')
			pAccounts[i] = new Checking; //get starting balance in constructor
		else if (choice == '2')
			pAccounts[i] = new Savings; //get starting balance in constructor
		else
			cout << "Invalid choice!" << endl;

		if (choice == '1' || choice == '2')
			do
			{
				cout << "\nWhat would you like to do with this account?" << endl
					<< "  1. Deposit" << endl
					<< "  2. Withdraw" << endl
					<< "  3. View balance" << endl
					<< "  4. Quit" << endl
					<< "Enter choice: ";
				cin >> choice;

				switch (choice)
				{
				case '1': pAccounts[i]->deposit();//gets deposit amount from user
												//and adds it to balance
					break;
				case '2': pAccounts[i]->withdraw();//gets withdrawal amount from user
												//and subtracts it (if possible)
					break;
				case '3': pAccounts[i]->printBalance();//prints current balance
					break;
				case '4': cout << "Finished with " << pAccounts[i]->getName()
							  << " account" << endl;
					break;
				default: cout << "Invalid choice!" << endl;
				}//end switch

			} while (choice != '4'); //end account operations menu

		cout << "Would you like to create and work with another account (y/n)?"
			<< endl;
		cin >> choice;
		i++;
	} while (choice != 'n');

	//clean up allocated memory! make sure destructors are virtual!
	for (j = 0; j < pAccounts.size(); j++)
		delete pAccounts[j];

	cout << "Good Bye!" << endl;

	return EXIT_SUCCESS;
}//end main

void notes()
{
	cout <<
"Joshua Hazel\
\n\n\
Notes:  \
Do not need to use static fee, per Stu \n\
\n\
Assumptions made:		(assignment unclear) \n\
Withdrawal fee: \n\
	Applies to both CHECKING and SAVINGS \n\
	Applies --ONLY-- applied when money is REMOVED from the balance \n\
		No fee for $0.00 withdrawals,  \n\
		Declined SAVINGS withdrawal --DO NOT-- cause an OVERDRAFT fee \n\
	Allowed to cause a negative SAVINGS balance \n\n\
";
}