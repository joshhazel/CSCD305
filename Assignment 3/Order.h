#pragma once

#include "main.h"

class Order
{
public:
	Order();
	Order(int mixNumber, int pig1, int pig2, int pig3);
	Order(const Order& orig);
	Order& operator=(const Order& rhs);
	~Order();

	friend ostream& operator<<(ostream& out, const Order& rhs);
	
	double getFee()const;

	int mixNumber; //unique to each special order
	int pig1,pig2,pig3; //Number of units of pigment used for three different pigments
};

