#pragma once

#include "main.h"

class CHugeInt
{
public:
	//Constructors
	CHugeInt();
	CHugeInt(string input);
	~CHugeInt();
	CHugeInt(const CHugeInt &orig);//Copy Constructor

	//Accessors and Mutators
	inline int getSize(){return this->m_size;};
	string getInt();
	void setInt(string input);
	void *operator new[](size_t size);
	//static void* operator new (size_t size); 
	//static void operator delete (void *p);

	//Overrides
	friend ostream & operator <<(ostream & out, const CHugeInt & rhs);
	friend istream &operator>>(istream &in, CHugeInt &rhs);
	bool operator==(const CHugeInt &rhs);
	bool operator!=(const CHugeInt &rhs);
	bool operator>(const CHugeInt &rhs);
	bool operator>=(const CHugeInt &rhs);
	bool operator<(const CHugeInt &rhs);
	bool operator<=(const CHugeInt &rhs);
	CHugeInt operator*(const CHugeInt & rhs);
	CHugeInt operator/(const CHugeInt & rhs);
	CHugeInt operator+(const CHugeInt & rhs);
	CHugeInt operator-(const CHugeInt & rhs);
	CHugeInt operator-();//unary minus, negative 
	CHugeInt operator--(int notUsed);// post decrement
	CHugeInt operator++(int notUsed);// post increment
	CHugeInt &operator--();//pre decrement
	CHugeInt &operator++();//pre increment
	CHugeInt &operator=(const CHugeInt &rhs);//assignment
	CHugeInt &operator+=(const CHugeInt & rhs);

private:
	
	//Data member
	int *m_ints;
	int m_size;
	bool m_bNeg; //track negative values

};