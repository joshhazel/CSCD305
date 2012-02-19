#pragma once
#include "customer.h"

//DVC Constructor (Question 7)
CCustomer::CCustomer():m_id(CCustomer::next_id++)
{
	name = "Joshua Hazel"; address = "123 Main Street"; city = "Spokane"; state = "WA"; zipcode = "99201";
	sales = 0; purchases = 0; credit_limit = 50000;
	//CCustomer("Joshua Hazel","123 Main Street","Spokane","WA","99201",50000);

}//end DVC

//EVC Constructor
CCustomer::CCustomer(string in_name, string in_address, string in_city, string in_state, string in_zipcode,int in_credit_limit):m_id(CCustomer::next_id++)
{
	name = in_name; address = in_address; city = in_city; state = in_state; zipcode = in_zipcode;
	sales = 0; purchases = 0; credit_limit = in_credit_limit;
}//end EVC

//Question 9 <like toString()>
	 ostream & operator<<(ostream & out, const CCustomer & rhs)
{
	out << "Name: " << rhs.get_name() << "\tID: " << rhs.get_id() << "\tCredit: $" << rhs.get_credit_limit() << endl << 
	"Address: " << rhs.get_address() << " " << rhs.get_city() << ", " << rhs.get_state() << " " << rhs.get_zipcode() << endl;
	return out;
}//end

/*//Question 6
bool checkAvailCredit(double purchase_price)
{
	if(purchase_price > get_credit_limit())
		return false
	return true;

}*/