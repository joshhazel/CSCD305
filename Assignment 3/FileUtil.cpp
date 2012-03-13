#pragma once
#include "FileUtil.h"
#include "knihtclinput.h"

using namespace kniht;


ifstream openInput (string filename)
{
	//Open file
	ifstream fin;
	fin.open(filename, ios::in);

	//Request filename if fail
	while ( fin.fail() )
	{
		cout << "Input file name: " << flush;
		getline(cin, filename);
		fin.clear();
		fin.open(filename);
		if (fin.fail())
			cout << "Failed to open " << filename << " --- try again\n";
	}
	return fin;
}

ofstream openOutput (string filename)
{
	//Open file
	ofstream fout;
	fout.open(filename);

	//Request filename if fail
	while ( fout.fail() )
	{
		cout << "Output file name: " << flush;
		getline(cin, filename);
		fout.clear();
		fout.open(filename);
		if (fout.fail())
			cout << "Failed to open " << filename << " --- try again\n";
	}

	return fout;
}

string getFilename(string fileType)
{
	string filename = "";
	while(filename == "")
	{
		cout << "\nPlease provide the " << fileType << " filename: ";
		getline(cin,filename);
	}
	return filename;
}

void menu(LinkedList* list, ofstream& fout)
{
	string input = "";
	while(input != "4")
	{
		cout << endl
			<< "Select an option from below:" << endl
			<< "1.  Edit pigment quantities for a customer" << endl
			<< "2.  Remove information on a customer" << endl
			<< "3.  Write contents (append) to output file" << endl
			<< "4.  Quit"  << endl << endl
			<< "Selection: ";

		getline(cin,input);
		if( input.length() == 0)
			input="0";
		cout << endl;
		switch (input.at(0))
		{
			case '1':
				editPigment(list);
				break;
			case '2':
				removeCustomer(list);
				break;
			case '3':
				writeFile(list,fout);
				break;
			case '4':
				break;
			default: 
				cout << "\nInvalid input.\n";
				break;
		}
	}
}

void editPigment(LinkedList* list)
{
	int input = -1;
	
	while(input != 0)
	{
		input = getInput("Enter Customer Number to update or '0' to quit: ",1,9999);
		vector<Customer*> customer = list->findCustomerOrders(input);
		if(input == 0)
		{}
		else if(customer.size() == 0)//NULL)
		{
			cout << "Customer not found!" << endl << endl;
		}
		else
		{
			//should be 2 match for 5147 customer
			cout << "\nFound " << customer.size() << " customer order(s)" << endl
				<< "Select an order to edit from the following: " << endl
				<< "   Mix No.\t Name\t\t\tPig 1\tPig 2\tPig 3\tFee" << endl;
			for(int i = 0; i < customer.size(); i++)
			{
				cout << (i+1) << ". " << *(customer.at(i));
			}
			input = getInput("Entry Number: ",1,customer.size());
			customer.at( (input-1) )->setPig1(getInput("New pigment 1 value: ",0,99999));
			customer.at( (input-1) )->setPig2(getInput("New pigment 2 value: ",0,99999));
			customer.at( (input-1) )->setPig3(getInput("New pigment 3 value: ",0,99999));
			cout << endl << "Order Updated: " << *(customer.at(input-1));
		}
	}
}
void removeCustomer(LinkedList* list)
{
	int input = -1;
	
	while(input != 0)
	{
		input = getInput("Enter Customer Number to remove or '0' to quit: ",1,9999);
		if(input != 0)
		{
			if(list->removeAll(input))
			{
				cout << "Customer number " << input << " and all associated orders deleted." << endl << endl;
			}
			else
			{
				cout << "Customer number " << input << " not found." << endl;
			}
		}
	}
}
int getInput(string msg, int min, int max)
{
	int input = -1;

	while(input != 0)
	{
		try{
			cout << msg;
			if(!(cin >> input >> blankline)) 
			{
				throw runtime_error("Invalid entry...");
			}
			else if(input != 0 && (input < min || input > max))
			{
				throw runtime_error("Invalid entry... ");
			}
			return input;
		}
		catch (...)
		{
			cout << endl << "Invalid entry..." << endl;
			cin >> clearline;
		}
	}
	return 0;
}

void writeFile(LinkedList* list,ofstream& fout)
{
	//Create vector of Customer* from linkedlist
	vector<Customer*> customers = list->getAll();

	fout << "______________________Start Set________________________________" << endl << endl;
	fout << "Sort by Original Input: " << endl << endl;
	printHeader(fout);
	printVector(customers,fout);
	fout << endl << endl;

	//Sort by customer name, then mixture #
	Customer cust;
	sort(customers.begin(),customers.end(), cust);
	fout << "Sort by Customer Name: " << endl << endl;
	printHeader(fout);
	printVector(customers,fout);
	fout << endl << endl;

	//Sort by customization fee, then cust name, then mix #
	sort(customers.begin(),customers.end(), sortFunction);
	fout << "Sort by Customization Fee: " << endl << endl;
	printHeader(fout);
	printVector(customers,fout);
	fout << "________________________End Set________________________________" << endl << endl;

	cout << "Data written to file..." << endl;
}
bool sortFunction(Customer* lhs, Customer* rhs)
{
	if(*lhs < *rhs)
		return false;
	return true;
}
void printHeader(ofstream& fout)
{
	fout << "                                   --- Pigment ---             " << endl;
	fout << left << setw(10) << "Mixture" << setw(25) << "Customer Name" << setw(6) << "1" << setw(6) << "2" << setw(6) << "3" << setw(10) << "Fee/gallon" << endl;
	fout << "---------------------------------------------------------------" << endl;
}
void printVector(vector<Customer*> customers,ofstream& fout)
{
	for(int i = 0; i < customers.size(); i++)
	{
		fout << *(customers.at(i));
	}
}