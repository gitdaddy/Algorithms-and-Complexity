using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace Inquisitiveness
{
    static class Bubble
    {
        public static int BubbleSort(int max, double[] numarray)
        {
            


            Stopwatch stopWatch = Stopwatch.StartNew();
            for (int i = 1; i < max; i++)
            {

                for (int j = 0; j < max - i; j++)
                {

                    if (numarray[j] > numarray[j + 1])//slowCompare(numarray[j], numarray[j + 1]) )
                    {

                        double temp = numarray[j];

                        numarray[j] = numarray[j + 1];

                        numarray[j + 1] = temp;

                    }

                }
               
               

            }
            stopWatch.Stop();
            Console.WriteLine("TIME TAKEN in BUBBLE SORT: " + stopWatch.Elapsed);

            return 0;

        }

        static private bool slowCompare(int a, int b)
        {
            // change the loop limit up or down...
            //   for (int i = 0; i < LOOP_LIMIT; i++);
            return (a > b);
        }
    }
}
