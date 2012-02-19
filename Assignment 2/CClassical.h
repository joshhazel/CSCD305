#pragma once
#include "CTicket.h"

class CClassical : public CTicket
{
public:
	CClassical(ifstream & in);// : CTicket(in);
	virtual ~CClassical(void);
};