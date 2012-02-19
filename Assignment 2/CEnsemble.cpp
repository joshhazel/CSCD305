#pragma once

//#include "main.h"
#include "CTicket.h"
#include "CClassical.h"
#include "CEnsemble.h"

#define DEBUG

CEnsemble::CEnsemble(ifstream & in) : CClassical(in) //CTicket(in)
{
	//Get Ensemble name
	getline(in,this->name);

#ifdef DEBUG
	cout<<"CEnsemble constructor: " << this->name << endl;
#endif
}


CEnsemble::~CEnsemble(void)
{
#ifdef DEBUG
	cout<<"CEnsemble DESTRUCTOR: " << this->name << endl;
#endif
}

void CEnsemble::Print(ostream& out)//const
{
	CTicket::Print(out);		//Print Ticket #, time, date -- from CTicket
	out << this->name;			//Print ensemble name playing
}