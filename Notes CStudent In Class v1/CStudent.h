#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class CStudent
{
//Anything declared here before public/private defaults to private

public: //everything is public until you say otherwise
//	CStudent(); //always have constructor
//	CStudent(string s = "Stu Steiner"); //Specify default value
	
	CStudent(string s = "Stu Steiner", int id = 12); //Specify default value
	~CStudent(); //always have a destructor
	inline string getName()const{return this->m_name;} // "const" allows not to have to declare const in multiple locations, requires "inline"
	inline int getID()const{return this->main_id;}
	inline void setID(int i){m_id = i;}
	inline void setName(string s){m_name = s;}

	//string getName()const; //const specifies type //alternate requires "const" in .h and .cpp file
	//const int getID()const; //the const at beginning means it cannot be changed
	
	//friend allows you to put header/prototype INSIDE a class, need const for CStudent DO NOT CHANGE CStudent
	friend ostream & operator<<(ostream & out, const CStudent & rhs);
	//should NOT be a const on istream or CStudent
	friend istream * operator>>(istream & in, CStudent & rhs);

	
private: //everything is private until you say otherwise
	string m_name;
	
	//const cannot be initialized in header file
	//cont inside of a class means cannot be changed in class, it is instance variable
	const int m_id; 
	
	//incremental value
	static int next_id; //is class level variable not instance therefore does not have m_next_id;
};

/*output 
Takes a reference to a CStudent and should return a REFERENCE to an ostream operator
gives ability to chain (ie cout << "this" << "and" << "this";
need to put const somewhere:  before CStudent, you are outputing values from CStudent NOT CHANGING THEM!
the ostream "&" is so you get a REFERENCE of the CURRENT object not create a new one*/
ostream & operator<<(ostream & out, const CStudent & rhs);

void swapByVal(CStudent one, CStudent tow);
void swapByVal(CStudent *a, CStudent *b);
void swapByRef(CStudent &a, CStudent &b); //pass by reference passes the contents so it changes the object
