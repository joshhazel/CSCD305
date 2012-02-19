/*
Joshua Hazel
CSCD305 C++
Lab 4 Inheritance
*/

#include "main.h"
#include "Student.h"
#include "Grad.h"

int main()
{
	CStudent *studentPtr; 
	
	CGrad a("stu steiner", 666, 15);
	CGrad * b = new CGrad();

	cout << "Test via regular CGrad Object" << endl;
	a.print(cout);
	cout << "The fees are: " << a.calcFees() << endl << endl;
	
	cout << "Test via CGrad pointer" << endl;
	b->print(cout);
	cout << "The fees are: " << b->calcFees() << endl << endl;

	cout << "Polymorphic behavior" << endl;
	studentPtr = b;
	cout << "Using Print" << endl;
	studentPtr->print(cout);
	cout << "The fees are: " << studentPtr->calcFees() << endl << endl;
	
	cout << "Using ostream operator<<" << endl;
	cout << *studentPtr;
	cout << "The fees are: " << studentPtr->calcFees() << endl;

	string temp;
	getline(cin, temp);

	return 0;
}
