#include "CFraction.h"

int CFraction::next_ID = 10;

CFraction::CFraction(int num, int den):m_id(next_ID++)
{	
	//Used for pointers
	this->m_num=new int;	
	*this->m_num=num;		//same as *(m_num)=num;

	this->m_den=new int;	
	*this->m_den=den; //Same as *(m_den)=den;		
}


CFraction::~CFraction(void)
{	
//	cout<<"Im deleting "<< *this << endl;
	//* check if var are null before deleting   ---  both var are allocating memory
/*	if(this->m_den != NULL)
		delete this->m_den;	
	if(this->m_num != NULL)
		delete this->m_den;
	*/
}

ostream & operator<<(ostream & out, const CFraction & rhs) //const would not allow change val in class
{
	return out << *rhs.m_num << "/" << *rhs.m_den << " someConst: " << rhs.m_id;//* remove line
}//end output

//Return type is CFraction &
CFraction & CFraction::operator = (const CFraction & rhs)
{
	//"this" is a ptr and "rhs" is object, need to deref or & , typically &
	//If we dont do this change then it destroys contents of rhs obj !!
	if(this != &rhs) //use this make sure you dont create a fraction C, then do C=C
	{
		this->m_den=rhs.m_den;
		this->m_num=rhs.m_num;
			//C Version
		//*((int *)&someConst)=rhs.someConst 
			//C++ version
		//const_cast<int &>(someConst)=rhs.someConst;


	//Delete var
	/*	//* check if var are null before deleting   ---  both var are allocating memory
	if(this->m_den != NULL)
		delete this->m_den;	
	if(this->m_num != NULL)
		delete this->m_den

	//Assign ---this allows for d=b when 
	this->m_den - new int;
	this->m_num = new int;

	*this->m_den= *rhs.m_den
	*this->m_num= *rhs.m_num

	return *this;
	*/

		//}
	}

	//After copying must return deref ptr *this
	return *this;
}
 //Use as copy constructor
CFraction::CFraction(const CFraction & orig) 
{
	this->m_num = new int;
	*this->m_num = *orig.m_num;

	this->m_num=new int;
	*(m_num) = *orig.m_num;
}
