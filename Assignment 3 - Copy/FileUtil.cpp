#pragma once
#include "FileUtil.h"

ifstream openInput (string filename)
{
	//Open file
	ifstream fin;
	fin.open(filename, ios::in);

	//Request filename if fail
	while ( fin.fail() )
	{
		cout << "Input file name: " << flush;
		getline(cin, filename);
		fin.clear();
		fin.open(filename);
		if (fin.fail())
			cout << "Failed to open " << filename << " --- try again\n";
	}
	return fin;
}

ofstream openOutput (string filename)
{
	//Open file
	ofstream fout;
	fout.open(filename);

	//Request filename if fail
	while ( fout.fail() )
	{
		cout << "Output file name: " << flush;
		getline(cin, filename);
		fout.clear();
		fout.open(filename);
		if (fout.fail())
			cout << "Failed to open " << filename << " --- try again\n";
	}

	return fout;
}

string getFilename(string fileType)
{
	string filename = "";
	while(filename == "")
	{
		cout << "\nPlease provide the " << fileType << " filename: ";
		getline(cin,filename);
	}
	return filename;
}

void menu()
{
	string input = "";
	while(input != "4")
	{
		cout << endl
			<< "Select an option from below:" << endl
			<< "1.  Edit pigment quantities for a customer" << endl
			<< "2.  Remove information on a customer" << endl
			<< "3.  Write contents (append) to output file" << endl
			<< "4.  Quit"  << endl << endl
			<< "Selection: ";

		getline(cin,input);
		if( input.length() == 0)
			input="0";

		switch (input.at(0))
		{
			case '1':

				break;
			case '2':

				break;
			case '3':

				break;
			case '4':
				break;
			default: 
				cout << "\nInvalid input.\n";
				break;
		}
	}
}