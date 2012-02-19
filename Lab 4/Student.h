/*
Joshua Hazel
CSCD305 C++
Lab 4 Inheritance
*/

#pragma once
#include "main.h"

class CStudent
{
public:
	CStudent(string s="Ima Nerd", int i=123456, int cr=12);
	CStudent(const CStudent & orig);
	~CStudent();

	string getName()const;
	int getID()const;
	int getCredits()const;
	
	void setName(string s);
	void setID(int i);
	void setCredits(int cr);
	
	CStudent & operator=(const CStudent & rhs);

	double calcFees()const;
	void print(ostream & out)const;

	friend ostream & operator<<(ostream & out, const CStudent& rhs);

private:
	string name;
	int id, credits;
	const double PER_CREDIT;
};

