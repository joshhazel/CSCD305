#pragma once;
#include "CStudent.h"

int main()
{
	//CStudent one;
	CStudent one("Stu Steiner", 43);
	CStudent two("Josh Hazel", 12);
	cout << "One: " << one.getName(); //<< " " << one.getID() << endl;
	cout << "Two: " << two.getName(); //<< " " << one.getID() << endl;
	
	swapByPoint(&one,&two);
	count << "One: " << one.getName(); //<< " " << one.getID() << endl;
	cout << "Two: " << two.getName(); //<< " " << one.getID() << endl;
	
	swapByRef(one,two);
	count << "One: " << one.getName(); //<< " " << one.getID() << endl;
	cout << "Two: " << two.getName(); //<< " " << one.getID() << endl;

	cout << one; //no perator found takes RH operand of type CStudent
}
