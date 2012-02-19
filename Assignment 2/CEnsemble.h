#pragma once

//#include "main.h"
#include "CTicket.h"
#include "CClassical.h"

class CEnsemble : public CClassical //public CTicket
{

public:
	CEnsemble(ifstream & in);
	virtual ~CEnsemble(void);

	void Print(ostream& out);//const;
//	friend ostream & operator <<(ostream & Out, const Time & T);


private:
	//char* name;
	string name;
};

