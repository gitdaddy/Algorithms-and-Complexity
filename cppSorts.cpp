

/***********************************************************************
* Program:
*    Ponder 04, Sanitization
*    Brother Smith, CS470
* Author:
*    Daniel Marsden
* Summary:
*    This program is our second program created in cs 124.
*    This program is made to display numbers that are easy to read.
*    In this program uses new commands such as the tab, number display
*    and set width.
************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>    // clock_t
#include <algorithm> // swap

using namespace std;

typedef int arrayItems;    // the type of item in the array
const int NUMITEMS = 100;  // number of items in array
clock_t start;        
clock_t finish;

void cocktailSort(arrayItems A[])
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

void bubbleSort(arrayItems B[])
{
	for(int i = 0; i < NUMITEMS - 1; i++)
	{
		for(int j = 0; j < NUMITEMS - 1; j++)
		{
			if(B[j] > B[j + 1])
				swap(B[j], B[j+1]);
		}

	}
}

void mergeSort(arrayItems C[])
{

}

void BTSort(arrayItems D[])
{

}

void displayItems(arrayItems x[])
{
	for(int i = 0; i < NUMITEMS; i++)
	{
		cout << " " << x[i];
	}

}


int main()
{
	// preload each array with random items	
	
	arrayItems * x = new arrayItems[NUMITEMS]; // put memeory on the heap
	cerr << "Current Unsorted Array :";
	for(int i = 0; i < NUMITEMS; i++)
	{
		x[i] = rand() % NUMITEMS; // random int from 0 to num 
		cerr << " " << x[i]; 
	}

	bool breakout = false;
	do
	{
		int z; 
		cout << "\n 1. Coctail Sort" << endl;
		cout << " 2. Bubble Sort" << endl;
		cout << " 3. Merge Sort" << endl;
		cout << " 4. Binary Tree Sort" << endl  << " >";
		cin >> z;
		if(cin.fail())
			breakout = true;
	
		switch(z)
		{
			case 1:
			{	
				start = clock();
				cocktailSort(x);    // n^2
				break;
			}
			case 2:
			{
				bubbleSort(x);     // n^2
				break;
			}
			case 3:
			{
				mergeSort(x);       // nlogn
				break;
			}
			case 4:
			{
				BTSort(x);			// nlogn
				break;
			}
			default:
			{
				cout << "Sorry that is not an option\n";
				breakout = true;
				break;
			}

		}
		finish = clock();
		cout << setprecision(3) << "Time to complete: " << (finish - start) / (double) CLOCKS_PER_SEC;

		//cout << "\nSorted List\n";
		//displayItems(x);

	}while(!breakout);

	
	return 0;
}