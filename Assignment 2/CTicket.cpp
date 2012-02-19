#pragma once

//#include "main.h"
#include "CTicket.h"

#define DEBUG

int CTicket::m_NextNumber = 0;

CTicket::CTicket(ifstream & in):m_ticketNumber(CTicket::m_NextNumber++)
{	
	char c;
	int num1,num2,num3;

	//Initialize Date, Time
	this->date = Date();
	this->time = Time();

	//Get Date
	in >> num1;
	in>>c;
	in >> num2;
	in>>c;
	in >> num3;

	//Set Date
	this->date.setDate( num1,num2,num3);

	//Get Time
	in >> num1;
	in >> c;
	in >> num2;

	//Set Time
	this->time.setTime( num1,num2,0 );
	
	string temp;
	getline(in,temp);

	//Set Location
	getline(in,this->location);

#ifdef DEBUG
	//Get Location
	cout<<endl<<"CTicket constructor: ";
	cout<< this->date << " "	//Print Date - Time 
		<< ( ( this->time.getHour() == 0 || this->time.getHour() == 12 ) ? 12 : this->time.getHour() % 12 )
        << ":" << ( this->time.getMinute() < 10 ? "0" : "" ) << this->time.getMinute()
        << ( this->time.getHour() < 12 ? " AM" : " PM" ) << endl;
#endif
}

CTicket::~CTicket(void)
{
#ifdef DEBUG
	cout <<"CTicket DESTRUCTOR: ";
    cout << this->date << " " 
		<< ( ( this->time.getHour() == 0 || this->time.getHour() == 12 ) ? 12 : this->time.getHour() % 12 )
        << ":" << ( this->time.getMinute() < 10 ? "0" : "" ) << this->time.getMinute()
        << ( this->time.getHour() < 12 ? " AM" : " PM" );
#endif
}

void CTicket::Print(ostream& out)//const
{
	out << "Ticket No. " << this->m_ticketNumber << endl;	//Print ticket #
    out << ( ( this->time.getHour() == 0 || this->time.getHour() == 12 ) ? 12 : this->time.getHour() % 12 )
        << ":" << ( this->time.getMinute() < 10 ? "0" : "" ) << this->time.getMinute()
        << ( this->time.getHour() < 12 ? " AM" : " PM" );	//Print Time 
	out << " "<< this->date << endl							//Print Date
		<< this->location << endl;					//Print location
}

ostream & operator <<(ostream & out, Time & T)
{
   out << ( ( T.getHour() == 0 || T.getHour() == 12 ) ? 12 : T.getHour() % 12 )
        << ":" << ( T.getMinute() < 10 ? "0" : "" ) << T.getMinute()
        << ( T.getHour() < 12 ? " AM" : " PM" );
   return out;
}