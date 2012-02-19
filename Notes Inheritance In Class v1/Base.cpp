#include "Base.h"


Base::Base(int xx)
{
	this->x = xx;
}


Base::~Base(void)
{
	cout << "Base" << *this << endl;
}

void Base::print(ostream & out)
{
	out << "Base " << x << endl;
}

void Base::someMethod()
{
	cout << "Base someMethod()" << endl;

}

ostream & operator<<(ostream & out, const Base & rhs)
{
	out << "Base " << rhs.x << endl;
	return out;
}
