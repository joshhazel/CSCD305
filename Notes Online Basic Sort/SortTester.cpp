// sort algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "MyClass.h"

using namespace std;

bool myFunction (int i,int j);
void print(vector<int> aVector);



int main ()
{
  
  int myints[] = {32,71,12,45,26,80,53,33};
  int myints2[] = {40, 45, 12, 34, 56, 79, 1, 33};
  int myints3[] = {45,76,87,13,32,25,17,2};

  vector<int> myvector (myints, myints+8);               
  vector<int> myvector2 (myints2, myints2+8);            
  vector<int> myvector3 (myints3, myints3+8);            

  MyClass myObject;

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