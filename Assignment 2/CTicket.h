#pragma once

#include "main.h"
#include "Date1.h"
#include "Time3.h"

class CTicket
{
static int m_NextNumber;

public:
	CTicket(ifstream & in);
	virtual ~CTicket(void);

	void Print(ostream& out);//const;
	friend ostream & operator <<(ostream & Out, const Time & T);

	static void SetNumber(int N) {m_NextNumber = N;}

private:
	const int m_ticketNumber;
	Date date;
	Time time;
	//char* location;
	string location;
};

