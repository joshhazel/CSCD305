#pragma once
#include "cscd305_w12_lab3.h"
/*
#pragma once

#include <iostream>
#include <string>

using namespace std;
*/


class CArray
{
public:
	//Constructors
	CArray();
	CArray(int size);
	~CArray();
	CArray(const CArray & orig); //copy constructor

	//Input-Output stream
	//friend ostream & operator<<(ostream & out, const CStudent & rhs);
	friend ostream & operator<<(ostream & out, const CArray & rhs);
	friend istream & operator>>(istream & in, CArray & rhs);

	//Overload methods
	bool operator!=(const CArray & rhs);
	bool operator == (const CArray & rhs);
	CArray & operator = (const CArray & rhs);
	int & CArray::operator[] (const int index); //need "CArray::" and space after brackets "operator[] ()"
	//Getters-Setters
	inline int getSize(){return this->m_size;}

private:
	int *m_array;
	bool *m_arrayBool;
	int m_size;
};