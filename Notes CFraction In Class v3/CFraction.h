#pragma once

#include <iostream>
using namespace std;
#include <string>

class CFraction
{
public:
	CFraction(int num = 0, int den = 1);

	//Copy constructor, should CFraction be const?  YES, we dont want obj to change, do not make CONTRUCTOR const CFraction() thuiogh
	//The & is requires because.......................???
	CFraction(const CFraction & orig); //copy constructor, anytime byval passed or return copy constructor is called

	//Deconstructor
	~CFraction(void);

	//Create copy , const here not to change rhs, if you put const before ; it would not allow to change in function
	//want CFraction & operator, & to allow chaning 
	CFraction & operator = (const CFraction & rhs);


	CFraction operator+(const CFraction & rhs)const;
	CFraction & operator+=(const CFraction & rhs);
	CFraction operator-();//unary minus
	//two ++ to disntinguish pre and post increment, 
	//prefix returns byref
	CFraction& operator++(); //pre increment
	//postfix returns byval 
	CFraction operator++(int notUsed);//post increment, matches the call behind scenes a.operator++(0)
	//global member function example: - when its global function pass in both object
	//friend CFraction & operator++(CFraction & lhs); 
	//friend CFraction operator++(CFraction & lhs, int notUsed);

	//overloading new[] - the new[] and delete need space for "operator new[]" or "operator free[]"
	//returns void* like malloc/alloc 
	void *operator new[](size_t size);

	//Equality - like compareTo -- overload as a datamember
	bool operator == (const CFraction & rhs); //overload as data member -- //member function version always gets called before global function, so to MANUALLY call this one - call override as if(operator==(a,b))
	bool operator != (const CFraction & rhs); //overload as data member -- //member function version always gets called before global function 
	//Equality - like Comparator -- overload as non-member global function, requires getters/setters or "friend"
	friend bool operator == (const CFraction & lhs, const CFraction & rhs); //overload as GLOBAL non-data member, default call is to the member data member

	//Output stream, allows chaining
	friend ostream & operator<<(ostream & out, const CFraction & rhs); //const would not allow change val in class	
	//Input stream
	friend istream & operator>>(istream &in, CFraction &rhs);

private:
	int *m_num;
	int *m_den;
	int m_id;
	static int next_ID;
};

