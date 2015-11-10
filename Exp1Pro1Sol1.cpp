#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

int main()
{

	int a = 0, b = 0;
	int m = 0;
	int q = 0;
	int r = 0;
	int inc = 0;
	int sum = 0;
	
	// Prompting
	cout << "Enter A: ";
	cin  >> a;
	cout << "Enter B: ";
	cin  >> b;


	// Break a into a{a1,an-1,an} with n -> b 
	int array[b - 1];
	for (int i = 0; i < b; i++)
	{
		inc++;
		array[i] = inc;
	}

	// Find quotient q and assert (a & b)
	m = (b * (b + 1)) / 2;
	q = a / m;
	assert(a > m);

	// Multiply q and a{}
	for (int j = 0; j < b; ++j)
	{
		array[j] = q * array[j];
		// Find sum of the array
		sum += array[j];
		// Make sure sum < a
		if (sum > a)
		{
			break;
		}
		else;
	}

	// Find remainder of a and sum
	r = a - sum;
	// add remainder to the last slot
	array[b - 1] += r;
	
	// Display the a{}
	cout << a << ":";
	for (int k = 0; k <= b - 1; k++)
	{
		cout << " " << array[k];
	}
	cout << endl;
	
	return 0;
}
