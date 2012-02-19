#include "CFraction.h"

int CFraction::next_ID = 10;

CFraction::CFraction(int num, int den):m_id(next_ID++)
{	
	//Used for pointers
	this->m_num=new int;	
	*this->m_num=num;		//same as *(m_num)=num;

	this->m_den=new int;	
	*this->m_den=den; //Same as *(m_den)=den;		
}


CFraction::~CFraction(void)
{	
//	cout<<"Im deleting "<< *this << endl;
	//* check if var are null before deleting   ---  both var are allocating memory
	if(this->m_den != NULL)
		delete this->m_den;	
	if(this->m_num != NULL)
		delete this->m_num;
	
}

CFraction CFraction::operator+(const CFraction & rhs)const
{	//Call constructor
	CFraction temp; //cannot call copy constructor because ur combining two
	temp.m_num = new int;
	temp.m_den = new int;
	*temp.m_num=*this->m_num * *rhs.m_den + *this->m_den * *rhs.m_num;
	*temp.m_den = *this->m_den * *rhs.m_den;
	return temp;
};
CFraction CFraction::operator-()//unary minus, negative 
{
		//call copy constructor
	CFraction temp = *this; 
	//negatate num and return
	*temp.m_num = -*temp.m_num;
	return temp;
}
CFraction & CFraction::operator+=(const CFraction & rhs)
{
	*this = *this + rhs;
	return *this;
}

//We can do prefix and postfix as data member functions (see global member function example)
//To distinguish them we have to pass in int(NotUsed) for postfix
CFraction & CFraction::operator++() //pre increment    //modifying by this, so need &
{
	*this->m_num += *this->m_den;
	return *this;
}
CFraction CFraction::operator++(int notUsed) //post increment
{
	CFraction temp(*this->m_num + *this->m_den, *this->m_den);
	return temp;
}

//Equals == like compareTo
bool CFraction::operator == (const CFraction & rhs) //overload as data member
{
	return *this->m_num == *rhs.m_num && *this->m_den == *rhs.m_den;
}
//Not Equals != 
bool CFraction::operator != (const CFraction & rhs) //overload as data member
{		//Cannot use (*this != rhs) because it would recursive call THIS method
	return !(*this == rhs); //use (*this != rhs) to call MY ==	
}

//Equals - This is like a Comparator in Java
bool operator==(const CFraction & lhs, const CFraction & rhs) //overload as non-member global function, requires getters/setters or "friend"
{
	return *lhs.m_num == *rhs.m_num && *lhs.m_den == *rhs.m_den;
}

ostream & operator<<(ostream & out, const CFraction & rhs) //const would not allow change val in class
{
	out << *rhs.m_num ;
	out << "/";
	out << *rhs.m_den;
	out << " someConst: ";
	out << rhs.m_id;//* remove line
	return out;
}//end output

istream & operator>>(istream & in, CFraction &rhs)
{
	cout <<"Please enter a numerator: " ;
	in >> *rhs.m_num;

	cout << "Please enter a denominator: ";
	in >> *rhs.m_den; 

	return in;
}
/*
//Global member function for ++, use like b++c; in main
CFraction & operator++(CFraction & lhs)
{
	*lhs.m_num += *lhs.m_den;
	return lhs;
}
CFraction operator++(CFraction & lhs, int notUsed)
{
	CFraction temp(*lhs.m_num + *rhs.m_den, *lhs.m_den);
	return temp
}
*/

//Return type is CFraction &
CFraction & CFraction::operator = (const CFraction & rhs)
{
	//"this" is a ptr and "rhs" is object, need to deref or & , typically &
	//If we dont do this change then it destroys contents of rhs obj !!
	if(this != &rhs) //use this make sure you dont create a fraction C, then do C=C
	{
		delete this->m_den;
		delete this->m_num;
		this->m_num = new int;
		this->m_den = new int;
		*this->m_den=*rhs.m_den;
		*this->m_num=*rhs.m_num;
			//C Version
		//*((int *)&someConst)=rhs.someConst 
			//C++ version
		//const_cast<int &>(someConst)=rhs.someConst;


	//Delete var
	/*	//* check if var are null before deleting   ---  both var are allocating memory
	if(this->m_den != NULL)
		delete this->m_den;	
	if(this->m_num != NULL)
		delete this->m_den

	//Assign ---this allows for d=b when 
	this->m_den - new int;
	this->m_num = new int;
	*this->m_den= *rhs.m_den
	*this->m_num= *rhs.m_num
	*/

		//}
	}

	//After copying must return deref ptr *this
	return *this;
}
 //Use as copy constructor
CFraction::CFraction(const CFraction & orig) 
{
	this->m_num = new int;
	*this->m_num = *orig.m_num;

	this->m_den=new int;
	*(m_den) = *orig.m_den;
}
