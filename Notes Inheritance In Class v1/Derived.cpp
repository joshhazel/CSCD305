#include "Derived.h"



//To call the parent class constructor ":Base(values)"
Derived::Derived(int xx, int yy):Base(xx)
{
	y = yy;
}
Derived::~Derived(void)
{
	cout << "Derived" << *this << endl;
}

//Like toString
void Derived::print(ostream & out)
{
	Base::print(out);
	out << "Derived class " << y << endl;
	
}


void Derived::someMethod()
{
	cout << "Derived someMethod" << endl;

}

ostream & operator<<(ostream & out, const Derived & rhs)
{
	
	out << "Derived class " << rhs.y << endl;
	return out;

}