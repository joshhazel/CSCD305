#include "Customer.h"

/*
const double PIG_1_PRICE = 0.012;
const double PIG_2_PRICE = 0.009;
const double PIG_3_PRICE = 0.015;
*/

Customer::Customer() {}
Customer::~Customer() {}
/*Customer::Customer(int mixNumber, int pig1, int pig2, int pig3, int custNumber, string name)
{
	this->mixNumber=mixNumber;
	this->pig1 = pig1;
	this->pig2 = pig2;
	this->pig3 = pig3;
	this->name = name;
}*/
Customer::Customer(const Customer& orig)
{
	this->name = orig.name;
	this->custNumber = orig.custNumber;
	this->orders = orig.orders;
}
Customer& Customer::operator=(const Customer& rhs)
{
	if(this != &rhs)
	{
		this->name = rhs.name;
		this->custNumber = rhs.custNumber;
		this->orders = rhs.orders;
	}
	return *this;
}
bool Customer::operator==(const Customer& rhs)
{
	if(this->custNumber == rhs.custNumber)
		return true;
	return false;
}
bool Customer::operator<(const Customer& rhs)
{
	return false;
}
ostream& operator<<(ostream& out, const Customer& rhs)
{
	for(int i = 0; i < rhs.orders.size(); i++)
	{
		out	<<	rhs.orders.at(i).mixNumber << "\t" 
			<<	rhs.name << "\t" 
			<<	rhs.orders.at(i).pig1 << "\t" 
			<<	rhs.orders.at(i).pig2 << "\t" 
			<<	rhs.orders.at(i).pig3 << "\t" 
			<<	rhs.orders.at(i).getFee() << "\t" 
			<< endl;
	}		
	return out;
}
istream& operator>>(istream& in, Customer& rhs)
{
	Order temp(1,2,3,4);
	in >> temp.mixNumber;
	in >> temp.pig1;
	in >> temp.pig2;
	in >> temp.pig3;

	rhs.orders.push_back(temp);
	in >> rhs.custNumber;
	getline(in,rhs.name);
	return in;
}

//double Customer::getFee()const
//{
//	double fee = 1.00; //flat fee
//	fee =	//charge per gallon for each pigment
//			(this->pig1 * PIG_1_PRICE)
//		+	(this->pig2 * PIG_2_PRICE)
//		+	(this->pig3 * PIG_3_PRICE);
//
//	return fee;
//}
int Customer::getCustNumber()const
{
	return this->custNumber;
}