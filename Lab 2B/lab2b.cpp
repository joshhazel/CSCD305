/*
Joshua Hazel
CSCD 305 C++
Stu Steiner

Part-B
Uses lab2PartBImplement.cpp, Lab_2.h, customer.h
*/

#include "lab2b.h";
#include "customer.h";

//Starting value of student
int CCustomer::next_id = 12345;


int main()
{
	questionB1();
	questionB2();
	questionB3();
	questionB4();
	questionB5();
	questionB6();
	questionB7();
	questionB8();
	questionB9();
	questionB10();
	questionB11();
	questionB12();
	questionB13();
	questionB14();

	//Question 14: Test Class below...

	//Test DVC
	CCustomer me;
	//Test EVC 
	CCustomer me1("name1","addy1","city1","state1","zip1",10000);
	CCustomer me2("name2","addy2","city2","state2","zip2",20000);
	CCustomer me3("name3","addy3","city3","state3","zip3",30000);
	//Test accessors
	cout << "Name: " << me.get_name() << "\tID: " << me.get_id() << "\tCredit $" << me.get_credit_limit() << endl 
		<< "Address: " << me.get_address() << " " << me.get_city() << " " << me.get_state() << " " << me.get_zipcode() << endl << endl;
	//Test ostream & incrementing ID #
	cout << me1 << endl;
	cout << me2; cout << endl;
	cout << me3; cout << endl;

	//Test manipulators
	cout << "\nChanging me3.set methods...\n\n";
	me3.set_name("SetName"); me3.set_address("SetAddress"); me3.set_city("SetCity"); me3.set_state("SetState"); me3.set_zipcode("SetZip"); me3.set_credit_limit(1000.00);
	cout << me3; cout << endl;
		
	//Test Question6
	cout << "\nChecking to see if can purchase $5000, if credit limit available.\n\t";
	if(!me3.make_purchase(5000.00)) cout << "Purchase for $5000.00; Not enough credit available. \n\tCredit balance available: " << me3.get_balance();
	else cout << "Purchase for $5000.00; Credit available for purchase. \n\tCredit balance available: " << me3.get_balance();

	cout  << "\n\nIncreasing credit limit to $10000 ( increase_limit() )\n\n";
	me3.increase_limit(9000.00);
	cout << "\nChecking to see if can purchase $5000, if credit limit available.\n\t";
	if(!me3.make_purchase(5000.00)) cout << "Purchase for $5000.00; Not enough credit available. \n\tCredit balance available: " << me3.get_balance();
	else cout << "Purchase for $5000.00; Credit available for purchase. \n\tNew Credit balance available: " << me3.get_balance();


	int exit; cout << "\n\nType q <enter> to exit\n"; cin >> exit;

	//Exit normally
	return 0;
}//end main
