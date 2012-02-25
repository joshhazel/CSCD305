#pragma once
#pragma warning (disable :4018)
#include "CStudent.h"
#include "FileUtil.h"
#include <algorithm>  

CStudent readFile(ifstream& fin);
void menu(ofstream & fout);
void displayMenu();
void findColor();
void writeFile(ofstream & fout);
void sortVector(); //vector<CStudent> & students

vector<CStudent> students;

int main() 
{
	//Open input/output file
	ifstream fin = openInput("students.txt");
	ofstream fout = openOutput("studentsOut.txt");

	//Read file
	while(! fin.eof() )
		students.push_back( readFile(fin) ); //Add each student

	//Create iterator
	vector<CStudent>::iterator it;

	//Print before sort
	cout<<endl<<"After sort"<<endl;
	for (it = students.begin(); it < students.end(); it++ )
		cout << *it;

	//Sort vector
	sortVector();

	//Print after sort
	cout<<endl<<"After sort"<<endl;
	for (it = students.begin(); it < students.end(); it++ )
		cout << *it;


	//Menu
	menu(fout);

	//Close input file
	fin.close();
	fout.close();

	cout<<"\nPress <enter> to quit";	cin.ignore(255, '\n');
	return 0;
}//end main

CStudent readFile(ifstream &fin)
{
	string name;
	string color;
	int id;
	
	getline(fin, name); //get lname, fname
	fin >> id; //get id
	getline(fin,color);
	getline(fin,color); //get color

	return CStudent(name, id, color);
}

void menu(ofstream & fout)
{
	displayMenu();
	string kb;
	getline(cin,kb);

	while(kb.compare("3") != 0)
	{
		if(kb.compare("1")==0)
			findColor();
		else if(kb.compare("2")==0)
			writeFile(fout);
		
		displayMenu();
		getline(cin,kb);
	}
}

void displayMenu()
{
	cout << endl << "1.  Search student favorite color"
		 << endl << "2.  Write sorted array to output file: studentsOut.txt"
		 << endl << "3.  Quit"
		 << endl << "-->";
}

void findColor()
{
	cout<<"find color"<<endl;
}

void writeFile(ofstream & fout)
{
	cout<<"write file"<<endl;
}

void sortVector() //vector<CStudent> & students
{
	cout<<"sort vector"<<endl;
	sort(students.begin(),students.end());/*
	for(int i = 0; i < students.size(); i ++)
	{
		for(int j = i; j < students.size()-1; j++)
		{
			if(students.at(j) < students.at(j+1))
			{
				CStudent temp(students.at(j));
				students.at(j) = students.at(j+1);
				students.at(j+1) = temp;
			}
		}
	}*/
}