// sort algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

#include "MyClass.h"
#include "MyClass2.h"

using namespace std;

bool myFunction (int i,int j);
void print(vector<int> aVector);
void print(vector<MyClass2> aVector);



int main ()
{
  
  int myints[] = {32,71,12,45,26,80,53,33};
  int myints2[] = {40, 45, 12, 34, 56, 79, 1, 33};
  int myints3[] = {45,76,87,13,32,25,17,2};

  MyClass2 myc[] = {32,71,12,45,26,80,53,33};

  vector<int> myvector (myints, myints+8);               
  vector<int> myvector2 (myints2, myints2+8);            
  vector<int> myvector3 (myints3, myints3+8);    
  vector<MyClass2> myvector4(myc, myc+8);

  MyClass myObject;
  MyClass2 myObj;

  // using default comparison (operator <):
  print(myvector);
  sort (myvector.begin(), myvector.end());           
  print(myvector);
  cout << endl;

  // using function as comp
  print(myvector2);
  sort (myvector2.begin(), myvector2.end(), myFunction); 
  print(myvector2);
  cout << endl;

  // using object as comp
  print(myvector3);
  sort (myvector3.begin(), myvector3.end(), myObject);  
  print(myvector3);
  cout << endl;

  print(myvector4);
  sort (myvector4.begin(), myvector4.end(), myObj);  
  print(myvector4);
  cout << endl;



  string s;
  getline(cin, s);
  
  return 0;


}// end main


bool myFunction (int i,int j)
{
	return (i<j);
}// end myFunction

void print(vector<int> myVector)
{
	 vector<int>::iterator it;

	 // print out content:
	 cout << "myvector contains:";
	 for (it=myVector.begin(); it!=myVector.end(); ++it)
		cout << " " << *it;

	cout << endl;


}// end print

void print(vector<MyClass2> myVector)
{
	 vector<MyClass2>::iterator it;

	 // print out content:
	 cout << "myvector contains:";
	 for (it=myVector.begin(); it!=myVector.end(); ++it)
		cout << " " << *it;

	cout << endl;


}// end print