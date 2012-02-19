/*
	Joshua Hazel
	CSCD305 C++
	Classes Provided: Date1, Time3, hw2Tester main()
	Classes Created: CTicket, CPops, CEnsemble, CRecital, CClassical
*/
/* Initial debugging driver for the Ticket class hierarchy

   Author:  Timothy Rolfe

   Simply construct and print all of the classes defined.

   Modified by Stu Steiner 10/21/2007

   CTicket
*/
#pragma once
#include "CTicket.h"
#include "CPops.h"
#include "CEnsemble.h"
#include "CRecital.h"


void OpenFiles (ifstream &Inp, ofstream &Out);

void main ( void )
{
   ifstream Inp;
   ofstream Out;
   char  TxtIn[255];
   int   NumIn;

   OpenFiles  (Inp, Out);

   Inp >> NumIn;        // Initialize CTicket::m_NextNumber
   CTicket::SetNumber(NumIn);

   Inp >> TxtIn;        // Read the first record type

   while ( !Inp.eof() )
   {
      if ( stricmp(TxtIn, "Pops") == 0 )
      {
         CPops Tick(Inp);
         Tick.Print(Out);
      }
      else if ( stricmp(TxtIn, "Ensemble") == 0 )
      {
		  CEnsemble Tick(Inp);
         Tick.Print(Out);
      }
      else if ( stricmp(TxtIn, "Recital") == 0 )
      {
		CRecital Tick(Inp);
         Tick.Print(Out);
      }
      else
      {
         cout << "Unrecognized ticket type " << TxtIn
              << "\nAborting the run." << endl;
         break;
      }

      Out << endl << endl;   // Spacing blank lines in output

      Inp >> TxtIn;          // Read the first record type
   }
// Preserve the screen output to allow copying:
   cout << "\n\nPress ENTER to exit:";
   cin.ignore(255, '\n');
}

void OpenFiles (ifstream &Inp, ofstream &Out)
{
   char Fname[255];

   do
   {
      cout << "Input file name: " << flush;
      cin.getline(Fname, 255);
      Inp.clear();
	  Inp.open(Fname, ios::in); //Inp.open(Fname, ios::in|ios::nocreate);
	  if (Inp.fail())
         cout << "Failed to open " << Fname << " --- try again\n";
   } while ( Inp.fail() );

   do
   {
      cout << "Output file name:  " << flush;
      cin.getline(Fname, 255);
      Out.clear();
      Out.open(Fname);
      if (Out.fail())
         cout << "Failed to open hw2output.txt  " << Fname << " --- try again\n";
   } while ( Out.fail() );
}

