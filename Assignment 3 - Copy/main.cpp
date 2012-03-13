/*
Joshua Hazel
CSCD305 C++
Assignment 3
Due Monday, March 12, 2012 midnight
*/

#pragma once

#include "main.h"
#include "FileUtil.h"
#include "Customer.h"
#include "LinkedList.h"

int main()
{
	//Open input and output files
	ifstream fin = openInput( "input");//getFilename("input") );
	//ofstream fout = openOutput( getFilename("output") );
	
	//Create LinkedList of input file
	LinkedList list;
	
	//Read files
	Customer *temp;
	cout <<	"\t\t\t\t--- Pigment ---       " << endl
		<<	"Mixture  Customer Name           1      2      3     Fee/gallon      " << endl
		<<	"-----------------------------------------------------------------       " << endl;
	while(!fin.eof())
	{
		temp = new Customer();
		fin>>*temp;
		list.add(temp);
		//cout<<temp;
	}

	cout << list;

	//Prompt user for action
	menu();

	//Close input and output files
	fin.close();
	//5fout.close();

	//Exit program
	cout<<"\n\nPress <Enter> to exit"; cin.ignore(255,'\n'); 
	return 0;
}//end main