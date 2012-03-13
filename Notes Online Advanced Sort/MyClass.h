#pragma once

#include <iostream>
using namespace std;


class MyClass
{
public:
  inline bool operator() (int i,int j) {return (i<j);}
} ;