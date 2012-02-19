#pragma once
#include "Base.h"

//Multiple inheritance allows you to have multiple parents possibly up to 36

//": public Base" gives you access to all public stuff in Base
//Additional inheritance:   class Derived : public Base, public OtherClass, public AnotherClass
// ": public Base " 
//Virtual keywork ONLY in .h file

class Derived : public Base
{
public:
	Derived(int xx=66, int yy=42);
	virtual ~Derived(void);

	inline int getY(){return y;}
	inline void setY(int yy){y = yy;}

	void print(ostream & out);
	void someMethod();

	friend ostream & operator<<(ostream & out, const Derived & rhs);

private:
	int y;
};

