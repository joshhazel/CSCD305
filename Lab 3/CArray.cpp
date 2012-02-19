#include "CArray.h"
#include "cscd305_w12_lab3.h"

CArray::CArray()
{
	this->m_array = new int[10];
	this->m_arrayBool = new bool[10];
	for(int i = 0; i < 10; i++)
	{
		this->m_arrayBool[i] = false;	
//		this->m_array[i] = i;
	}
	this->m_size = 10;
}

CArray::CArray(int size)
{
	this->m_array = new int[size];
	this->m_arrayBool = new bool[size];
	for(int i = 0; i < size; i++)
	{
		this->m_arrayBool[i] = false;	
		//this->m_array[i] = 0;
	}
	this->m_size = size;
}

CArray::~CArray(void)
{
	delete[] this->m_array;
	delete[] this->m_arrayBool;

}

/*int CArray::getSize()
{
	return this->m_size;
}*/ //Alternative get method

/*___________________________
	Overload Methods
  ___________________________*/
ostream& operator <<(ostream &out, const CArray &rhs) 
{	
	out << "[";
	for(int i = 0; i < rhs.m_size-1; i++)
	{
		if(rhs.m_arrayBool[i] == false)
			out << "null";
		else
			out << rhs.m_array[i];
		out << ", ";
	}
	if(rhs.m_arrayBool[rhs.m_size-1] == true)
		out << rhs.m_array[rhs.m_size-1];
	else
		out << "null";
	out << "]" << endl;
	return out;
}
istream& operator>>(istream& in, CArray & rhs)
{
	for(int i = 0; i < rhs.getSize(); i++)
	{
		in >> rhs.m_array[i];
		rhs.m_arrayBool[i] = true;
	}
	//how to get rid of extra junk?  maybe 18th number etc?
	return in;
}

//Regular operators
//!=
bool CArray::operator != (const CArray & rhs)
{
	return !(*this == rhs);
}
//==
bool CArray::operator == (const CArray & rhs)
{
	if(this->m_size == rhs.m_size)
	{
		for(int i = 0; i < this->m_size; i++)
		{
			if(this->m_array[i] != rhs.m_array[i])
			{
				return false;
			}
		}
		return true;
	}
	else
		return false;
}

CArray &CArray::operator=(const CArray & rhs)
{
	if(this != &rhs) //use this make sure you dont create a Carray C, then do C=C
	{
		if(this->m_array != NULL)
			delete this->m_array;
		if(this->m_arrayBool != NULL)
			delete this->m_arrayBool;

		this->m_size = rhs.m_size;
		this->m_array = new int[rhs.m_size];
		this->m_arrayBool = new bool[rhs.m_size];

		for(int i = 0; i < rhs.m_size; i++)
		{
			this->m_array[i] = rhs.m_array[i];
			this->m_arrayBool[i] = rhs.m_arrayBool[i];
		}
	}
	return *this;
}
//Copy constructor
CArray::CArray(const CArray & orig) 
{
	this->m_size = orig.m_size;

	this->m_array= new int[orig.m_size];
	//this->m_array = orig.m_array; //makes a pointer, this is wrong

	this->m_arrayBool= new bool[orig.m_size];
	//this->m_arrayBool = orig.m_arrayBool;//makes a pointer, this is wrong

	for(int i = 0; i < orig.m_size; i++)
	{
		this->m_array[i] = orig.m_array[i];
		this->m_arrayBool[i] = orig.m_arrayBool[i];
	}
}

int & CArray::operator[] (const int index) 
{
	if(index < 0 || index >= this->m_size)
		throw out_of_range("ERROR: subscript out of range");
	return this->m_array[index];
}
