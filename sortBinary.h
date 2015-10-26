#ifndef SORT_BINARY_H
#define SORT_BINARY_H

#include "bst.h"
#include <cassert>

/*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 * We use the one we created in assignment 08
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{
   BST<T> sortBin;
   // insert data to BST
   for (int i = 0; i < num; i++)
      sortBin.insert(array[i]);
   
   int count = 0;
   BSTiterator<T> it;
   // copy back to the array
   for (BSTiterator<T> it = sortBin.begin(); it != sortBin.end(); it++)
   {
      array[count] = * it;
      count++;
   }
}


#endif // SORT_BINARY_H
