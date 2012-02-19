// Fig. 6.10: time3.h
// Declaration of the Time class.
// Member functions defined in time3.cpp

// preprocessor directives that
// prevent multiple inclusions of header file
#ifndef TIME3_H  
#define TIME3_H 

#include <iostream>
using namespace std;

class Time {
public:
   Time( int = 0, int = 0, int = 0 );  // constructor

   // set functions
   void setTime( int, int, int );  // set hour, minute, second
   void setHour( int );   // set hour
   void setMinute( int ); // set minute
   void setSecond( int ); // set second

   // get functions
   int getHour();         // return hour
   int getMinute();       // return minute
   int getSecond();       // return second

   void printMilitary();  // output military time
   void printStandard();  // output standard time

private:
   int hour;              // 0 - 23
   int minute;            // 0 - 59
   int second;            // 0 - 59
};

#endif

