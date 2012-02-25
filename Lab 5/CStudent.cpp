#include "CStudent.h"

CStudent::CStudent()
{
	//do diddly junk
}
CStudent::CStudent(string name, int id, string color)
{
	this->name.first = name.substr(0, name.find(", "));
	this->name.second = name.substr(name.find(", "), name.length());
//cout<<this->name.first<<" "<<this->name.second<<endl;
	this->id = id;
	this->color = color;
}


CStudent::~CStudent(void)
{
}

CStudent & CStudent::operator=(const CStudent & rhs)
{
	if(this != &rhs) //use this make sure you dont create a Carray C, then do C=C
	{
		this->name = rhs.name;
		this->id = rhs.id;
		this->color = rhs.color;
	}
	return *this;
}

bool CStudent::operator<(const CStudent & rhs)const
{
	if(this->name.second.compare(rhs.name.second) < 0 )
		return true;
	else if(this->name.second.compare(rhs.name.second) == 0)
	{
		if(this->name.first.compare(rhs.name.first) < 0 )
			return true;
		else if(this->id < rhs.id)
			return true;
	}
	return false;
}

ostream &operator<<(ostream & out, const CStudent & rhs)
{
	out << "Name: " << rhs.name.first << " "
		<< rhs.name.second << endl
		<< "ID: " << rhs.id << endl
		<< "Color: " << rhs.color << endl << endl;

	return out;
}

 istream & operator>>(istream & fin, CStudent & rhs)
 {
	string name;
	string color;
	int id;
	
	getline(fin, name); //get lname, fname
	fin >> id; //get id
	getline(fin,color);
	getline(fin,color); //get color

	return fin;
 }