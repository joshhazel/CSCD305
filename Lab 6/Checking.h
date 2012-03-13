#pragma once

#include "Account.h"

class Checking : public Account
{
public:
	Checking();
	~Checking();
	Checking(const Checking & orig);
	Checking & operator=(const Checking & rhs);

	void withdraw();

private:

};