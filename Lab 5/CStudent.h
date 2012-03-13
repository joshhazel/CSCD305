#pragma once

#include "main.h"

class CStudent
{
public:
	CStudent();
	explicit CStudent(string, int, string);
	~CStudent();
	bool operator<(const CStudent & rhs);
	CStudent& operator=(const CStudent & rhs);
	string getName();
	int getID();
	string getColor();
	string getFName();
	string getLName();



	friend ostream & operator<<(ostream & out, const CStudent & rhs);
	friend ifstream & operator>>(ifstream & fin, CStudent & rhs);

private:
	pair<string,string> name;
	string color;
	int id;
};