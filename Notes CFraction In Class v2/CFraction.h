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
	CFraction(const CFraction & orig);

	//Deconstructor
	~CFraction(void);

	//Create copy , const here not to change rhs, if you put const before ; it would not allow to change in function
	//want CFraction & operator, & to allow chaning 
	CFraction & operator = (const CFraction & rhs);

	//Constructor for cout usage and chaining
	friend ostream & operator<<(ostream & out, const CFraction & rhs); //const would not allow change val in class	

private:
	int *m_num;
	int *m_den;

	int m_id;

	static int next_ID;
};

