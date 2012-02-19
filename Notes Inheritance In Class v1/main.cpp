#include "Base.h"
#include "Derived.h"

int main()
{
	Base a;
	Base *b = new Base(15);

	Derived c;
	Derived *d = new Derived(99);

	cout << "a is: " << a;
	cout << "b is: " << *b;
	cout << "c is: " << c;
	cout << "d is: " << *d;

	cout << endl << "Calling methods of a" << endl;
	a.someMethod();
	a.print(cout);


	cout << endl << "Calling methods of pointer b" << endl;
	b->someMethod();
	b->print(cout);
	

	cout << endl << "Calling methods of c" << endl;
	c.someMethod();
	c.print(cout);


	cout << endl << "Calling methods of pointer d" << endl;
	d->someMethod();
	d->print(cout);

	b = d;
	cout << endl << "Calling methods of pointer b" << endl;
	b->someMethod();
	b->print(cout);

	string exit;	cout<<"\nType q and <enter> to quit";	getline(cin,exit);
	return 0;
}