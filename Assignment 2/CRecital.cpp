#pragma once

#include "CTicket.h"
#include "CRecital.h"
#include "CClassical.h"

#define DEBUG

CRecital::CRecital(ifstream & in) : CClassical(in) //CTicket(in)
{
	//Get soloist/first artist
	getline(in,this->soloist);

	//Get junk line
	string temp;
	getline(in,temp);
	
	//Get additional artist
	getline(in,temp);

	//Check if there is additional artist and append
	if(temp.length() > 1)
	{
		this->accompanist = temp;
	}

#ifdef DEBUG
	cout<<"CRecital constructor: " << this->soloist << endl;
#endif
}

CRecital::~CRecital(void)
{
#ifdef DEBUG
	cout<<"CRecital DESTRUCTOR: " << this->soloist << endl;
#endif
}

void CRecital::Print(ostream& out)//const
{
	CTicket::Print(out);		//Print Ticket #, time, date -- from CTicket
	out << "Recital by ";
	out << this->soloist;		//Print soloist 
	if(this->accompanist.length() > 1)
	{
		out << "\tAccompanied by ";
		out << this->accompanist;	//Print accompanist
	}
}