#include "CFraction.h"

int main()

{
	//3 constructors
	CFraction a(1,2), b(2,3), c;
	CFraction d = b;//this line doesnt call assignment operatory, assignment op only called when assigning two obj, in this case d has not been constructed so it is not yet an obj -- MUST CONSTRUCT 2 OBJ TO CALL BOTH OBJ
	CFraction e = 3; 
	c = a; //creates shallow copy

	cout<<"a: " << a << endl;
	cout<<"b: " << b << endl;
	cout<<"c: " << c << endl;
	cout<<"d: " << d << endl;
	cout<<"e: " << e << endl;

	string ch; 



	string exit;
	getline(cin,exit);
	//exit normal
	return 0;
}