#pragma once

#include "main.h"
#include "LinkedList.h"

ifstream openInput(string);
ofstream openOutput(string);
string getFilename(string);

int getInput(string input, int min, int max);
void menu(LinkedList* list, ofstream& fout);
void editPigment(LinkedList* list);
void removeCustomer(LinkedList* list);
void writeFile(LinkedList* list,ofstream& fout);
void printHeader(ofstream& fout);
void printVector(vector<Customer*> customers,ofstream& fout);
bool sortFunction(Customer* lhs, Customer* rhs);