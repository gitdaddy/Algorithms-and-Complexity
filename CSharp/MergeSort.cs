using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inquisitiveness
{
    static class MergeSort
    {
        static public void DoMerge(double[] numbers, int left, int mid, int right)
        {

            double[] temp = new double[numbers.Length];

            int i, left_end, num_elements, tmp_pos;



            left_end = (mid - 1);

            tmp_pos = left;

            num_elements = (right - left + 1);



            while ((left <= left_end) && (mid <= right))
            {

                if (numbers[left] <= numbers[mid])

                    temp[tmp_pos++] = numbers[left++];

                else

                    temp[tmp_pos++] = numbers[mid++];

            }



            while (left <= left_end)

                temp[tmp_pos++] = numbers[left++];



            while (mid <= right)

                temp[tmp_pos++] = numbers[mid++];



            for (i = 0; i < num_elements; i++)
            {

                numbers[right] = temp[right];

                right--;

            }

        }

        static private bool slowCompare(int a, int b)
        {
            // change the loop limit up or down...
            //   for (int i = 0; i < LOOP_LIMIT; i++);
            return (a > b);
        }

        static public void MergeSort_Recursive(double[] numbers, int left, int right)
        {

            int mid;



            if (right >  left)
            {
                
                mid = (right + left) / 2;

                MergeSort_Recursive(numbers, left, mid);

                MergeSort_Recursive(numbers, (mid + 1), right);



                DoMerge(numbers, left, (mid + 1), right);

            }

        }
    }
}
