#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H

/*****************************************************
 * SORT BUBBLE
 * Perform the bubble sort
 * We used the algorith from the CS165 textbook-
 * assignment 4.2
 ****************************************************/
template <class T>
void sortBubble(T array[], int numElements)
{
    T temp;
    int numCompare = 0;
    bool swap;

    //for (int i = 0; i < numElements; i++)
    for (int i = 0; i < (numElements + 1); i++)
    {
       //for (int j = numElements - 1; j > i + 1; j--)
       for (int j = numElements - 1; j > i; j--)
       {
          if (array[j-1] > array[j])
          {
             temp = array[j];
             array[j] = array[j-1];
             array[j-1] = temp;
          }
       }
    }

}

template <class T>
void CTS(T A[], int NUMITEMS)
{
      bool swapped;
      do
      {
         swapped = false;
         for(int i = 0; i < NUMITEMS - 2; i++)
         {  
            if(A[i] > A[i + 1])
            {
               swap(A[i], A[i + 1]);
               swapped = true;
            }
         }  
         if(!swapped)
            break;
         for(int j = NUMITEMS - 2; j > 0; j--)
         {
            if(A[j] > A[j + 1])
            {
               swap(A[j], A[j + 1]);
               swapped = true;
            }
         }


      }while(swapped);
}

// We used the algorithm in CS124 Textbook - page 343
/* for (int iSpot = numElements; iSpot >= 1 && swap; iSpot--) */
/* for (int iCheck = 0 && swap == false; iCheck <= iSpot - 1; iCheck++) */
/* { */
/* 		numCompare++; */
/*     if (array[iCheck] > array[iCheck + 1]) */
/*     { */
/* 			// swap */
/*         temp = array[iCheck]; */
/*         array[iCheck] = array[iCheck + 1]; */
/*         array[iCheck + 1] = temp; */
/*         swap = true; */
/*     } */
/* }; */



#endif // SORT_BUBBLE_H
