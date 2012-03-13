#pragma once //

#ifndef HOURLY_H
#define HOURLY_H
#endif //

#include "employee.h"
class HourlyWorker 
	: public Employee //
{
private:
	double wages, hours; //
	void Print(ostream& out); //

public:
	HourlyWorker(string f="hourly", string l="worker",
		double wages=8.55, double hours=0.0);
	~HourlyWorker();

	inline double getEarnings() {return wages*hours;} //
	friend ostream& operator<<(ostream& out, HourlyWorker& rhs); //
	virtual Employee& operator=(const Employee& rhs); //
	HourlyWorker& operator=(const HourlyWorker& rhs); //
};

