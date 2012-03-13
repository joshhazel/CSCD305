#include "Employee.h"

Employee::~Employee() {}
ostream& operator<<(ostream& out, Employee& rhs) //
{
	rhs.Print(out << "Name: " << rhs.first << " " << rhs.last << endl);
	return out;
}
Employee& Employee::operator=(const Employee& rhs) //
{
	if(this != &rhs)
	{
		this->first = rhs.first;
		this->last = rhs.last;
	}
	return *this;
}