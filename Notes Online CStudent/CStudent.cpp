#include "CStudent.h"

int CStudent::next_id=0;

CStudent::CStudent(string s, int id):ACONST(next_id++)
{
	this->m_name = s;
	this->m_id = id;
	
}// end

CStudent::~CStudent()
{


}// end destructor


ostream & operator<<(ostream & out, const CStudent & rhs)
{

	out << "Name: " << rhs.m_name << endl;
	out << "ID: " << rhs.m_id << endl;
	return out;
}

istream & operator>>(istream & in, CStudent & rhs)
{
	cout << "Please enter a name ";
	getline(in, rhs.m_name);

	cout << "Please enter an id ";
	in >> rhs.m_id;
	return in;


}






