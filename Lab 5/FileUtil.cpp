#include "FileUtil.h"

ifstream openInput (string filename)
{
	//Open file
//	filename = "students.txt";
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
