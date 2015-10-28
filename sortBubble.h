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
