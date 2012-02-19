#include "CStudent.h"

//Starting value of student
int CStudent::next_id = 123456;
//:m_id(CStudent::next_id++) //The :m_id(CStudent::next_id++) is used to set initial value of next_id when it is a CONST (separate each with a comma)
//friend ostream & operator<<(ostream & out, const CStudent & rhs)
//friend allows you to put header/prototype INSIDE a class so you can call rhs rather than rhs.getName()

//Constructor for Student
CStudent::CStudent() //Regular creation
CStudent::CStudent():m_id(CStudent::next_id++) //The :m_id(CStudent::next_id++) is used to set initial value of next_id when it is a CONST (separate each with a comma)
{
	this->m_name = "Stu Steiner"; //This is a pointer
	//this->m_id = next_id++;  //Cannot be done this way since next_id is CONST
}//end

//Deconstructor for Student
CStudent::~CStudent() //Empty Constructor
{

}

ostream & operator<<(ostream & out, const CStudent & rhs)
{
	out << "Name: " << rhs.getName() << endl;
	out << "ID: " << rhs.getID() << endl;
	return out;
}

//istream & gives you chaining 
istream & operator>>(istream & in, CStudent & rhs)
{
	cout << "Please enter a name ";
	//bad:	//in >> rhs.m_name >> rhs.m_id;  	//use:
	getline(in, rhs.m_name);

	cout << "Please enter a name ";
	//bad:	//in >> rhs.m_name >> rhs.m_id;  	//use:
	in >> rhs.m_id;
	return in;
}




//Creates a copy of one and two, and is just local to the method so it doesnt change permanent
void swapByVal(CStudent one, CStudent two)
{
	CStudent temp(one); //calling "copy constructor", will call a "shallow copy"
	one = two;
	two = temp;
}
void swapInts(int *a, int *b) //same as swapByVal
{
	int *temp = a;
	a=b;
	b = temp;
}
void swapByPointer(CStudent *a, CStudent *b) //same as swapByVal
{
	CStudent *temp = a;
	a - b;
	b=temp;
}
void swapByRef(CStudent &a, CStudent &b) //pass by reference passes the contents so it changes the object
{
	CStudent temp(a);
	a=b;
	b=temp;
}


//The most important new thing in this code is the operator of scope (::, two colons) included in the definition of set_values(). 
//It is used to define a member of a class from outside the class definition itself.
string CStudent::getName()
	{return this->m_name;}

string Cstudent::getName()const
{
	return this->m_name;
}

const int CStudent::getID()const //const at beginning means return cannot be changed, the last const at the end means cannot change member values
{
	return this->m_id;
}
