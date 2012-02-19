/*
Joshua Hazel
CSCD305 C++
Lab 4 Inheritance
*/

#include "Grad.h"
#include "main.h"

CGrad::CGrad(string s, int i, int cr, double fee) : CStudent(s,i,cr) 
{
	this->fee = fee;
}//end constructor

CGrad::CGrad(const CGrad & orig) {
	this->setName(orig.getName());
	this->setID(orig.getID());
	this->setCredits(orig.getCredits());
}//end copy constructor

CGrad::~CGrad() {

}//end destructor

double CGrad::calcFees()const {
	return CStudent::calcFees() + (CStudent::getCredits() * CGrad::fee);
}//end calcFees

void CGrad::print(ostream & out)const {
	CStudent::print(out);
	out<<"Fees: "<<this->calcFees()<<endl;
}//end print

CGrad & CGrad::operator=(const CGrad & rhs) {
	CStudent::operator=(rhs);
	this->fee = fee;

	return *this;
}//end = overload