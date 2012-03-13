#pragma once
#include "Order.h"

const double PIG_1_PRICE = 0.012;
const double PIG_2_PRICE = 0.009;
const double PIG_3_PRICE = 0.015;

Order::Order() {}//this->mixNumber=0;this->pig1=0;}
Order::Order(int mixNumber, int pig1, int pig2, int pig3)
{
	this->mixNumber = mixNumber;
	this->pig1 = pig1;
	this->pig2 = pig2;
	this->pig3 = pig3;
}
Order::Order(const Order& orig)
{
	this->mixNumber = orig.mixNumber;
	this->pig1 = orig.pig1;
	this->pig2 = orig.pig2;
	this->pig3 = orig.pig3;
}
Order& Order::operator=(const Order& rhs)
{
	if(this != &rhs)
	{
		this->mixNumber = rhs.mixNumber;
		this->pig1 = rhs.pig1;
		this->pig2 = rhs.pig2;
		this->pig3 = rhs.pig3;
	}
	return *this;
}

Order::~Order()
{
}

ostream& operator<<(ostream& out, const Order& rhs)
{
	return out;
}

double Order::getFee()const
{
	double fee = 1.00; //flat fee
	fee =	//charge per gallon for each pigment
			(this->pig1 * PIG_1_PRICE)
		+	(this->pig2 * PIG_2_PRICE)
		+	(this->pig3 * PIG_3_PRICE);

	return fee;
}
