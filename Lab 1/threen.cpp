#include "lab1.h"

int recurse(int cycles, int num) 
{
	if(num == 1)
		return cycles;
	if(num % 2 == 0)
		return recurse(cycles+1,num/2);
	else
		return recurse(	cycles+1,3*num+1);
}

void printMax(int x, int y) {
	int threen = 0, max = 0;
	for(int i = 0; i < y-x; i++) 
	{
		threen = recurse(1,x+i);
		if(threen > max)
			max = threen;
	}
	cout << x << " " << y << " " << max << endl;
}