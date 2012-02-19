#pragma once

#include "CTicket.h"
#include "CClassical.h"

#define DEBUG

CClassical::CClassical(ifstream & in) : CTicket(in)
{
#ifdef DEBUG
	cout<<"CClassical constructor: "<< endl;
#endif
}


CClassical::~CClassical(void)
{
#ifdef DEBUG
	cout<<"CClassical DESTRUCTOR: " << endl;
#endif
}
