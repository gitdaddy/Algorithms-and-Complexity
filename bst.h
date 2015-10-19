/***********************************************************************
 * Module:
 *    Lesson 10, Sort Binary
 *    Brother Helfrich, CS 235
 * Summary:
 *    This program will implement the Binary Tree Sort.  It supports
 *    the insert, find, and remove functions, and others.  It has has a 
 *    BST iterator class that provides functionality for pointers in 
 *    to nodes within the tree.
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include "bnode.h"
#include <cassert>
#include <queue>

// Forward declaration
template <class T>
class BSTiterator;

// Forward declaration
template <class T>
class BST;

/***************************************************************************************
 * CLASS LIST ITERATOR
 * A list iterator holds a pointer to a node within a BST.  
 ****************************************************************************************/
template <class T>
class BSTiterator
{
  public:
   // default constructor
  BSTiterator() : p(0x00000000) {  }       
      
   // initialize to direct p to some item
  BSTiterator(BinaryNode<T> * pointer) : p(pointer) { }

   // copy constructor
   BSTiterator(const BSTiterator<T> & rhs) { *this = rhs; }   

   // assignment operator
   BSTiterator & operator = (const BSTiterator & rhs)    
   {
      this->p = rhs.p;
	  return *this;
   }
   
   // not equals operator
   bool operator != (const BSTiterator & rhs) const
   {
      return rhs.p != this->p;
   }
   
   //  equals operator
   bool operator == (const BSTiterator & rhs) const
   {
      return rhs.p == this->p;
   }
   
   // dereference operator
   T & operator * ()                                         
   {
      return p->data;
   }

   BinaryNode<T> getNode()  { return *p; }

    /////////////////// PRE-FIX INCREMENT ////////////////////
   BSTiterator <T> operator ++ ()                       
   {    
      // Case 1: We have a right child
      if (p->pRight != NULL)
      {
         // jog right
         p = p->pRight;
         // go left as far as we can
         while (p->pLeft)
            p = p->pLeft;
      }
      // Case 2:  No right child, I am left child
      else if (p->pRight == NULL && !p->isRightChild())    
      {
         p = p->pParent;
      }
      // case 3:  No Right child, I am right child
      else if (p->pRight == NULL && p->isRightChild())   
      {
         //  How do we handle the case of the last item ?
         BinaryNode<T> * ptr = p;
         //  Go as far up to the left as we can
         while (ptr->isRightChild() && ptr->pParent != NULL)
         {
            ptr = ptr->pParent;
         }
         // unless we are the root...
         if (ptr->pParent != NULL)
         {
            // set ptr to it's parent (now that we've
            // headed as far left as we can, jog right)
            ptr = ptr->pParent;
            p = ptr;
         }
         else
            p = NULL; 
         
      }
      
      BSTiterator<T> temp(p);
      return temp;
      ///////////////END OF PRE-FIX INCREMENT////////////////////////
   }

   /////////////////////// POST-FIX INCREMENT ////////////////////////
   BSTiterator <T> operator ++ (int postfix) 
   {
      // we will change p but return original iterator
      BSTiterator temp(*this);

      // Case 1: We have a right child
      if (p->pRight != NULL)
      {
         // jog right
         p = p->pRight;
         // go left as far as we can
         while (p->pLeft)
            p = p->pLeft;
      }
      // Case 2:  No right child, I am left child
      else if (p->pRight == NULL && !p->isRightChild())
      {
         p = p->pParent;
      }
      // case 3:  No Right child, I am right child
      else if (p->pRight == NULL && p->isRightChild())
      {
         //  How do we handle the case of the last item ?
         BinaryNode<T> * ptr = p;
         //  Go as far up to the left as we can
         while (ptr->isRightChild() && ptr->pParent != NULL)
         {
            ptr = ptr->pParent;
         }
         // check to make sure we are not the root...
         if (ptr->pParent != NULL)
         {
            // set ptr to it's parent (now that we've
            // headed as far left as we can, jog right)
            ptr = ptr->pParent;
            p = ptr;
         }
         else
            p = NULL; 
      }
      return temp;
   }
   
   ///////////////////// PRE-FIX DECREMENT /////////////////////
   BSTiterator <T> operator -- ()                    
   {
      {
         // Case 1: We have a left child
         if (p->pLeft != NULL)
         {
            // jog left
            p = p->pLeft;
            // go right as far as we can
            while (p->pRight)
               p = p->pRight;
         }
         // Case 2:  No left child, I am right child      
         else if (p->pLeft == NULL && p->isRightChild())   
         {
            p = p->pParent;
         }
         // case 3:  No left child, I am left child
         else if (p->pLeft == NULL && !p->isRightChild())   
         {
            //  How do we handle the case of the last item ?
            BinaryNode<T> * ptr = p;
            //  Go as far up to the right as we can
            while (!ptr->isRightChild() && ptr->pParent != NULL)
            {
               ptr = ptr->pParent;
            }
            // As long as we are not the root...               
            if (ptr->pParent != NULL)
            {
               // set ptr to it's parent (now that we've   
               // headed as far left as we can, jog right)
               ptr = ptr->pParent;
               p = ptr;
            }
            else
               p = NULL; // set P to null
         }
         // Create an iterator that points to p
         BSTiterator<T> temp(p); 
         return temp;               // and return it
      }
   }
   
   ///////////////////// POST-FIX DECREMENT /////////////////////
   BSTiterator <T> operator -- (int postfix)
   {
      // we will change p but return original iterator
      BSTiterator temp(*this);

      // Case 1: We have a left child
      if (p->pLeft != NULL)
      {
         // jog left
         p = p->pLeft;
         // go right as far as we can
         while (p->pRight)
            p = p->pRight;
      }
      // Case 2:  No left child, I am right child      
      else if (p->pLeft == NULL && p->isRightChild())   
      {
         p = p->pParent;
      }
      // case 3:  No left child, I am left child
      else if (p->pLeft == NULL && !p->isRightChild()) 
      {
         //  How do we handle the case of the last item ?
         BinaryNode<T> * ptr = p;
         //  Go as far up to the right as we can
         while (!ptr->isRightChild() && ptr->pParent != NULL)
         {
            ptr = ptr->pParent;
         }
         // unless we are the root...                
         if (ptr->pParent != NULL)
         {
            // set ptr to it's parent (now that we've   
            // headed as far left as we can, jog right)
            ptr = ptr->pParent;
            p = ptr;
         }
         else
            p = NULL; 
      }

      return temp;
   }

   BinaryNode <T> * getP() {return p;}
   void setP(BinaryNode<T> * theNode) { p = theNode;}
   
   private:
   BinaryNode<T> * p;  // pointer to a node
};

 /***********************************************************************
 * The BST class encapsulates a Binary Search Tree, which maintains the
 * following order:  All items on the left of a node are smaller than it,
 * and all items on the right of a node are greater than it.
 ************************************************************************/
template <class T>
class BST
{
  public:
   BST() : root(NULL) {};  
   ~BST() { clear(root); }
   //question ??
   //  BinaryNode<T> Bnode;             
   bool empty() { return root == NULL; }
   void clear(BinaryNode <T> * root);
   BSTiterator<T> find(const T & item);             
      
   void copySubTree(BinaryNode <T> * subTree)
   {
      if (subTree != NULL)
      {
	     BinaryNode<T> temp(*subTree);
         push_back(temp);
         copySubTree(subTree->pLeft);
         copySubTree(subTree->pRight);
      }
   }
   
	// Jason: temping to overload < operator
   // bool operator < (const BST & rhs)
   // {
      // return root < rhs.root;
   // }   
   
   BST & operator = (const BST & rhs) throw (const char *)
   {
      BST<T> returnCopy;
      if (root == NULL)
	  {
	     returnCopy = new BST<T>();
		 return returnCopy;
      }
	  else
	  {
	     copySubTree(root);
	  }
   }

   void insert(const T & item);
   BinaryNode<T> * getRoot() { return root; }
      
   BSTiterator<T> begin();
   BSTiterator<T> end()      {return BSTiterator<T> (NULL); } 
   BSTiterator<T> rbegin();
   BSTiterator<T> rend()     {return BSTiterator<T> (NULL); }
   
   void searchForRemove(const T & item, bool found,
                        BinaryNode<T> * temp, BinaryNode<T> * parent) const;
   void remove(BSTiterator<T> tmp);
      
  private:          
   BinaryNode<T> * root;
   std::queue<BinaryNode<T> > copyQueue;
   
   // Used in begin().  Concept gained from classmate Tenzing (spelling?)
   BinaryNode<T>* getLeftMost(BinaryNode<T> * temp)
   {
      if (temp == NULL)
         return temp;
      if (temp->pLeft == NULL)
         return temp;
      return getLeftMost(temp->pLeft);
   }
   
    // Used in rBegin().  Concept gained from classmate Tenzing (spelling?)
   BinaryNode<T>* getRightMost(BinaryNode<T> * temp)
   {
      if (temp == NULL)
         return temp;
      if (temp->pRight == NULL)
         return temp;
      return getRightMost(temp->pRight);
   }
   
};


/************************************************ 
 * BEGIN
 *    returns at iterator to the begining of the 
 *   BST, by calling getLeftMost();
 ***********************************************/
template <class T>
BSTiterator<T> BST<T>::begin()
{
   return BSTiterator<T>(getLeftMost(root));
}

/************************************************ 
 * RBEGIN
 *    returns at iterator to the rbegin (end) of 
 *  the BST, by calling getRightMost();
 ***********************************************/
template <class T>
BSTiterator<T> BST<T>::rbegin()
{
   return BSTiterator<T>(getRightMost(root));
}   


/************************************************
 * CLEAR
 *    deletes all children and itself
 ***********************************************/
template <class T>
void BST<T>::clear(BinaryNode <T> * root)
{
   if (root != NULL)
   {
      clear(root->pLeft);
      clear(root->pRight);
      delete root;
   }
}

/************************************************
 * INSERT
 *   Creates a node with the item in it, maintains
 *  the order of the binary search tree, and 
 *  sets pointers accordingly.
 ***********************************************/
template <class T>
void BST<T>::insert(const T & item)
{
   bool found = false;  // Have we found where to place the item?
   
   if (root == NULL)
   {
      root = new BinaryNode<T>(item);
   }
   else
   {
      BinaryNode<T> * temp = root;
   
      while (!found)
      {
         //if (item < temp->data)  This wouldn't compile...
         if (temp->data > item)
         {
            if (temp->pLeft == NULL)
            {
               temp->addLeft(item);
               found = true;
            }
            else
               temp = temp->pLeft;       
         }

         if (item > temp->data)
         {
            if (temp->pRight == NULL)
            {
               temp->addRight(item);
               found = true;
            }
            else  
               temp = temp->pRight;
         }
         if (item == temp->data)
         {
            if (temp->pLeft == NULL)
                temp->addLeft(item);
            else
               temp->addRight(item);
            
            found = true;
         }
      }
   }
}


/************************************************
 * REMOVE
 *  Removes an item from the list.  It takes an
 * iterator pointing to the node to be removed
 * as a parameter.  It adjusts the pointers
 * of the nodes affected according to maintain the
 * order of the BST.
 ***********************************************/
template <class T>
void BST<T>::remove( BSTiterator<T> trash)
{
   bool found;

   BinaryNode<T> * x = trash.getP();
   BinaryNode<T> * parent = x->pParent;
   
   // Case:  2 children
   if (x->pLeft != NULL && x->pRight != NULL)
   {
      BinaryNode<T> * ios;  // in-order successor
	  ios = x->pRight;          // move right one
	  // then move to the left all they way
	  while (ios->pLeft != NULL)  
	  {
	     parent = ios;
		 ios = ios->pLeft;
	  }
      
	  x->data = ios->data;
	  x = ios;
   }

   // Case:  0 or 1 children
   //        (at most 1 non-empty subtree)
   BinaryNode<T> * subtree;
   subtree = x->pLeft;
   if (subtree == NULL)
      subtree = x->pRight;
   if (parent == NULL)
      root = subtree;
   if (parent->pLeft == x)
      parent->pLeft = subtree;
   if (parent->pRight == x)
   {
      parent->pRight = subtree;
	  //subtree->pParent = parent;
   }	
   delete x;
}

/************************************************
 * FIND
 *  Searches all the nodes in the BST for the 
 * one containing a given item, and returns an 
 * iterator pointing to that node. 
 ***********************************************/
template <class T>
BSTiterator<T> BST<T>::find(const T & item)  
{
   BinaryNode<T> * temp = new BinaryNode<T>(); // took out parameter of item
   temp = root;
   //root = temp;
   bool found = false;

   while (temp != NULL) // !found && 
   {
      std::cerr << "Checkpoint 1\n";
      if (item == temp->data)
      {
         std::cerr << "Checkpoint 2\n";
         return BSTiterator<T>(temp);
         //found = true;
      }
      else if (temp->data < item)
      {
         std::cerr << "Checkpoint 3\n";
         if (temp->pRight == NULL)
         {
            std::cerr << "Checkpoint 4\n";
            //temp = NULL;
            return end();  // do not move right if pRight is NULL
            break;
         }
         else
         {
            std::cerr << "Checkpoint 5\n";
            temp = temp->pRight;
         }
      }
      else // item < temp->data
      {
         std::cerr << "Checkpoint 6\n";
         if (temp->pLeft == NULL)
         {
            std::cerr << "Checkpoint 7\n";
            //temp = NULL;
            return end();  // do not move left if pLeft is NULL
            //break;
         }
         std::cerr << "Checkpoint 8\n";
         temp = temp->pLeft;
      }
      std::cerr << "Checkpoint 9\n";
   }

   /* if (found == false) */
   /* { */
   /*    return end(); */
   /* } */

   std::cout << "temp->data = " << temp->data << std::endl;
   
  
}
#endif
