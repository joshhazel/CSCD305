/*
Joshua Hazel
CSCD305 C++
Lab 4 Inheritance
*/

#include "Student.h"
#include "main.h"

CStudent::CStudent(string s, int i, int cr) : PER_CREDIT(123.45) {
	this->name = s;
	this->id = i;
	this->credits = cr;
}//end constructor

CStudent::CStudent(const CStudent & orig) : PER_CREDIT(123.45) {
	this->name = orig.name;
	this->id = orig.id;
	this->credits = orig.credits;
}//end copy constructor

CStudent::~CStudent() {

}//end destructor

string CStudent::getName()const {
	return this->name;
}//end getName

int CStudent::getID()const {
	return this->id;
}//end getID

int CStudent::getCredits()const {
	return this->credits;
}//end getCredits
	
void CStudent::setName(string s) {
	this->name = s;
}//end setNam	e

void CStudent::setID(int i) {
	this->id = i;
}//end setID

void CStudent::setCredits(int cr) {
	this->credits = cr;
}//end setCredits
	
CStudent & CStudent::operator=(const CStudent & rhs) {
	this->credits = rhs.getCredits();
	this->id = rhs.id;
	this->name = rhs.name;

	return *this;
}//end = overload

double CStudent::calcFees()const {
	return this->credits * this->PER_CREDIT;
}//end calcFees

void CStudent::print(ostream & out)const {
	out<<"Name: "<<this->name<<"\nID: "<<this->id<<"\nCredits: "<<this->credits<<endl;		
}//end print

ostream & operator<<(ostream & out, const CStudent& rhs){
	out<<"Name: "<< rhs.name<< "\nID: " << rhs.id << "\nCredits: " << rhs.credits <<endl;
	return out;
}//end ostream overload
