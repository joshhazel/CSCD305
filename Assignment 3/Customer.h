/*
need order class
customer may have multiple order, store in vector
*/
#pragma once
#include "main.h"

//#include "Order.h"

class Customer
{
public:
	Customer();
	Customer(int,int,int,int,int,string);
	~Customer();

	Customer(const Customer& orig);
	Customer& operator=(const Customer& rhs);
	bool operator==(const Customer& rhs);
	bool operator<(const Customer& rhs);
	bool operator()(const Customer* lhs, const Customer* rhs);

	friend ostream& operator<<(ostream& out, const Customer& rhs);
	friend istream& operator>>(istream& in, Customer& rhs);

	double getFee()const;
	int getCustNumber()const;
	void setPig1(int value);
	void setPig2(int value);
	void setPig3(int value);

private:
	int mixNumber; //unique to each special order
	int pig1,pig2,pig3; //Number of units of pigment used for three different pigments
	int custNumber; //Customer number
	string name; //Customer name
	//vector<Order> orders;
};

