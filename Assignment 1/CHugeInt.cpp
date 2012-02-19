#include "CHugeInt.h"
#include "main.h"


CHugeInt::CHugeInt()
{
	this->setInt("100");
}
CHugeInt::CHugeInt(string input)
{
	this->setInt(input);
}//end EVC

void CHugeInt::setInt(string input)
{
	//User gives ONLY '-'
	if(input.length()==1 && input[0]=='-')
	{
		cout<<"\nInvalid input: -\n";
		return;
	}

	//Default neg value to false
	this->m_bNeg=false;

	//Reduce length to just numbers, ignore '-' and excess '0' from front of number ie... -01234 s/b length 4
	int len = input.length(); int x = 0;
		//If number is negative: length -1, negative bool = true 
		if(x == 0 && input[x]=='-')
		{
			this->m_bNeg=true;
			len--;
			x++;
		}
		//If first set of digits == 0: subtract them from length
		while(len != 1 && input[x]=='0')
		{
			len--;
			x++;
		}

	//Set member size to len
	this->m_size = len;

	//Create new member int array using len
//this->m_ints = new int[input.length()]
	this->m_ints = new int[len];

	//Loop through input, check 1st char for - neg, make sure each addl is numeric, assign to int array
		//i is for input string[], j for member m_array[]
	for( int i = input.size()-len, j = 0; i < input.size(); i++,j++)
	{	
		//isNegative: ignore it, handled already, unless there is a second one
		if(input[i]=='-'){
//			cout<<input[i]<<" is negative\n";
			if(this->m_bNeg=true)
				//NOT A DIGIT ERROR!!
				{cout<<input[i]<<" is not digit\n"; this->m_size=0;return;}
			j--;
			i--;
			continue;}
		else{
			//isDigit?
			if(!isdigit(input[i]))
				//NOT A DIGIT ERROR!!
				{cout<<input[i]<<" is not digit\n"; this->m_size=0;return;}
			//Subtract 48 off number because it is read in as char/string (ascii) and assign to array
			this->m_ints[j] = (input[i]-48);
//		cout<<"m_ints["<<j<<"] is: "<<m_ints[j]<<endl;
		}//end if
	}//end for

	//Remove negative from 0
	if(this->m_bNeg==true && this->m_ints[0]==0)
		this->m_bNeg=false;	
}
CHugeInt::~CHugeInt()
{
	//if(this->m_ints != NULL)
		//delete[] this->m_ints;
}
string CHugeInt::getInt()
{
	if(this->m_size==0)
		return "null";

	stringstream ss;
	string s;

	if(this->m_bNeg)
		ss<<"-";
	for(int i = 0; i < this->m_size; i++)
		ss<<this->m_ints[i];
	ss>>s;
	return s;
}

CHugeInt::CHugeInt(const CHugeInt &orig)
{
	//Copy values from orig to this
	this->m_bNeg=orig.m_bNeg;
	this->m_size=orig.m_size;

	this->m_ints = new int[orig.m_size];
	for(int i = 0; i < this->m_size; i++)
		this->m_ints[i] = orig.m_ints[i];
}//end copy Constructor
ostream& operator <<(ostream& out, const CHugeInt& rhs)
{

	if(rhs.m_size==0)
	{
		out<<"null";
	}
	else
	{
//		out<<"Size: "<<rhs.m_size<<"  Value: [";
		int i = 0;
		if(rhs.m_bNeg)
		{
			out << "-";
		}
		for(; i < rhs.m_size; i++)
		{
			out << rhs.m_ints[i];
//			if(i != rhs.m_size-1)
//				out<<",";
		}
//		out<<"]";
	}

	return out;
}
istream &operator>>(istream &in, CHugeInt &rhs)
{
	string temp;
	getline(in,temp);
	rhs.setInt(temp);

	return in;
}
CHugeInt &CHugeInt::operator = (const CHugeInt &rhs)
{
	//Copy values from orig to this
	this->m_bNeg=rhs.m_bNeg;
	this->m_size=rhs.m_size;

	this->m_ints = new int[rhs.m_size];
	for(int i = 0; i < this->m_size; i++)
		this->m_ints[i] = rhs.m_ints[i];

	return *this;
}
bool CHugeInt::operator == (const CHugeInt &rhs)
{
	if((this->m_size != rhs.m_size) || this->m_bNeg!=rhs.m_bNeg)
		return false;
	for(int i = 0; i < this->m_size; i++)
	{
		if(this->m_ints[i] != rhs.m_ints[i])
			return false;
	}
	return true;
}
bool CHugeInt::operator != (const CHugeInt &rhs)
{
	if(*this == rhs)
		return false;
	return true;
}
CHugeInt CHugeInt::operator+(const CHugeInt & rhs)
{	
	//Return 0 values (+ 0)
	if(rhs.m_size==1 && rhs.m_ints[0]==0)
		return *this; //rhs is 0, so return this
	if(this->m_size==1 && this->m_ints[0]==0)
		return rhs; //this is 0, so return rhs

	//Variables array sizes and remainder for carryover
	int smallArraySize, largeArraySize, remainder=0, divisor=0;
	CHugeInt ret; //return at end of method

	//Determine which array is larger, will use this to store values
	if(this->m_size >= rhs.m_size)
	{
		largeArraySize = this->m_size;
		smallArraySize = rhs.m_size;
		ret = *this; //*this is larger array
	}else if
		(this->m_size < rhs.m_size)
	{
		largeArraySize = rhs.m_size;
		smallArraySize = this->m_size;
		ret = rhs; //rhs is larger array
	}//end if


	//Set negative value
	if(this->m_bNeg == rhs.m_bNeg)
		ret.m_bNeg=rhs.m_bNeg; // set Neg value when equal
	else if(this->m_bNeg != rhs.m_bNeg)
	{ //If one is negative, other is positive, check see which is larger
		if( (this->m_bNeg == true && rhs.m_bNeg==false) ||
			(this->m_bNeg == false && rhs.m_bNeg==true) )
		{

bool boolReturnNegative = false;
if( this->m_bNeg==true && (this->m_size > rhs.m_size) )
	boolReturnNegative = true;
else if( rhs.m_bNeg==true && (this->m_size < rhs.m_size) )
	boolReturnNegative = true;
else if( this->m_size==rhs.m_size) //if( this->m_bNeg==true || rhs.m_bNeg==true )
{
	for(int i = this->m_size - 1; i >= 0; i++)
	{		//Larger and negative
		if( (this->m_ints[i] > rhs.m_ints[i] && this->m_bNeg == true) ||
			(this->m_ints[i] < rhs.m_ints[i] && rhs.m_bNeg == true) )
		{
			boolReturnNegative=true; //One of the # is negative and has larger value
			break;
		}
		//All numbers are same, one negative one positive results in 0 value
/*		ret.m_size=1;
		if(ret.m_ints != NULL)
			delete[] ret.m_ints;
		ret.m_ints = new int[1];
		ret.m_ints[0]=0;
		return ret;
*/
	}//end for

}

			CHugeInt temp;
			if(this->m_bNeg == true && rhs.m_bNeg==false)
			{
				//Need a temp be rhs is const
				temp = rhs; 
				this->m_bNeg=false;
				ret = *this-temp;
				ret.m_bNeg=true;
			}
			else //if(this->m_bNeg == false && rhs.m_bNeg==true)
			{
				temp = rhs; 
				temp.m_bNeg=false;
				ret = *this-temp;
			}
			if(boolReturnNegative==true)
				ret.m_bNeg=true;
			return ret;
		}
/*
		if(this->m_size > rhs.m_size)
		{ //*this is larger
			if(this->m_bNeg) 
				ret.m_bNeg=true; //larger value is negative
			else
				ret.m_bNeg=false; //larger value is positive
		}
		else if(this->m_size < rhs.m_size)
		{// rhs is larger
			if(rhs.m_bNeg)
				ret.m_bNeg=true; //larger value is negative
			else
				ret.m_bNeg=false; //larger value is positive
		}
		else //both numbers have same length
		{		//compare all digits until one is larger 
			for(int i = this->m_size - 1; i >= 0; i++)
			{		//Larger and negative
				if( (this->m_ints[i] > rhs.m_ints[i] && this->m_bNeg == true) ||
					(this->m_ints[i] < rhs.m_ints[i] && this->m_bNeg == true) )
				{
					ret.m_bNeg=true; //One of the # is negative and has larger value
					break;
				}
				//All numbers are same, one negative one positive results in 0 value
				ret.m_size=1;
				if(ret.m_ints != NULL)
					delete[] ret.m_ints;
				ret.m_ints = new int[1];
				ret.m_ints[0]=0;
				return ret;

			}//end for
		}//end if
*/
	}//end Negative value check

	//Create new array for ret
	if(ret.m_ints != NULL)
		delete[] ret.m_ints;
	ret.m_ints = new int[largeArraySize+1];
	ret.m_size = largeArraySize+1;

	//*THIS > RHS
	if(this->m_size > rhs.m_size)
	{	//Create extra space for carryover
		ret.m_ints[0]=0;
		for(int i = 1; i < ret.m_size; i++)
		{	//Set values to THIS
			ret.m_ints[i] = this->m_ints[i-1];
		}
		for(int i = ret.m_size-1, j=0; j<rhs.m_size; i--,j++)
		{	//Add in values from RHS
			ret.m_ints[i] += rhs.m_ints[rhs.m_size-1-j];
//cout<<"Add ret.int["<<i<<"]="<<ret.m_ints[i]<<endl;
		}

		for(int i = ret.m_size-1; i>0; i--)
		{	//Carryover math:
			if(ret.m_ints[i]>9)
			{
				ret.m_ints[i-1] += ret.m_ints[i]/10;
				ret.m_ints[i] = ret.m_ints[i]%10;
			}
//cout<<"Carry ret.int["<<i<<"]="<<ret.m_ints[i]<<endl;
		}

	}//end if THIS>RHS

	//THIS < RHS
	else if(this->m_size < rhs.m_size)
	{
		ret.m_ints[0]=0;
		for(int i = 1; i < ret.m_size; i++)
		{
			ret.m_ints[i] = rhs.m_ints[i-1];
		}

		for(int i = ret.m_size-1, j=this->m_size-1; j>=0; i--,j--)
		{
			ret.m_ints[i] += this->m_ints[j];
		}

		for(int i = ret.m_size-1; i>0; i--)
		{
			if(ret.m_ints[i]>9)
			{
				ret.m_ints[i-1] += ret.m_ints[i]/10;
				ret.m_ints[i] = ret.m_ints[i]%10;
			}
		}
	}//end if THIS<RHS

	//*THIS == RHS
	else if(this->m_size == rhs.m_size)
	{
		ret.m_ints[0]=0;
		for(int i = 1; i < ret.m_size; i++)
		{
			ret.m_ints[i] = this->m_ints[i-1];
		}
		for(int i = 1, j=0; i<ret.m_size; i++,j++)
		{
			ret.m_ints[i] += rhs.m_ints[j];
		}

		for(int i = ret.m_size-1; i>0; i--)
		{
			if(ret.m_ints[i]>9)
			{
				ret.m_ints[i-1] += ret.m_ints[i]/10;
				ret.m_ints[i] = ret.m_ints[i]%10;
			}
		}

	}//end if THIS>RHS

	//Get rid of extra 0 at beginning
	if(ret.m_ints[0]==0)
	{	//Copy values to temp array
		int *array = new int[ret.m_size-1];
		for(int i = 0; i < ret.m_size-1; i++)
			array[i]=ret.m_ints[i+1];
		
		//Copy them back and resize
		delete[] ret.m_ints;

		ret.m_size--;
		ret.m_ints = new int[ret.m_size];
		for(int i = 0; i < ret.m_size; i++)
			ret.m_ints[i]=array[i];
	}

	return ret;
};
CHugeInt CHugeInt::operator-(const CHugeInt & rhs)	
{
	//Return 0 values (+ 0)
	if(rhs.m_size==1 && rhs.m_ints[0]==0)
		return *this; //rhs is 0, so return this
	if(this->m_size==1 && this->m_ints[0]==0)
		return rhs; //this is 0, so return rhs

	//Variables remainder for carryover
	int smallArraySize, largeArraySize, remainder=0, divisor=0;
	CHugeInt ret; //return at end of method

	//Determine which array is larger, will use this to store values/set negative flag
	if(this->m_size > rhs.m_size)
	{
		largeArraySize = this->m_size;
		smallArraySize = rhs.m_size;
		ret = *this; //*this is larger array
		if(this->m_bNeg==true)
			ret.m_bNeg=true;
	}else if
		(this->m_size < rhs.m_size)
	{
		largeArraySize = rhs.m_size;
		smallArraySize = this->m_size;
		ret = rhs; //rhs is larger array
		ret.m_bNeg=true; //so set to negative;
	}
	else //== in size, 
	{
		largeArraySize=rhs.m_size;  smallArraySize=rhs.m_size;
		for(int i = 0; i < rhs.m_size; i++)
		{
			if(this->m_ints[i]>rhs.m_ints[i])
			{
				//ret=*this;
				this->m_bNeg=true; //this causes 2 - 1 not to work
				//ret.m_bNeg=false;
				//return ret;
				break;
			}
			else if(this->m_ints[i]<rhs.m_ints[i])
			{
//				ret=rhs;
				ret.m_bNeg=true;
				break;
			}
			else if(i == rhs.m_size-1) //reached end of for loop
			{
				//All values are same, return 0;
				ret.m_bNeg=false;
				ret.m_size=1;
				if(ret.m_ints != NULL)
					delete[] ret.m_ints;
				ret.m_ints = new int[1];
				ret.m_ints[0] = 0;
				return ret;
			}
		}
	}
	//end if


	//Set Negative value
	if(this->m_bNeg == rhs.m_bNeg)
	{
		//If both are negative, call the + operator
		if(this->m_bNeg == true && rhs.m_bNeg == true)
		{
			ret = *this + rhs;
			return ret;
		}
	}
	else if(this->m_bNeg==true && rhs.m_bNeg==false)
	{
		CHugeInt temp = rhs;
		temp.m_bNeg=false;
		//this->m_bNeg=false; //this causes -10 + 1 = -11 //commented out also issues with 2-1
		ret = temp + *this;
		ret.m_bNeg=true;
		return ret;

	}
	else if(this->m_bNeg==false && rhs.m_bNeg==true)
	{
		CHugeInt temp1=*this;
		CHugeInt temp2=rhs;
		//temp2.m_bNeg=false; //this causes 1 + -10 = +11
		return temp1+temp2;
		return ret;
	}

	else if(this->m_bNeg != rhs.m_bNeg)
	{ //If one is negative, other is positive, check see which is larger
		if(this->m_size > rhs.m_size)
		{ //*this is larger
			if(this->m_bNeg) 
				ret.m_bNeg=true; //larger value is negative
			else
				ret.m_bNeg=false; //larger value is positive
		}
		else if(this->m_size < rhs.m_size)
		{// rhs is larger
			if(rhs.m_bNeg)
				ret.m_bNeg=true; //larger value is negative
			else
				ret.m_bNeg=false; //larger value is positive
		}
		else //both numbers have same length
		{		//compare all digits until one is larger 
			for(int i = this->m_size - 1; i >= 0; i++)
			{		//Larger and negative
				if( (this->m_ints[i] > rhs.m_ints[i] && this->m_bNeg == true) ||
					(this->m_ints[i] < rhs.m_ints[i] && this->m_bNeg == true) )
				{
					ret.m_bNeg=true; //One of the # is negative and has larger value
					break;
				}
				//All numbers are same, one negative one positive results in 0 value
				ret.m_size=1;
				if(ret.m_ints != NULL)
					delete[] ret.m_ints;
				ret.m_ints = new int[1];
				ret.m_ints[0]=0;
				return ret;

			}//end for
		}//end if
	}//end Negative value check

	//Create new array for ret
/*
	if(ret.m_ints != NULL)
		delete[] ret.m_ints;
	ret.m_ints = new int[largeArraySize];
	ret.m_size = largeArraySize;
*/

	//*THIS > RHS
	if(this->m_size > rhs.m_size)
	{	
		for(int i = 0; i < ret.m_size; i++)
		{	//Set values to THIS
			ret.m_ints[i] = this->m_ints[i];
		}
		int borrow = 0;
		for(int i = ret.m_size-1, j=rhs.m_size-1; j>=0; i--,j--)
		//for(int i = ret.m_size-1; i>0; i--)
		{
			//Check if need to borrow
			if(ret.m_ints[i] - rhs.m_ints[j] < 0)
			{
				ret.m_ints[i] = ret.m_ints[i] + 10;
				ret.m_ints[i-1] = ret.m_ints[i-1] - 1;
				if(ret.m_ints[i-1] < 0 && i-1>=0)
				{
//cout<<"oh no out of borrows!  "<<ret.m_ints[i-1]<<endl;
					borrow = i-1;
					while(borrow > 0)
					{
						ret.m_ints[borrow] = ret.m_ints[borrow] + 10;
						ret.m_ints[borrow-1] = ret.m_ints[borrow-1] - 1;
						borrow --;
					}
				}
			}
			//Subtract
			ret.m_ints[i] = ret.m_ints[i] - rhs.m_ints[j];
		}

	}//end if THIS<RHS

	else if(this->m_size < rhs.m_size)
	{
		for(int i = 0; i < ret.m_size; i++)
		{	//Set values to THIS
			ret.m_ints[i] = rhs.m_ints[i];
		}
		int borrow = 0;
		for(int i = ret.m_size-1, j=this->m_size-1; j>=0; i--,j--)
		//for(int i = ret.m_size-1; i>0; i--)
		{
			//Check if need to borrow
			if(ret.m_ints[i] - this->m_ints[j] < 0  && i-1>=0)
			{
				ret.m_ints[i] = ret.m_ints[i] + 10;
				ret.m_ints[i-1] = ret.m_ints[i-1] - 1;
				if(ret.m_ints[i-1] < 0)
				{
//cout<<"oh no out of borrows!  "<<ret.m_ints[i-1]<<endl;
					borrow = i-1;
					while(borrow > 0)
					{
						ret.m_ints[borrow] = ret.m_ints[borrow] + 10;
						ret.m_ints[borrow-1] = ret.m_ints[borrow-1] - 1;
						borrow --;
					}
				}
			}
			//Subtract
			ret.m_ints[i] = ret.m_ints[i] - this->m_ints[j];
		}
	}//end if THIS<RHS

	//*THIS == RHS
	else if(this->m_size == rhs.m_size)
	{
//cout<<"test: "<<ret.m_ints[0];		
//		ret.m_ints[0]=0;

for(int i = 0; i < ret.m_size; i++)
{	//Set values to THIS
	ret.m_ints[i] = rhs.m_ints[i];
}
int borrow = 0;
for(int i = ret.m_size-1; i>=0; i--)
{
	//Check if need to borrow
	if((ret.m_ints[i] - this->m_ints[i] < 0) && i-1>=0)
	{
		ret.m_ints[i] = ret.m_ints[i] + 10;
		ret.m_ints[i-1] = ret.m_ints[i-1] - 1;
		if(ret.m_ints[i-1] < 0)
		{
//cout<<"oh no out of borrows!  "<<ret.m_ints[i-1]<<endl;
			borrow = i-1;
			while(borrow > 0)
			{
				ret.m_ints[borrow] = ret.m_ints[borrow] + 10;
				ret.m_ints[borrow-1] = ret.m_ints[borrow-1] - 1;
				borrow --;
			}
		}
	}
	//Subtract
	ret.m_ints[i] = ret.m_ints[i] - this->m_ints[i];
}
//This here keeps us from having to create a for loop to check if this.value > rhs.value, and determine which array to assign to "ret"
//	example, 9 - 1 vs 1 - 9,  rather checking if all array val on LHS are > RHS, just subtract whichever two however 
//	they are naturally assigned above, ie if asigned 1 - 9, returns -9, and check the bool flag if it was neg to start, if not it fixes this
if(ret.m_bNeg==false && ret.m_ints[0]<0)
{
	ret.m_ints[0] *=-1;
}

		//for(int i = 1; i < ret.m_size; i++)
		//{
		//	ret.m_ints[i] = this->m_ints[i-1];
		//}
		//for(int i = 1, j=0; i<ret.m_size; i++,j++)
		//{
		//	ret.m_ints[i] += rhs.m_ints[j];
		//}

		//for(int i = ret.m_size-1; i>0; i--)
		//{
		//	if(ret.m_ints[i]>9)
		//	{
		//		ret.m_ints[i-1] += ret.m_ints[i]/10;
		//		ret.m_ints[i] = ret.m_ints[i]%10;
		//	}
		//}

	}//end if THIS>RHS

	//Get rid of extra 0 at beginning
	if(ret.m_ints[0]==0)
	{	//Copy values to temp array
		int *array = new int[ret.m_size-1];
		for(int i = 0; i < ret.m_size-1; i++)
			array[i]=ret.m_ints[i+1];
		
		//Copy them back and resize
		delete[] ret.m_ints;

		ret.m_size--;
		ret.m_ints = new int[ret.m_size];
		for(int i = 0; i < ret.m_size; i++)
			ret.m_ints[i]=array[i];
		
		delete[] array;
	}

	return ret;
};
CHugeInt CHugeInt::operator-()//unary minus, negative 
{
	//call copy constructor
	CHugeInt temp = *this; 
	//negatate num and return
	if(temp.m_ints[0] !=0)
	{
		temp.m_bNeg= (!temp.m_bNeg);
	}
	else
		cout<<"-------You idiot! You cannot negate a zero!-------"<<endl;
	return temp;
}
CHugeInt & CHugeInt::operator+=(const CHugeInt & rhs)
{
	*this = *this + rhs;
	if(this->m_bNeg==true && this->m_size >= 2 && this->m_ints[1]==0)
		this->m_bNeg=false;
	return *this;
}
CHugeInt & CHugeInt::operator++() //pre increment    //modifying by this, so need &
{
	CHugeInt temp(*this+CHugeInt("1"));	
	*this = temp;
	return *this;
}
CHugeInt CHugeInt::operator++(int notUsed) //post increment
{
    // Create a temporary variable with our current value
	CHugeInt temp(*this);
 
    // Use prefix operator to increment this number
    ++(*this);             // apply operator
 
    // return temporary result
    return temp;       // return saved state
}
CHugeInt & CHugeInt::operator--() //pre decrement    
{
	CHugeInt temp(*this-CHugeInt("1"));	
	*this = temp;
	return *this;
}
CHugeInt CHugeInt::operator--(int notUsed) //post increment
{
    // Create a temporary variable with our current value
	CHugeInt temp(*this);
 
    // Use prefix operator to decrement this number
    --(*this);             // apply operator
 
    // return temporary result
    return temp;       // return saved state
}
CHugeInt CHugeInt::operator*(const CHugeInt &in)
{
	//get rid of constness ugh, put small # on lhs, big on rhs
	CHugeInt lhs,rhs; 
	if(*this < in) //1st # < 2nd #
	{
		lhs=*this;
		rhs=in;
	}
	else //2nd # > 1st#
	{
		lhs=in;
		rhs=*this;
	}
	
	//Array max size = lhs+rhs
	int size = (lhs.m_size + rhs.m_size);
	int *result = new int[size];
	for(int i = 0; i < size; i++) 
		result[i]=0;
	int insert=size;
	for(int i = lhs.m_size-1, k=0; i >= 0; i--,k++) 
	{
		insert=size-k;
		for(int j = rhs.m_size-1; j>=0; j--)
		{
			--insert;
			result[insert] = result[insert] + (lhs.m_ints[i] * rhs.m_ints[j]);
			//cout<<result[insert]<<endl;
		}
		//--size;
		cout<<endl;
	}
		//cout<<result[i]<<" ";

	int remainder=0;
	for(int i = 0; i < size; i++)
	{
		if(result[i] > 9)
		{
			result[i-1] = result[i-1] + (result[i] / 10);
			result[i] = result[i] % 10;
		}
	}

	int resize = size;
	for(int i = 0; i < size; i++)
	{
		//cout<<result[i];
		if(result[i]==0)
			resize--;
		else
			break;
	}

	if(lhs.m_ints !=NULL)
		delete[] lhs.m_ints;
	lhs.m_ints = new int[resize];
	lhs.m_size=resize;

	for(int i = resize-1, j=size-1; i >=0; i--,j--)
	{
		lhs.m_ints[i]=result[j];
	}

	if(result != NULL)
		delete[] result;

	if(rhs.m_bNeg==true)
		lhs.m_bNeg=true;

	return lhs;
}
CHugeInt CHugeInt::operator/(const CHugeInt & rhs)
{
	//LHS < RHS, return 0
	if(this->m_size < rhs.m_size)
		return CHugeInt(0);


	for(int i = rhs.m_size-1; i >=0; i--)
	{

	}

}


bool CHugeInt::operator>(const CHugeInt &rhs)
{
	int x=0;
		if( (this->m_size > rhs.m_size && this->m_bNeg==false && rhs.m_bNeg==false)  ||//LHS > RHS, both POS
			(this->m_size < rhs.m_size && this->m_bNeg==true && rhs.m_bNeg==true) ||//LHS < RHS, both NEG
			(this->m_bNeg==false && rhs.m_bNeg==true) ) //LHS==POS, RHS==NEG			
				return true;
	else if((this->m_size < rhs.m_size && this->m_bNeg==false && rhs.m_bNeg==false)  ||//LHS < RHS, both POS
			(this->m_size > rhs.m_size && this->m_bNeg==true && rhs.m_bNeg==true) ||//LHS > RHS, both NEG
			(this->m_bNeg==true && rhs.m_bNeg==false) ) //LHS==NEG, RHS==POS
				return false;
	else if(this->m_size == rhs.m_size)
	{
		for(int i = 0; i < rhs.m_size; i ++)
		{
			if(this->m_ints[i] > rhs.m_ints[i] && this->m_bNeg==false) //LHS > RHS, LHS is POS
				return true;
			if(this->m_ints[i] < rhs.m_ints[i] && this->m_bNeg==true) // RHS > LHS, LHS is NEG
				return true;
/*			{
				if(this->m_bNeg==true)
					return true; //LHS > RHS, LHS is POS (RHS NEG/POS doesnt matter)
				if(this->m_bNeg==false)
					return false; //LHS > RHS, LHS is NEG (RHS NEG/POS doesnt matter)
			}*/
		}
		return false; //ALL LHS = RHS (NEG/POS doesnt matter)
	}
	else
	{
		cout<<"---------Unhandled > issue!----------";
		return false;
	}
}
bool CHugeInt::operator>=(const CHugeInt &rhs)
{
	if( (*this > rhs) || (*this == rhs) )
		return true;

	return false;
}
bool CHugeInt::operator<(const CHugeInt &rhs)
{
	return !(*this>rhs) && (*this!=rhs);
}
bool CHugeInt::operator<=(const CHugeInt &rhs)
{
	if( (*this < rhs) || (*this == rhs) )
		return true;
	
	return false;
}

void* operator new[](size_t size)
{
	//CHugeInt *arr = (CHugeInt*)malloc(5*sizeof(CHugeInt));

void *p=malloc(size*sizeof(CHugeInt)); 
 if (p==0) // did malloc succeed?
  throw std::bad_alloc(); // ANSI/ISO compliant behavior
 return p;
}


void operator delete[](void *p)
{
 free(p); 
}