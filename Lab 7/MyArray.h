#pragma once

#include <iostream>
#include <string>
using namespace std;



/*
	You must write the constructor, destructor, copy constructor, 
	and getSize as inline functions

	You must write the assignment operator and plus operator as
	member functions just not inline.

	//+ operator returns byvalue not byref
	//MyArray<T> MyArray<T>::operator+(const(MyArray<T>& rhs)
*/
template <class T>
class MyArray
{
public:

	MyArray(int s = 5 ) { s<5 ? size=5:size=s; theArray = new T[size]; };
	MyArray(const MyArray& orig) { size=orig.size; theArray=orig.theArray; }
	~MyArray() { /*delete theArray;*/ };
	
	inline int getSize() { return size; }

	friend istream& operator>> <>(istream& in, MyArray<T>& rhs);
	friend ostream& operator<< <>(ostream& out, const MyArray<T>& rhs);

	//inline MyArray<T> operator+(const MyArray<T>& rhs); { MyArray<T> temp; return temp;}
	//inline MyArray<T> operator=(const MyArray<T>& rhs); { if(this != &rhs) { /*do_something*/ } return *this; }
	MyArray<T> operator+(const MyArray<T>& rhs); 
	MyArray<T>& operator=(const MyArray<T>& rhs); 

private:
	T * theArray;
	int size;
};

template <typename T>
istream& operator>> <>(istream& in, MyArray<T>& rhs)
{
	int i = 0;
	//while(!in.eof()) 
	while(i < rhs.size)
	{
		in >> rhs.theArray[i];
		i++;
	}
	return in;
}

template <typename T>
ostream& operator<< <>(ostream& out, const MyArray<T>& rhs)
{
		for(int i = 0; i < rhs.size; i++)
	{
		out << rhs.theArray[i];
	}
	return out;
}

template <typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& rhs)
{
	MyArray<T> temp( (this->size + rhs.size) );
	temp.theArray = new T[temp.size];
	int i = 0;
	for(; i < this->size; i++)
	{
		temp.theArray[i] = this->theArray[i];
	}
	for(int j = 0; j < rhs.size; j++)
	{
		temp.theArray[j+i] = rhs.theArray[j];
	}
//cout << temp;
	return temp;
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& rhs)
{
	if(this != &rhs)
	{
		this->size = rhs.size;
		if(this->theArray != NULL)
			delete this->theArray;
		this->theArray = new T[this->size];
		for(int i = 0; i < this->size; i++)
		{
			this->theArray[i] = rhs.theArray[i];
		}
	}
	return *this;
}