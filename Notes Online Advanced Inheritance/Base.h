#pragma once

#include <iostream>
#include <cstring> //what is cstring
#include <string>
using namespace std;


class Base
{
public:
	Base(char * name = "Ima Nerd");
	~Base(void);

	Base(const Base & orig);
	//Base(const Y & orig); //can you do this??
	virtual Base & operator=(const Base & orig);
	virtual void print(ostream & out); //why do you want a print instead of ostream <<

	friend ostream & operator<<(ostream & out,  Base & rhs);


protected:
	char * name;
};

