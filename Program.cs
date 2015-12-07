using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace powersOf2
{
    class Program
    {
        static void Main(string[] args)
        {
            BigInteger testInt;
            if(BigInteger.TryParse(Console.ReadLine(), out testInt))
            {
                int m = 0;
                BigInteger baseVal = 10;
                BigInteger twoVal = 2;
                bool successful = false;

                while(!successful)
                {
                    var testVal = (testInt + 1) * BigInteger.Pow(baseVal, m);
                    var logVal = new BigInteger(BigInteger.Log(testVal, 2.0));
                    var newTest = BigInteger.Pow(twoVal, (int)logVal);
                    var display = newTest;
                    newTest = newTest / BigInteger.Pow(baseVal, m); 

                    if (testInt == newTest)
                    {
                        Console.WriteLine("2^{0} is the matching value", logVal);
                        Console.WriteLine("The Number is {0}", display);
                        successful = true;
                    }
                    m++;
                }
            }
        }
    }
}
