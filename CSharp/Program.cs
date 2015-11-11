using System;

using System.Collections.Generic;

using System.Text;



namespace Inquisitiveness
{

    class Program
    {
        
        static void Main(string[] args)
        {

            int[] numbers = { 3, 8, 7, 5, 2, 1, 9, 6, 4 };

            int len = 9;

            
            Console.WriteLine("MergeSort By Recursive Method");

            MergeSort.MergeSort_Recursive(numbers, 0, len - 1);

            for (int i = 0; i < 9; i++)

                Console.WriteLine(numbers[i]);



        }

    }
}