#include "Y.h"

int main()
{
	Base a("Fred"), d("Dee"), *e=NULL; //Base obj
	Y b("Greg", 1988), c("See", 12345); //Y obj - extra private int

	//Print Base and Y obj using overloaded ostream<<
	cout << a << endl; //Fred
	cout << b << endl; //Greg 1988
	cout << c << endl; //See 12345
	cout << d << endl; //Dee

/*
	//Call the base class copy constructor
	Base f = c; 

	//Calls the derived class copy constructor
	Y g=d;

*/

	d = a; //d and a are already constructed type Base   // Assign Fred to d
	cout << "Should print " << endl << a << "==========" << endl; // Print Fred
	cout << d << endl; //Print Fred

	c = b; //c and b are already constructed type Y obj // Assign Greg 1988 to c
	cout << "Should print " << endl << b << "==========" << endl; // Print Greg 1988
	cout << c << endl; //Print Greg 1988

//Assign a child to already constructed parent object
//This calls assignment in derived Y class for the base class -> then set the other val to default
	d = c; //d is Base, c is type Y obj, both already constructed - copy Y obj to D obj // Assign Greg 1988 to d
	cout << "Should print " << endl << c << "==========" << endl; //Print Greg 1988
	cout << d << endl; //Print Greg 1988

//Assign a child to a null parent object
//This will "slice" which could memory leak
	e = &c; //e is null Base *ptr, c is constructed Y obj  // Assign Greg 1988 to &c
	cout << "Should print " << endl << c << "==========" << endl; //Print Greg 1988
	cout << *e << endl; //Deref e, print Greg 1988

	string exit;	cout<<"\nPress <enter> to quit\n";	getline(cin,exit);
	return 0;
}
