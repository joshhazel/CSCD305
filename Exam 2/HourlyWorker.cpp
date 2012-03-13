#include "HourlyWorker.h"

HourlyWorker::HourlyWorker(string first, string last, double wages, double hours) //
	: Employee(first,last) //
{
	this->wages = wages; 
	this->hours = hours;
}
HourlyWorker::~HourlyWorker() {}

Employee& HourlyWorker::operator=(const Employee& rhs) //
{	
	const HourlyWorker* pHW = dynamic_cast<const HourlyWorker*>(&rhs);
	*this = *pHW;
	return *this;
}
HourlyWorker& HourlyWorker::operator=(const HourlyWorker& rhs) //
{
	if(this != &rhs) 
	{
		this->setFName(rhs.getFName());
		this->setLName(rhs.getLName());
		this->hours = rhs.hours;
		this->wages = rhs.wages;
	}
	return *this;
}

ostream& operator<<(ostream& out, HourlyWorker& rhs) //
{
	return out	<< "Hours Worked: " << rhs.hours << endl
				<< "Hourly Rate: $" << rhs.wages  << endl
				<< "Gross Pay: $" << rhs.getEarnings() << endl;

}

void HourlyWorker::Print(ostream& out) //
{
	out << *this; //call overloaded HourlyWorker << ostream
}