#pragma once

#include "Account.h"

class Savings : public Account
{
public:
	Savings();
	~Savings();
	Savings(const Savings & orig);

	void withdraw();

private:

};