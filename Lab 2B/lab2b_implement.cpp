/*
Joshua Hazel
CSCD 305 C++
Stu Steiner

Part-B
Uses lab2PartBTester.cpp, Lab_2.h, customer.h
*/

#include "lab2b.h";

void questionB1()
{
	cout << "1. Create customer.h, customer.cpp and lab2PartBTester.cpp. \nThe tester file will be empty for the time being. \nCreate inline member functions for the accessor functions.\n\n";
	cout << "Why use inline function over a function in the implementation file? \n";
	cout << "\tLess code, runs faster, does not require separate prototype.\n\n";
	cout << "What are 2 drawbacks to inline member functions? \n";
	cout << "\tIt may make the header file large and/or unreadable, \n\talso inline functions can be less flexible and require recompile\n\n";
}
void questionB2()
{
	cout << "2. Class Customer has a common syntactical error.  Try to compile this code and state the error.\n\
	Error 10 error C1004: unexpected end-of-file found:customer.cpp 29\n\n";
	cout << "What is the fix to this error?\n";
	cout << "\tAdd a semicolon ';' to the end of the class encapsulation\n\n";
}
void questionB3()
{	
	cout << "3. Class Customer FAILS to effectively encapsulate a data member, thereby risking a runtime error due to corrupted data. Locate the problem(s) and propose a solution and code it.\n";
	cout << "\tdouble credit_limit; is public rather than private, make it private\n\n";
}
void questionB4()
{
	cout << "4. One data members is PROPERLY encapsulated but value cannot be detected. \nWhat is it and what member function might be added later that might use it? \nMake sure you add the member function. \n";
	cout << "\tzip code is private, and cannot be accessed, add get_zipcode() method.\n\n";
}
void questionB5()
{
	cout << "5. Suppose that the Customer class is going to be expanded to keep track of total year-to-date purchases. Declare data fields, accessors and mutators which will keep track of the total number of sales and total sales for each instance of Customer.\n\tdone...\n\n";
}
void questionB6()
{
	cout << "6. Suppose that management now wants to automate the customer management system to detect\
	when a new purchase cannot be made because the credit limit will be exceeded.  You will\
	need to declare or modify data members, constructors, accessors and mutators to expand the\
	Customer class to return a value specifying that a new purchase would exceed the credit limit.\
	This can be calculated by passing the purchase price into a member function, adding this to\
	the unpaid balance and comparing it to the credit line. \n\n";
}
void questionB7()
{
	cout << "7. This class contains only an explicit value constructor.  \nShould this class require a default value constructor?  \nYes or no, justify your answer.\n";
	cout << "It is not required, however, if DVC is called it is implicitly declared by the constructor with a null body. Typically not required if it has no function and non-static members have constructors. But should be included if you want to set default values for your class member variables when object is created.\n\n";
	cout << "Code a default value constructor you can pick the default values.  \nThere should only be a single constructor for this class that handles  \nboth default value and explicit value values.\n\tDone... \n\n";
}
void questionB8()
{
	cout << "8. Code the tester file to test all aspects of your class. \n\tDone...\n\n";
}
void questionB9()
{
	cout << "9. Add code to your files to allow the following code: \n\
	cout << cust << endl;   // presume cust is an object of customer \n\
	the non-member function prototype will be:\n\
	ostream & operator<< (ostream & out, const Customer & rhs) \n\n";
 	
	cout << "What changes did you make to your class in order for the code to compile?\n";
	cout << "\tAdded 'friend' before the header, it allows placement in the class\n\n";
}
void questionB10()
{
	cout << "10. Explain the purpose of the ostream & return type.\n";
	cout << "\tostream & as return type allows chaining << output.\n\n";
}
void questionB11()
{
	cout << "11. Explain why the ostream & out as a parameter is not constant whereas the Customer parameter is constant. \n\
	It is being returned byRef and allows to be modified\n\n";
}
void questionB12()
{
	cout << "12. Add a constant int called custID that is originally 12345.  \nEach time a customer is added the id will be incremented so each customer has a unique id value.  \n\tDone...\n\n";
}
void questionB13()
{
	cout << "13. Add the appropriate methods to access the customer’s ID. \n\tDone...\n\n";
}
void questionB14()
{
	cout << "14. Enter code into the tester and show that all your code works.    \n\tDone...\n\n";
}
