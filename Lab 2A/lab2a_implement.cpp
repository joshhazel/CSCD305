/*
Joshua Hazel
CSCD 305 C++
Stu Steiner

Part-A 
*/

#include "Lab2a.h";

void questionA1()
{
	cout << "Question 1: Do the following lines of input data work properly? Why or why not? Justify your answer with actual code. \n";
	cout << "\nUser Input: 24 25 26 \n";
	int first, second, third;
	cin >> first >> second >> third; 
	cout << "echo: " << first << " " << second << " " << third << endl; 
	cout << "The input expects 3 ints and receive 3 ints, it works.\n";

	cout << "\nUser Input: 24.4 25.5 26\n";
	double fourth, fifth, sixth; 
	cin >> fourth >> fifth >> sixth; 
	cout << "echo: " << fourth << " " << fifth << " " << sixth << endl; 
	cout << "The input expects 3 doubles and receives 2 doubles and 26 (same as 26.0), it works.\n";

	cout << "\nUser Input: 24.4 25.5 26.6 \n";
	int seventh, eighth, ninth; 
		cin >> seventh >> eighth >> ninth;
		cout << "\necho: " << seventh << " " << eighth << " " << ninth << endl; 
		//Check if failure on input
		if(cin.fail() == 1)
		{
			cin.clear(); cin.ignore(INT_MAX,'\n'); 
			cout << "The input expects 3 ints and receives 3 doubles, it throws an error.\n";
		}//end if

	cout << "\nUser Input: 23.4 24.5 \n";
	double tenth=0, eleventh=0, twelfth=0; 
	cin >> tenth >> eleventh;// >> twelfth; 
	
	cout << "echo: " << tenth << " " << eleventh << " " << twelfth << endl; 
	cout << "The input expects 3 doubles and receives 2 doubles, \ndoes not throw error but waits FOREVER for a third input.\nI have defaulted value to 0 and skip read for 3rd number.\n";
}//end question1

void questionA2() 
{
	string first_name = "Kenneth";    
	string last_name = "Cole";   
	string name; 

	cout << "\n\n2. What value will name contain after name = first_name + last_name;\n";
	name = first_name + last_name; 
	cout << name << endl;
}//end question2

void questionA3()
{
	cout << "What will be the resulting substring in the following examples? \nIf invalid, give a corrected version of the call to substr. \nJustify your answers with actual code.\n";
	
	cout << "\n3. string name = 'Robert Sourchie'    \nstring first_name = name.substr(2, 4)"; 
	string name = "Robert Sourchie"; 
	string first_name = name.substr(2, 4); 
	cout << endl << "echo: " << first_name << endl;
	cout << "Correct substring: \n\tname.substr(0,6) = " << name.substr(0,6) << endl;
}//end question3

void questionA4()
{
	cout << "\n4.  string name = 'Robert Sourchie'    \nstring last_name = name.substr(7, 4)"; 
	string name = "Robert Sourchie";
	string last_name = name.substr(7, 4); 
	cout << endl << "echo: " << last_name << endl;
	cout << "Correct substring: \n\tname.substr(7,name.length) = " << name.substr(7,name.length()) << endl;
}//end question4

void questionA5()
{
	cout << "\n5. string name = 'Pamela Sourchie'    \nstring name2 = name.substr(1, 11)"; 
	string name = "Pamela Sourchie"; 
	string name2 = name.substr(1, 11); 
	cout << endl << "echo: " << name2 << endl;
	cout << "Correct substring: \n\tname.substr(0,name.length()) = " << name.substr(0,name.length()) << endl;
}//end question5

void questionA6()
{
	cout << "6. Using substr and concatenation, write code containing a sequence of commands that will extract characters from input_string = Four score and seven years ago our fathers to make output_string = 'no tears'. Then print output_string.\n";
	string input_string = "Four score and seven years ago our fathers";
	string output_string = 
							input_string.substr(input_string.find('n'),1) + 
							input_string.substr(input_string.find("o "),2) +
							input_string.substr(input_string.find('t'),1) +
							input_string.substr(input_string.find("ears"),4);
	cout << endl << output_string << endl;
}//end question6

void questionA7()
{
	//use the setprecision, setw and setiosflags defined in the <iomanip> to create the table
	double interest, interestRate, balance, payment;
	cout << "\nProvide interest rate, the initial balance, and monthly payment amount \n(ex. 0.01 $10050.00 $500.00).\n";
	cin >> (double)interestRate >> (double)balance >> (double)payment;
	//balance = 10050; payment = 500; interestRate = 0.01; 
	
	cout << endl;
	cout << setw(13) << "Month Balance" << setw(11) << "Interest" << setw(15) << "Payment" << endl;
	for(int i = 0; i < 4; i++)
	{
		interest = balance * interestRate;

		cout	<< fixed << "$" << setw(8) << setprecision(2) << balance
				<< "\t$" << setw(6) << setprecision(2) << interest
				<< "\t\t$" << setw(6) << setprecision(2) << payment
				<< endl;
		balance = balance + interest - payment;
	}
}//end question7

void questionA8() 
{
	cout << "\nProvide two filenames, separated by space (ex. 'file1.txt' 'file2.txt').\n";
	pair<string,string> filename;
	cin >> filename.first >> filename.second;

	pair<ifstream,ifstream> fin;
	
	fin.first.open(filename.first);
	if(fin.first.fail())
		cout << "\nQuit. Unable to open " << filename.first << endl;
	else {
		fin.second.open(filename.second);
		if(fin.second.fail())
			cout << "\nQuit. Unable to open " << filename.second << endl;
		else {
			pair<string,string> compare;
			int linecount = 0;
		/*    while ( myfile.good() )
			{
			  getline (myfile,line);
			  cout << line << endl;
		*/	while(!fin.first.eof() && !fin.second.eof())
			{
				linecount++;
				getline(fin.first,compare.first);
				getline(fin.second,compare.second);
				if(compare.first.compare(compare.second))

					cout << "\nLine " << linecount << " does not match!" << endl 
						<< filename.first << ": '" << compare.first << "'" << endl 
						<< filename.second << ": '" << compare.second<< "'" << endl;
			}//end while
	
			if(!fin.first.eof())
				cout << endl << filename.second << " file is shorter than " << filename.first << endl;
			else if(!fin.second.eof())
				cout << endl << filename.first << " file is shorter than " << filename.second << endl;
			else
				cout << endl << filename.first << " and " << filename.second << " are identical " << endl;
		
			fin.second.close();
		}//end inner if (file2 opened)
		
		fin.first.close();
	}//end outer if (file1 opened)

}