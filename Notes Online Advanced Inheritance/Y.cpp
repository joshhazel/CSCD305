#include "Y.h"


Y::Y(char * n, int nn):Base(n) //Call base constructor pass in n
{
	this->num = nn; //Assign nn to Y.num
}


Y::~Y(void)
{
	cout << "Y: "<< endl;
}

Y::Y(const Y & orig)
{

}
/*
Y::Y(const Base & orig)
{
	this->name = NULL;
	Base::operator=(orig); //cannot use Y::, need to use Base::
	this->num = 4222;
}

Base & Y::operator=(const Base & orig)
{
	if(this != &orig)
	{
		Base::operator=(orig);
		this->num = 422;
	}
}
*/

//Base & Y
Base & Y::operator=(const Base & rhs)
{
	const Y *pD = dynamic_cast<const Y*>(&rhs); //what does this dynamic_cast do?
	return *this;
}

Y & Y::operator=(const Y & rhs)
{
	if(this != &rhs) //check if assigning same object
	{	//if not same object
		if(this->name != NULL) //check if memory allocated
			delete [] this->name; //mem allocated, delete it

		this->name = new char[strlen(rhs.name) + 1]; //create new char ptr
		strcpy(this->name, rhs.name); //copy rhs to this->name

		this->num = rhs.num; //copy num
	}
	return *this; //return deref copy
}

void Y::print(ostream & out)
{
	Base::print(out); //call base print, pass it the ostream
	out << "Y: " << this->num << endl; //this->num to out

}

ostream & operator<<(ostream & out, Y & rhs)
{
	rhs.print(out);
	return out;
}

