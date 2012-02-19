#pragma once

#include "CTicket.h"
#include "CPops.h"

#define DEBUG

CPops::CPops(ifstream & in) : CTicket(in) // CTicket(in) 
{
	//Get Count number of groups playing
	int count;
	in>>count;

	//Get junk line
	string line;
	getline(in,line);

	//Get 1st band
	getline(in,line);
	this->groups.append(line);

	//Loop through lines get groups
	for(int i = 0; i < count-1; i++)
	{
		getline(in,line);
		//this->groups.append("\n\t"+line);
		this->additionalGroups.append(line);
	}

	//Get junk line
	getline(in,line);
		
#ifdef DEBUG
	cout<<"CPops constructor: ";// <<endl ;
	//cout<<"junk";//<<endl;
	cout<< this->groups;
	cout << endl;
#endif
}


CPops::~CPops(void)
{
#ifdef DEBUG
	cout<<"CPops DESTRUCTOR: ";// <<endl;
	//cout<<"junk"<<endl;
	cout<< this->groups; //cant figure out why this wont print
	cout<< endl;
#endif
}

void CPops::Print(ostream& out)//const
{
	CTicket::Print(out);		//Print Ticket #, time, date -- from CTicket
	out<<"Presenting:\n";
	out << "\t" << this->groups;		//Print groups playing
	out << "\t" << this->additionalGroups;
}