#include "Customer.h"
#include <sstream>
#include "knihtclinput.h"

using namespace kniht;

const double PIG_1_PRICE = 0.012;
const double PIG_2_PRICE = 0.009;
const double PIG_3_PRICE = 0.015;

Customer::Customer() {}
Customer::~Customer() {}
Customer::Customer(int mixNumber, int pig1, int pig2, int pig3, int custNumber, string name)
{
	this->mixNumber=mixNumber;
	this->pig1 = pig1;
	this->pig2 = pig2;
	this->pig3 = pig3;
	this->name = name;
}
Customer::Customer(const Customer& orig)
{
	this->mixNumber = orig.mixNumber;
	this->pig1 = orig.pig1;
	this->pig2 = orig.pig2;
	this->pig3 = orig.pig3;
	this->name = orig.name;
}
Customer& Customer::operator=(const Customer& rhs)
{
	if(this != &rhs)
	{
		this->mixNumber = rhs.mixNumber;
		this->pig1 = rhs.pig1;
		this->pig2 = rhs.pig2;
		this->pig3 = rhs.pig3;
		this->name = rhs.name;
	}
	return *this;
}
bool Customer::operator==(const Customer& rhs)
{
	if(this->custNumber == rhs.custNumber)
		return true;
	return false;
}
istream& operator>>(istream& in, Customer& rhs)
{
	string str;
	string temp;

	in >> str;
	if(stringstream(str) >> rhs.mixNumber)
	{
		if(rhs.mixNumber <= 0)
		{
			getline(in,temp);
			throw "Invalid Mix Number: " + str;
		}
	}
	else
	{
		getline(in,temp);
		throw "Invalid Mix Number: " + str;
	}

	in >> str;
	if(stringstream(str) >> rhs.pig1)
	{
		if(rhs.pig1 < 0)
		{
			getline(in,temp);
			throw "Invalid Pigment Value: " + str;
		}
	}
	else
	{
		string temp;
		getline(in,temp);
		throw "Invalid Pigment Value: " + str;
	}

	in >> str;
	if(stringstream(str) >> rhs.pig2)
	{
		if(rhs.pig2 < 0)
		{
			getline(in,temp);
			throw "Invalid Pigment Value: " + str;
		}
	}
	else
	{
		string temp;
		getline(in,temp);
		throw "Invalid Pigment Value: " + str;
	}

	in >> str;
	if(stringstream(str) >> rhs.pig3)
	{
		if(rhs.pig3 < 0)
		{
			getline(in,temp);
			throw "Invalid Pigment Value: " + str;
		}
	}
	else
	{
		string temp;
		getline(in,temp);
		throw "Invalid Pigment Value: " + str;
	}

	in >> str;
	if(stringstream(str) >> rhs.custNumber)
	{
		if(rhs.custNumber <= 0)
		{
			getline(in,temp);
			throw "Invalid Customer Value: " + str;
		}
	}
	else
	{
		string temp;
		getline(in,temp);
		throw "Invalid Customer Value: " + str;
	}

	getline(in,rhs.name);

	return in;
}

double Customer::getFee()const
{
	double fee = 1.00; //flat fee
	fee +=	//charge per gallon for each pigment
			(this->pig1 * PIG_1_PRICE)
		+	(this->pig2 * PIG_2_PRICE)
		+	(this->pig3 * PIG_3_PRICE);

	return fee;
}
int Customer::getCustNumber()const
{
	return this->custNumber;
}
void Customer::setPig1(int value)
{
	this->pig1 = value;
}
void Customer::setPig2(int value)
{
	this->pig2 = value;
}
void Customer::setPig3(int value)
{
	this->pig3 = value;
}
bool Customer::operator()(const Customer* lhs, const Customer* rhs)
{
	//sort by cust number, then by mixture number
	if( (lhs->name < rhs->name) || ((lhs->name == rhs->name) && lhs->mixNumber < rhs->mixNumber))
		return true;
	return false;
}
bool Customer::operator<(const Customer& rhs)
{	
	if(this->getFee() < rhs.getFee())
		{	return true;}
	else if( this->getFee() == rhs.getFee() )
	{
		if(this->name < rhs.name)
		{ return true; }
		else
		{
			if(this->mixNumber < rhs.mixNumber)
			{ return true; }
		}
	}
	return false;
}

ostream& operator<<(ostream& out, const Customer& rhs)
{	out		<< setw(9) << rhs.mixNumber 
			<< setw(26) << left << rhs.name
			<< setw(6) << rhs.pig1
			<< setw(6) << rhs.pig2
			<< setw(6) << rhs.pig3
			<< setw(6) << setprecision(2) << fixed << rhs.getFee()
			<< endl;
	return out;
}