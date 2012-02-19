/*
Joshua Hazel
CSCD 305 C++
Stu Steiner

Part-B
Uses lab2PartBTester.cpp, lab2PartBImplement.cpp, Lab_2.h
*/
#ifndef CCUSTOMER
#define CCUSTOMER
#include "lab2b.h";

class CCustomer
{

//static int totalAllSales;

//incremental value
static int next_id; //is class level variable not instance therefore does not have m_next_id;

public:
	//Constructor header(s)
	CCustomer();
	CCustomer(string in_name, string in_address, string in_city, string in_state, string in_zipcode, int in_credit_limit);
	
	//Accessors <inline> Question 1
	inline string get_name()const{return this->name;}//string get_name();    
	inline string get_address()const{return this->address;}//string get_address();    
	inline string get_city()const{return this->city;}//string get_city();    
	inline string get_state()const{return this->state;}//string get_state();    
	inline string get_zipcode()const{return this->zipcode;}		//QUESTION 4
	inline double get_credit_limit()const{return this->credit_limit;}//double get_credit_limit(); 
	inline double get_sales()const{return this->sales;}//added
	inline int get_id()const{return this->m_id;}
	inline double get_balance(){return this->credit_limit - sales;}

	//Mutators
	inline void increase_limit(double amount){this->credit_limit += amount;}  
	inline void set_name(string in_name){this->name = in_name;}
	inline void set_address(string in_address){this->address = in_address;}
	inline void set_city(string in_city){this->city = in_city;}
	inline void set_state(string in_state){this->state = in_state;}
	inline void set_zipcode(string in_zipcode){this->zipcode = in_zipcode;}
	inline void set_credit_limit(double in_credit_limit){this->credit_limit = in_credit_limit;}
	inline void set_sales(double in_sales){this->sales = in_sales;}//Question 5-6
	inline void set_purchases(int in_purchases){this->purchases = in_purchases;}//Question 5-6

	//friend allow declare in class, use outside class
	friend  ostream & operator<<(ostream & out, const CCustomer & rhs);

	//Question 6
	inline bool make_purchase(double purchase_price) 
	{
		//Credit limit - Total Sales = Available Balance (compare to purchase price)
		if(purchase_price > this->get_balance() ) //(this->credit_limit - this->sales) ) 
			return false; 
		this->sales = this->sales + purchase_price;
		this->purchases++;
		return true;
	}
	//friend bool checkAvailCredit(double purchase_price);


private:    
	string name;    
	string address;
	string city;
	string state;
	string zipcode;
	double credit_limit; //Question 3
	double sales; //Question 5
	int purchases; //Question 5
	int m_id; 
		
};//Question 2

#endif