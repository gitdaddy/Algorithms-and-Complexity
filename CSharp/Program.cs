using System;

using System.Collections.Generic;

using System.Text;

using System.Diagnostics;


namespace Inquisitiveness
{

    class Program
    {
        
        static void Main(string[] args)
        {
            Console.Write("\n\nEnter the total number of elements: ");

            int max = Convert.ToInt32(Console.ReadLine());



            double[] mergeArray = new double[max];
          //  double[] bubbleArray = new double[max];
          //  double[] cocktailArray = new double[max];
            double[] quickArray = new double[max];


            for (int i = 0; i < max; i++)
            {
                mergeArray[i] = i;
               // bubbleArray[i] = i;
             //   cocktailArray[i] = i;
                quickArray[i] = i;
            }
            Random rnd = new Random();
            for (int i = 0; i < max; i++)
            {

                double swap = mergeArray[i];
                int randIndex = rnd.Next(0, (max - 1));
                mergeArray[i] = mergeArray[randIndex];
                mergeArray[randIndex] = swap;
                /*
                swap = bubbleArray[i];
                bubbleArray[i] = bubbleArray[randIndex];
                bubbleArray[randIndex] = swap;

                swap = cocktailArray[i];
                cocktailArray[i] = cocktailArray[randIndex];
                cocktailArray[randIndex] = swap;
                */
                swap = quickArray[i];
                quickArray[i] = quickArray[randIndex];
                quickArray[randIndex] = swap;

            }

            //Bubble.BubbleSort(max, bubbleArray);


            Stopwatch stopWatch = Stopwatch.StartNew();
            //CocktailSort.Sort(ref cocktailArray);
            stopWatch.Stop();
            Console.WriteLine("TIME TAKEN in COCKTAIL SORT: " + stopWatch.Elapsed);


            stopWatch = Stopwatch.StartNew();
            MergeSort.MergeSort_Recursive(mergeArray, 0, (max - 1));
            stopWatch.Stop();
            Console.WriteLine("TIME TAKEN in MERGE SORT: " + stopWatch.Elapsed);

            stopWatch = Stopwatch.StartNew();
            QuickSort.Sort(quickArray, max);
            stopWatch.Stop();
            Console.WriteLine("TIME TAKEN in QUICK SORT: " + stopWatch.Elapsed);


        }

    }
}