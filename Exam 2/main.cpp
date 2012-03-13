#pragma once //
#include "Employee.h"
#include "HourlyWorker.h"

/*
1. Based on the following driver file
	a.	Write the code to complete the interface for the Employee class.
	b.	Write any code you deem necessary for the function prototypes you placed in the interface of the Employee class.
	c.  Complete the interface for the HourlyWorker class (which is derived from Employee).
	d.  Write the code necessary for the functions in the HourlyWorker class.  Include member functions to ensure the driver file below executes propery.
*/
int main()
{
	//create an hourly worker:  first name, last, wage, hours worked
	Employee *h1 = new HourlyWorker("Karen", "Price", 14.00, 48);
	Employee *h2 = new HourlyWorker("Fred", "Smith", 10.50, 25);

	cout << "Specific employee info: \n";

	cout << *h1 << endl;
	/*	prints employee name, type of employee,
		and anything specific to that employee type (wage, hours worked, etc.)
	*/

	//getEarnings() should be polymorphic
	cout << "Employee earnings were: " << h1->getEarnings() << endl;

	//assignment operator overload
	*h2 = *h1;  
	
	cout << *h2 << endl; 

	delete h1;
	delete h2;
	
	cin.ignore(255,'\n');
	return 0;

}//end main

/*
2.  In an inheritance hierarchy explain why you would have a virtual destructor?
	Is there ever an instance where you would not want a virtual destructor?

	You would want to have a virtual destructor whenever you have virtual methods,
	or polymorphism (a derived type of base class).  Also, whenever your derived
	class has memory allocated.

	I think you should always declare a virtual destructor, but if you make sure
	a user never inherits from the class, do not create classes from it,
	do not create pointer from the the super(), or create an instance on the heap
	then you could probably do without.

3.  C++ expections are very similar to Java with a few differences.  Explain the
	differences as it relates to the try, catch, throw.  In particular discuss
	pointer versus object and a generic exception.

	Exceptions are inherited from Throwable so they share the same interface.
	There are no destructors in Java.  C++ exception functions are called at 
	run-time when the wrong exception is thrown.  Java exception spex are 
	enforced and checked at run-time and you have to document if the method
	can throw an exception.
	
	Java solves C++ problems with by using a finally statement.  If an exception
	in C++ leaves the function scope the objects allocated on the stack are 
	released and it calls the destructors.  Which means you must free memory
	when an exception occurs by having code in a destructor of the object.
	
4.	C++ abstract classes and interfaces are similar yet different then Java.
	Compare and contrast C++ abstract classes and interfaces to Java abstract
	classes and interfaces.

	In C++ for an interface you would simply create all methods to be virtual.
	Abstract classes and interfaces in C++ and Java are not much different.
	In Java you cannot inherit from more than one base class.  However, in both
	for an interface for the base class you make nothing but virtual functions.
	In java though you can have multiple interfaces.  

	In C++ you can declare functions and member variables while in Java you cannot.
	In Java you do not need to declare virtual because it is not possible
	to inherit from more than one base class.

5.	In class we examined C++ vectors.  Compare and contrast C++ vectors to Java
	vectors and Java ArrayLists.  Why would you use a vector?  Is there a 
	different data structure that is better than a vector?

	Both use fixed array length that when allocated and add too many elements
	the array grows by 1.5x to 2.0x to cover additional slots that may be 
	required for additions.  

	Vectors are synchronized and thread safe while ArrayList are not.
	The vector increases its size by double while ArrayList increases
	its size by 50% 

	In some cases vector may be the best but in others a data structure like 
	a linked list may be better.  A linked list will allow you to add or 
	delete an element in constant time since you wont have to shift 
	all the elements of the array in the arraylist/vector.  The trade-off
	is that a linked list would require more time to insert as it has to traverse
	the entire list to add an element.
*/