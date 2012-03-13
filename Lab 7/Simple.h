#pragma once

#include <iostream>
using namespace std;


class Simple
{
public:

	Simple(int x = 10)
	{
		val = x;
	}

	Simple & operator=(const Simple & rhs)
	{
		if(this != & rhs)
			this->val = rhs.val;

		return *this;
	}// end operator=

	friend ostream & operator<<(ostream & out, const Simple & rhs)
	{
		out << rhs.val;
		return out;

	}// end operator<<

	friend istream & operator>>(istream & in, Simple & rhs)
	{
		in >> rhs.val;
		return in;

	}// end operator>>

private: 
	int val;
};

