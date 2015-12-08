#include <iostream> 
#include <stdio.h> 
#include <math.h>
#include <cassert>
#include <NTL/ZZ.h>
using namespace std;
NTL_CLIENT
/************************
 * Compile with:   
 *   g++ vastnessZZ.cpp -lntl
 *************************/

bool check = false;
long baseTwo = 2;
long baseTen = 10;
long n = 0;
long numLog = 0;

ZZ prefix = to_ZZ(0);
ZZ expo = to_ZZ(0);
ZZ num = to_ZZ(0);
ZZ Test = to_ZZ(0);
ZZ newTest = to_ZZ(0);

int main ()
{
   cout << "Enter the prefix: ";
   cin >> prefix;
   assert(prefix >= 1);
   
   while (check == false)
   {
      power(expo, baseTen, n);
      num = (prefix + to_ZZ(1)) * expo;
      numLog = floor(log(num) / log(baseTwo));
      power(Test, baseTwo, numLog);
      newTest = Test / expo;
      
      if (prefix == newTest)
      {
         if (prefix == 1)
         {
            cout << "Prefix: 1 | 2^0 = 1" << endl;
            return 0;
         }
         cout << "Prefix: " << prefix    << " | "
              << "2^"       << numLog
              << " = "      << Test      << endl;
         check = true;
      }
      n++;
   }
   return 0;
}
