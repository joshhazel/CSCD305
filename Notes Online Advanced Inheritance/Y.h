#pragma once
#include "base.h"
class Y :
	public Base //Y inherits from Base
{
public:
	Y(char *n = "Why", int nn=422); //constructor
	virtual ~Y(void); //deconstructor

	Y(const Y & orig); //copy constructor
	//Y(const Base & orig) // this does what???

	virtual Base & operator=(const Base & orig); // what does virtual do here
	Y & operator=(const Y & rhs);  //assignment operator
	virtual void print(ostream & out); // what does virtual do here

	friend ostream & operator<<(ostream & out, Y & rhs);


private:
	int num;
};

