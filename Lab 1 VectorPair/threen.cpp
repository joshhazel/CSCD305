#include "threen.h"

//Calculate cycles
int recurse(int count, int value)
{
    //if even, n/2
    if((value % 2) == 0)
        return recurse(count + 1,value/2);
    //if odd, 3n+1
    else if((value %2  == 1) && value > 1)
        return recurse(count + 1,(value * 3) + 1);
    //if 1
    else 
        return count;   
}
 
//pair<int,int> 
void pairs(int min, int max)
{
        //Create vector/array of pairs
		pair<int,int>* cyclecounts = new pair<int,int>[max-min];
        
		//Loop difference between two input numbers
		for(int i = 0; i < max - min; i++)
			//Calculate cycles
			cyclecounts[i] = pair<int,int>(min + i,recurse(1,min+i));

        pair<int, int> greatest = cyclecounts[0];
        
		//Determine which number has most cycle counts
		for(int i= 0; i < max-min; i++)
        {
			if(cyclecounts[i].second > greatest.second)
				greatest = cyclecounts[i];
        }//end for

		//Output to screen
        cout << min << " "  << max << " " << greatest.second << endl;
        delete[max-min] cyclecounts;
}