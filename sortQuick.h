#ifndef SORT_QUICK_H
#define SORT_QUICK_H


/*****************************************************
 * SPLIT
 * Rearrange the array to position pivot. 
 ****************************************************/
template <class T>
int split (T x[], int first, int last)
{
   T pivot = x[first];
   int left = first;
   int right = last;

   while (left < right)
   {
      while (pivot < x[right])
         right--;

      while (left < right &&
             (x[left] < pivot || x[left] == pivot))
         left++;
		 
      if (left < right)
      {
         //swap(x[left], x[right]);
         T temp = x[left];
         x[left] = x[right];
         x[right] = temp;
      }
   }
   
   int pos = right;
   x[first] = x[pos];
   x[pos] = pivot;
   return pos;
}

/*****************************************************
 * QUICK SORT
 * Perform the quick sort
 ****************************************************/
template <class T>
void sort3(T x[], int first, int last)
{
   int pos;
   
   if (first < last)
   {
      pos = split(x, first, last);
      sort3(x, first, pos - 1);
      sort3(x, pos + 1, last);
   }
   else
   ;
}

/*****************************************************
 * SORT QUICK
 * Call sort function with 3 parameters
 ****************************************************/
template <class T>
void sortQuick(T x[], int num)
{
   int first = 0;
   sort3(x, first , num - 1);
}


#endif // SORT_QUICK_H
