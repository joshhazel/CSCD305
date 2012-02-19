#pragma once

//#include "main.h"
#include "CTicket.h"

class CPops : public CTicket
{

public:
	CPops(ifstream & in);
	virtual ~CPops(void);

	void Print(ostream& out);//const;

private:
	string groups;
	string additionalGroups;

};

