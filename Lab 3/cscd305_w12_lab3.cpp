/*
Joshua Hazel
CSCD305 C++ 
Stu Steiner
Lab 3 - Due Monday 1-30-2012
*/

#include "cscd305_w12_lab3.h"
#include "CArray.h"

int main()
{
	CArray integers1(7); // seven-element CArray
	CArray integers2; // 10-element CArray by default

	// print integers1 size and contents
   cout << "Size of CArray integers1 is " << integers1.getSize() << endl 
	   << "CArray after initialization:" << endl << integers1 << endl; 

   // print integers2 size and contents
   cout << "Size of CArray integers2 is " << integers2.getSize() << endl
      << "CArray after initialization:" << endl << integers2 << endl;

   // input and print integers1 and integers2
   cout << "Enter 17 integers:" << endl;
   cin >> integers1 >> integers2; //uncomment
   

   cout << "After input, the CArrays contain:" << endl
      << "integers1:" << endl << integers1
      << "integers2:" << endl << integers2 << endl;

   // use overloaded inequality (!=) operator
   cout << "Evaluating: integers1 != integers2" << endl;

   if ( integers1 != integers2 )
      cout << "integers1 and integers2 are not equal" << endl;

   // create CArray integers3 using integers1 as an
   // initializer; print size and contents
   CArray integers3( integers1 ); // invokes copy constructor

   cout << endl;

   cout << "Size of CArray integers3 is " << integers3.getSize() << endl
      << "CArray after initialization:" << endl << integers3 << endl;
   // use overloaded assignment (=) operator
   cout << "Assigning integers2 to integers1:" << endl;
   integers1 = integers2; // note target CArray is smaller

   cout << "integers1:" << endl << integers1
      << "integers2:" << endl << integers2;

   // use overloaded equality (==) operator
   cout << "Evaluating: integers1 == integers2" << endl;

   if ( integers1 == integers2 )
      cout << "integers1 and integers2 are equal" << endl;

	  //Print subarray????  how to ?
   // use overloaded subscript operator to create rvalue
   cout << "integers1[5] is " << integers1[ 5 ];

   // use overloaded subscript operator to create lvalue
   cout << "Assigning 1000 to integers1[5]" << endl;
   integers1[ 5 ] = 1000;
   cout << "integers1:" << integers1;

   
   // attempt to use out-of-range subscript
   try
   {
      cout << "Attempt to assign 1000 to integers1[15]" << endl;
      integers1[ 15 ] = 1000; // ERROR: subscript out of range
   } // end try
   catch ( out_of_range &ex )
   {
      cout << "An exception occurred: " << ex.what() << endl;
   } // end catch

   string exit;	cout <<"Type q and <enter> to quit: ";	cin>>exit;
   return 0;
} // end main
