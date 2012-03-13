#pragma once
#pragma warning (disable :4018)
#include "CStudent.h"
#include "FileUtil.h"
//#include <algorithm>  

CStudent readFile(ifstream& fin);
void menu(ofstream & fout);
void displayMenu();
void findColor();
void writeFile(ofstream & fout);
void sortVector(); 
void printVector();

vector<CStudent> students;

int main() 
{
	//Open input/output file
	cout << endl << "Reading file..." << endl;
	ifstream fin = openInput("students.txt");
	ofstream fout = openOutput("studentsOut.txt");

	//Read file
	cout << endl << "Loading data into vector..." << endl;
	while(! fin.eof() )
	{
//		students.push_back( readFile(fin) ); //Add each student
		CStudent temp("name",1,"color");
		fin >> temp;
		students.push_back(temp); //Add each student
	}

	
//	printVector();  //Print before sort

	//Sort vector
	cout << endl << "sorting vector..." << endl;
	sortVector();

//	printVector();  //Print before sort

	//Menu
	menu(fout);

	//Close input file
	fin.close();
	fout.close();

	cout<<"\nPress <enter> to quit";	cin.ignore(255, '\n');
	return 0;
}//end main

CStudent readFile(ifstream &fin)  //Same as the >> ifstream overload
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
	//Variables
	string color; bool found = false;

	//Get color
	cout << endl << "What color to search for? ";
	getline(cin,color);
	cout << endl;

	//Loop through students
	for(int i = 0; i < students.size(); i++)
	{
		if(students.at(i).getColor().compare(color) == 0)
		{
			found = true; //color was found flag
			cout << students.at(i).getName() << endl;
			cout << students.at(i).getID() << endl;
		}
	}

	//Indicate when no color found
	if(!found)
		cout << "No entry for that color." << endl;
}

void writeFile(ofstream & fout)
{
	cout<< endl << "Students written to file." << endl;

	//Loop through students
	for(int i = 0; i < students.size(); i++)
	{
		fout << students.at(i).getLName() << ", " << students.at(i).getFName() << endl;
		fout << students.at(i).getID() << endl;
		fout << students.at(i).getColor() << endl;
	}
}

void sortVector() //vector<CStudent> & students
{
	//sort(students.begin(),students.end()); /*
	for(int i = 0; i < students.size(); i ++)
	{
		for(int j = 1; j < students.size()- i; j++)
		{
			if(students.at(j) < students.at(j-1)) //marley < jones = false
			{
				CStudent temp(students.at(j));
				students.at(j) = students.at(j-1);
				students.at(j-1) = temp;
			}
		}
	}//*/
}

void printVector()
{
	//Create iterator
	vector<CStudent>::iterator it;

	cout<<endl<<"After sort"<<endl;
	for (it = students.begin(); it < students.end(); it++ )
		cout << *it;
	//sort(students.begin(),students.end()); /*

}