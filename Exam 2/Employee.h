#pragma once //
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Employee
{
private:
	string first, last;
	virtual void Print(ostream& out) = 0; // = 0 makes it pure virtual

public:
	Employee(string f="???", string l ="???") {first = f; last = l;};
	//NOTE: only place function prototypes for functions you know you must
	// have based on the driver file.  No copy constructor is required
	~Employee();

	virtual inline double getEarnings()=0; //
	inline string getFName() const {return first;}  inline string getLName() const {return last;} //
	inline void setFName(string f) {first=f;}  inline void setLName(string l) {last=l;} //
	virtual Employee & operator=(const Employee& rhs); //
	friend ostream& operator<<(ostream& out, Employee& rhs); //
}; //end class Employee

