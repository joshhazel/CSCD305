/*
Joshua Hazel
CSCD305 C++
Lab 4 Inheritance
*/

#pragma once
#include "main.h"
#include "Student.h"

class CGrad : public CStudent
{
public:
	CGrad(string s="Ima Nerd", int i=123456, int cr=12, double fee = 202.50);
	CGrad(const CGrad & orig);
	virtual ~CGrad();
	CGrad & CGrad::operator=(const CGrad & rhs);

	double calcFees()const;
	void print(ostream & out)const;

	friend ostream & operator<<(ostream & out, const CGrad & rhs);

private:
	double fee;
};

