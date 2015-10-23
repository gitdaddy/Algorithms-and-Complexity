
#ifndef COCKTAIL_SORT
#define COCKTAIL_SORT

#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>    // clock_t
#include <algorithm> // swap

template <class T>
class Cocktailsort
{
public:
	void cockTailSort(T A[], int NUMITEMS)
	{
		bool swapped;
		do
		{
			swapped = false;
			for(int i = 0; i < NUMITEMS - 2; i++)
			{	
				if(A[i] > A[i + 1])
				{
					swap(A[i], A[i + 1]);
					swapped = true;
				}
			}	
			if(!swapped)
				break;
			for(int j = NUMITEMS - 2; j > 0; j--)
			{
				if(A[j] > A[j + 1])
				{
					swap(A[j], A[j + 1]);
					swapped = true;
				}
			}


		}while(swapped);
	}	
//private:
//	int NUMITEMS;
};  
#endif COCKTAIL_SORT
