#pragma once

#include "main.h"

class CStudent
{
public:
	CStudent();
	explicit CStudent(string, int, string);
	~CStudent();
	friend bool operator<(const CStudent & rhs)const;
	CStudent& operator=(const CStudent & rhs);


	friend ostream & operator<<(ostream & out, const CStudent & rhs);
	friend istream & operator>>(ostream & in, CStudent & rhs);

private:
	pair<string,string> name;
	string color;
	int id;
};