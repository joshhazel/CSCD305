#pragma once
class MyClass2
{
public:

	inline MyClass2(int x=0){this->val = x;}
	
	friend bool operator< (const MyClass2 & lhs, const MyClass2 & rhs){return lhs.val < rhs.val;}

	inline bool operator() (const MyClass2 & a, const MyClass2 &b) {return (a < b);}

	friend ostream & operator<<(ostream & out, const MyClass2 & rhs){out << rhs.val; return out;}
private:
	int val;
};



