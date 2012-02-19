#include "CFraction.h"



CFraction::CFraction(int num, int den)
{
	this->m_num = new int;
	*(m_num) = num;
	this->m_den = new int;
	*m_den = den;
}



CFraction::~CFraction(void)
{
	if(this->m_den != NULL)
	{
		delete this->m_den;
		this->m_den = NULL;

	}

	if(this->m_num != NULL)
	{
		delete this->m_num;
		this->m_num = NULL;
	}
}


CFraction & CFraction::operator=(const CFraction & rhs)
{
	if(this != &rhs)
	{
		if(this->m_den != NULL)
		{
			delete this->m_den;
			this->m_den = NULL;

		}

		if(this->m_num != NULL)
		{
			delete this->m_num;
			this->m_num = NULL;
		}

		this->m_den = new int;
		this->m_num = new int;

		*this->m_den = *rhs.m_den;
		*this->m_num = *rhs.m_num;

	}// end if

	return *this;
}// end operator=

CFraction::CFraction(const CFraction & orig)
{
	this->m_num = new int;
	*(m_num) = *orig.m_num;
	this->m_den = new int;
	*m_den = *orig.m_den;
	
}// end copy constructor

bool CFraction::operator==(const CFraction & rhs)
{
	return *this->m_num == *rhs.m_num && *this->m_den == *rhs.m_den;
}

bool CFraction::operator!=(const CFraction & rhs)
{
	return !(*this == rhs);
}

bool operator==(const CFraction & lhs, const CFraction & rhs)
{
	return *lhs.m_num == *rhs.m_num && *lhs.m_den == *rhs.m_den;
}

ostream & operator<< (ostream & out, const CFraction & rhs)
{

	out << *rhs.m_num << "/" << *rhs.m_den;
	return out;

}// end operator<<

istream & operator>> (istream & in, CFraction & rhs)
{
	cout << "Please enter a numerator " ;
	in >> *rhs.m_num;

	cout << "Please enter a denominator ";
	in >> *rhs.m_den;

	return in;

}
