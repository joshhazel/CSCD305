// Fig. 8.6: date1.h
// Definition of class Date
#ifndef DATE1_H
#define DATE1_H
#include <iostream>
using namespace std;

class Date {
   friend ostream &operator<<( ostream &, const Date & );

public:
   Date( int m = 1, int d = 1, int y = 1900 ); // constructor
   void setDate( int, int, int ); // set the date
   Date &operator++();            // preincrement operator
   Date operator++( int );        // postincrement operator
   const Date &operator+=( int ); // add days, modify object
   bool leapYear( int );          // is this a leap year?
   bool endOfMonth( int );        // is this end of month?

private:
   int month;
   int day;
   int year;

   static const int days[];       // array of days per month
   void helpIncrement();          // utility function
};

#endif

