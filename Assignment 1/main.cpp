/*
Joshua Hazel
CSCD305 C++ 
Stu Steiner
Assignment 1 -  Due Tuesday 2-1-2012
Attempted extra credit / could not finish it
Due date extended to Saturday per Stu in Lab 2/1/2012
*/

#include "main.h"
#include "CHugeInt.h"

int main()
{
	//CHugeInt *arrayTest = new CHugeInt[5];
	CHugeInt *arr = (CHugeInt*)malloc(5*sizeof(CHugeInt));
	arr[0] = CHugeInt("-10000000000000000000000000000000000000000000");
	arr[1] = CHugeInt("1234");
	arr[2] = CHugeInt("-99");
	arr[3] = CHugeInt("234");
	arr[4] = CHugeInt("10");

	cout<<"Array of 5 CHugeInt:"<<endl;
	for(int i =0; i < 5; i++)
		cout<<i<<": "<<arr[i]<<endl;
	
	//Create default huge int
	cout<<"Creating default: intDefault"<<endl;
	CHugeInt intDefault;

	//Create explicit huge int
	cout<<"Creating default: intExplicit"<<endl;
	CHugeInt intExplicit("99");

	cout<<endl;

	//Getters
	cout<<"intDefault ACCESSORS... Size: "<<intDefault.getSize()<<"  Values: "<<intDefault.getInt()<<endl;
	cout<<"intExplicit ACCESSORS... Size: "<<intExplicit.getSize()<<"  Values: "<<intExplicit.getInt()<<endl;

	cout<<endl;


	string temp; 
/*
	//Setters
	cout<<"intDefault MUTATOR... Assign new number to intDefault: ";
	getline(cin,temp);
	intDefault.setInt(temp);
*/
	cout<<endl;

	//ostream operator overload
	cout<<"ostream intDefault: "<<intDefault<<endl;
	cout<<"ostream intExplicit: "<<intExplicit<<endl;

	cout<<endl;

	//copy constructor
	cout<<"Copying intDefault to intCopyCon"<<endl;
	CHugeInt intCopyCon(intDefault);
	cout<<"Value of intDefault: "<<intDefault<<endl;
	cout<<"Value of intCopyCon: "<<intCopyCon<<endl;

	cout<<endl;
/*
	//istream operator overload
	cout<<"istream override... Assign new number to intDefault: ";
	cin>>intDefault; //print again...
	cout<<"ostream intDefault: "<<intDefault<<endl;
	cout<<"ostream intExplicit: "<<intExplicit<<endl;
*/
	cout<<endl;

	//overload =
	cout<<"overload '='... intAssign=intDefault";
	CHugeInt intAssign = intDefault; cout<<endl;//print again
	cout<<"ostream intAssign: "<<intAssign<<endl;
	cout<<"ostream intDefault: "<<intDefault<<endl;

	cout<<endl;

	//overload == 
	cout<<"overload '=='... Check: intAssign==intDefault"<<endl;
	if(intAssign==intDefault)
		cout<<"intAssign ----IS EQUAL---- to intDefault"<<endl;
	cout<<"\tintDefault: "<<intDefault<<endl;
	cout<<"\tintAssign: "<<intAssign<<endl;
	cout<<endl;

	cout<<endl;
	//overload !=
	cout<<"overload '!='... Check:  intAssign!=intCopyCon:"<<endl;
	if(intAssign!=intCopyCon)
		cout<<"intAssign ----IS NOT EQUAL---- to intCopyCon"<<endl;
	cout<<"\tintAssign: "<<intAssign<<endl;
	cout<<"\tintCopyCon: "<<intCopyCon<<endl;

	cout<<endl;

	//overload +=
	cout<<"overload '+='... intCopyCon+=intDefault"<<endl;
	cout<<"Before:\n\tintCopyCon: "<<intCopyCon<<endl;
	cout<<"\tintDefault: "<<intDefault<<endl;
	intCopyCon+=intDefault;
	cout<<"After:\n\tintCopyCon: "<<intCopyCon<<endl;
	cout<<"\tintDefault: "<<intDefault<<endl;

	cout<<endl;

	//overload ++
	cout<<"overload 'post++'... intDefault++  "<<intDefault++<<endl;
	cout<<"Actual value: "<<intDefault<<endl;

	cout<<"overload '++pre'... ++intDefault"<<endl<<++intDefault<<endl;
	cout<<"Actual value: "<<intDefault<<endl;

	cout<<endl;

	//overload --
	cout<<"overload 'post--'... intDefault--  "<<intDefault--<<endl;
	cout<<"Actual value: "<<intDefault<<endl;

	cout<<"overload '--pre'... --intDefault"<<endl<<--intDefault<<endl;
	cout<<"Actual value: "<<intDefault<<endl;

	cout<<endl;

	//overload -
	cout<<"overload '- subtract'... Check:  intMinus = (intDefault - intCopyCon)"<<endl;
	cout<<"\tintDefault: "<<intDefault<<endl;
	cout<<"\tintCopyCon: "<<intCopyCon<<endl;
	CHugeInt intMinus = (intCopyCon-intDefault);
	cout<<"\t\tintMinus:  "<< intMinus<<endl;
	cout<<endl;

	cout<<endl;

	//overload unary -
	cout<<"overload 'unary negation -'... -intCopyCon"<<endl;
	cout<<-intCopyCon<<endl;
	cout<<"\tintCopyCon: "<<intCopyCon<<endl;

	cout<<endl;

	//overload +
	cout<<"overload '+'... Check:  intPlus = (intCopyCon + intDefault)"<<endl;
	cout<<"\tintCopyCon: "<<intCopyCon<<endl;
	cout<<"\tintDefault: "<<intDefault<<endl;
	CHugeInt intPlus=(intCopyCon+intDefault);
	cout<<"\t\tintPlus:  "<< intPlus<<endl;
	cout<<endl;

	cout<<endl;

	//overload *
	cout<<"overload '*'... Check:  intMultiply = (*arr[1] * *arr[3])"<<endl;
	cout<<"\tarr[1]: "<<arr[1]<<endl;
	cout<<"\tarr[3]: "<<arr[3]<<endl;
	CHugeInt intMultiply=(arr[1]*arr[3]);
	cout<<"\tintMultiply:  "<< intMultiply<<endl;

	cout<<endl;

	//overload >
	cout<<intDefault<<" > "<<intExplicit<<endl;
	if(intDefault > intExplicit)
		cout<<"TRUE"<<endl;
	else
		cout<<"FALSE"<<endl;

	cout<<endl;

	//overload >=
	cout<<intDefault<<" >= "<<intExplicit<<endl;
	if(intDefault >= intExplicit)
		cout<<"TRUE"<<endl;
	else
		cout<<"FALSE"<<endl;
	
	cout<<endl;

	//overload <
	cout<<intDefault<<" < "<<intExplicit<<endl;
	if(intDefault < intExplicit)
		cout<<"TRUE"<<endl;
	else
		cout<<"FALSE"<<endl;
	
	cout<<endl;

	//overload <=
	cout<<intDefault<<" <= "<<intExplicit<<endl;
	if(intDefault <= intExplicit)
		cout<<"TRUE"<<endl;
	else
		cout<<"FALSE"<<endl;
	
	cout<<endl;

	free(arr);

	cout <<"\n\nEnd program 0:\nType q and <enter> to quit: ";	cin>>temp;
   return 0;
}
