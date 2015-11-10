#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <math.h>
using namespace std;
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

int main()
{

	int a = 0, b = 0;
	int n = 0;
	int q = 0;
	
	// Prompting
	cout << "Enter A: ";
	cin  >> a;
	cout << "Enter B: ";
	cin  >> b;
	
	// Conditions
	q = a;	
	n = (b * (b + 1)) / 2;	
	assert(a > n);
	
	// Create an array
	int* array = NULL;
	array = new int[a];

	// Divide a by n and get q	
	for (int i = 0; i < a; i++)
	{
		array[i] = n;
		q -= n;
		n = floor(n / 2);
		
		// Assign remainder to the last slot
		array[a] = q;		
	}
	
	// Only display value> 0
	if (array[a] < 0)
	{
		array[0] += array[a];
	}
	else
		;

	// Display the a{}
	cout << a << ":";
	for (int k = 0; k <= a; k++)
	{
		if(array[k] > 0)
			cout << " " << array[k];
		else
			;
	}
	cout << endl;
	
	return 0;
}
