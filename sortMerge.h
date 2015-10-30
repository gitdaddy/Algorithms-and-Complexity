#ifndef SORT_MERGE_H
#define SORT_MERGE_H


/*****************************************************
 * copyArray
 * move the remain to the final array
 ****************************************************/
template <class T>
void copyArray(T array1[], T array2[], 
               int& temp, int first, int last)
{
   for (int i = first; i < last; i++)
   {
      array2[temp] = array1[i];
      temp++;
   }
}

/*****************************************************
 * combineArray
 * combines arrays into the final array
 ****************************************************/
template <class T>
void combineArray(T array1[], T array2[], 
                  int first1, int first2, 
				  int last1, int last2)
{
   for (int i = first1; i < last2 + 1; i++)
   {
      if (first1 > first2)
      {
	     last2 += 1;
         copyArray(array1, array2, i, last1, last2);
      }

      if (last1 > last2)
      {
	     first2 += 1;
         copyArray(array1, array2, i, first1, first2);
      }
     
      if (array1[last1] > array1[first1])
      {
         array2[i] = array1[first1];
         first1++;
      }
      else
      {
         array2[i] = array1[last1];
         last1++;
      }
   }
}

/*****************************************************
 * SORT MERGE
 * Perform the merge sort
 ****************************************************/
template <class T>
void sortMerge(T array[], int num)
{
   T* temp = new T[num];
   T* array1 = array;
   T* array2 = temp;
   int numSort;  
  
   while (numSort > 1)
   {
      int first1;
      int first2;
      int last1;
      int last2;
      int index = 0;

      numSort = 0;
      while(index < num)
      {  
         // test first1
         first1 = index;
         index++;
         while (index < num && 
		        (array1[index] > array1[index - 1] || 
				 array1[index] == array1[index - 1]))
            index++;

         // test first2
         first2 = index - 1;
         if(index == num)
         {
            copyArray(array1, array2, first2, first2, num);
            numSort++;
         }
        
         // test last1
         last1 = index;
         index++;
         while (index < num &&
		        (array1[index] > array1[index - 1] || 
				 array1[index] == array1[index - 1]))
            index++;
		 
		 // test last2
         last2 = index - 1;
		 // merging
         combineArray(array1, array2, first1, first2, last1, last2);
         numSort++;
      }
	  
	  // swap
      T* swap = array1;
      array1 = array2;
      array2 = swap;
   }
}
 

#endif // SORT_MERGE_H
