#pragma once

#include <iostream>
#include <string>

using namespace std;

class CStudent
{
public:
	CStudent(string s = "Stu Steiner", int id = 12);
	~CStudent();
	inline string getName()const{return this->m_name;}
	inline int getID()const{return this->m_id;}
	inline void setID(int i){m_id = i;}
	inline void setName(string s){m_name = s;}

	friend ostream & operator<<(ostream & out, const CStudent & rhs);
	friend istream & operator>>(istream & in, CStudent & rhs);
	
private:
	string m_name;
	int m_id;
	static int next_id;
	const int ACONST;
};

