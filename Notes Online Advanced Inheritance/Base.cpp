#include "Base.h"


Base::Base(char * n) //Constructor
{
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}


Base::~Base(void) //Deconstructor
{
	if(this->name != NULL) //Deleete non-null alloc memory
		delete [] this->name;

	this->name = NULL; //Set * to null
}

Base::Base(const Base & orig) //Copy constructor
{
	this->name = NULL; //Set ptr to NULL before calling =

	*this = orig; //Call assignment operator
}
Base & Base::operator=(const Base & orig) //Assignment overload, Return Base
{
	if(this != & orig)//Check if both obj are the same obj
	{ //If they are not
		if(this->name != NULL) //Delete alloc memory
			delete [] this->name;

		this->name = new char[strlen(orig.name) + 1]; //Allocate mem for *
		strcpy(this->name, orig.name); //Copy string from orig.name to this->name
	}
	return *this; //return deref obj
}

ostream & operator<<(ostream & out,  Base & rhs) //overload ostream<<
{
	rhs.print(out); //call the print, pass in ostream to print
	return out; //return ostream
}

void Base::print(ostream & out) //take in ostream
{
	out << "Name: " << this->name << endl; //print name to ostream
}
