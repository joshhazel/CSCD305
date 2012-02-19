#pragma once

//#include "main.h"
#include "CTicket.h"
#include "CClassical.h"

class CRecital : public CClassical //CTicket
{

public:
	CRecital(ifstream & in);
	virtual ~CRecital(void);

	void Print(ostream& out);//const;
//	friend ostream & operator <<(ostream & Out, const Time & T);


private:
	//char* soloist;
	//char* accompanist;
	string soloist;
	string accompanist;
};

