/***********************************************************************
* Header:
*    Node
* Summary:
*    This will contain the class definition of:
*        BINARY Node : A class encapsulates a single node on a Binary Tree
************************************************************************/
#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include <cassert>

/************************************************
 * BINARY NODE
 * A class that represents a node in a Bianry Tree
 *     
 ***********************************************/
template <class T>
class BinaryNode
{
public:
   // Constructors
   BinaryNode() : pLeft(0x00000000), pRight(NULL), pParent(NULL), visited(false) {}
   BinaryNode(const T & theData) : data(theData), pLeft(NULL), pRight(NULL),
                                   pParent(NULL), visited(false) {}
   BinaryNode(const BinaryNode & rhs) : data(rhs.data), pLeft(rhs.pLeft), pRight(rhs.pRight),
                                        pParent(rhs.pParent), visited(rhs.visited) {}
   
   //functions
   BinaryNode <T> addLeft(T type);// throw (const char *);
   BinaryNode <T> addLeft(BinaryNode <T> *);
   BinaryNode <T> addRight(T type);//throw (const char *);
   BinaryNode <T> addRight(BinaryNode <T> *);

   bool isRightChild() const { return (this->pParent && this->pParent->pRight == this); }
   
   //member variables are public for this assignment
   T data;
   BinaryNode <T> * pLeft;
   BinaryNode <T> * pRight;
   BinaryNode <T> * pParent;
   bool visited;
};

/************************************************
 * BINARY NODE:: ADD LEFT
 *    adds a new node to the left 
 ***********************************************/
template <class T>
BinaryNode <T> BinaryNode <T>::addLeft(T type)
{
   BinaryNode <T> * node = new BinaryNode(type);
   pLeft = node;
   node->pParent = this;
   return *this;
}

/************************************************
 * BINARY NODE:: ADD LEFT
 *    adds a already existing node to the left 
 ***********************************************/
template <class T>
BinaryNode<T> BinaryNode<T>::addLeft(BinaryNode <T> * node)
{
   pLeft = node;
   node->pParent = this;
   return *this;
}

/************************************************
 * BINARY NODE:: ADD RIGHT
 *    adds a new node to the right 
 ***********************************************/
template <class T>
BinaryNode<T> BinaryNode<T>::addRight(T type)
{
   BinaryNode <T> * node = new BinaryNode(type);
   pRight = node;
   node->pParent = this;
   return *this;
}

/************************************************
 * BINARY NODE:: ADD Right
 *    adds a already existing node to the right 
 ***********************************************/
template <class T>
BinaryNode<T> BinaryNode<T>::addRight(BinaryNode * node)
{
   pRight = node;
   node->pParent = this;
   return *this;
   }

/************************************************
 * DELETE BINARY TREE
 *    deletes all children and itself
 ***********************************************/
template <class T>
void deleteBinaryTree(BinaryNode <T> * root)
{
   if (root != NULL)
   {
      deleteBinaryTree(root->pLeft);
      deleteBinaryTree(root->pRight);
      delete root;
   }
}

/************************************************
 * INSERTION OPERATOR <<
 *    displays binary tree 
 ***********************************************/
template <class T>
std::ostream & operator << (std::ostream & out, const BinaryNode <T> * node)
{
   //out << node->pLeft;
   
   if (node != NULL)
   {
      //goes through the left
      if (node->pLeft != NULL)
         out << node->pLeft;
      //displays visit
      out << node->data << " ";
      //goes through the right
      if (node->pRight != NULL)
         out <<node->pRight;
   }
   else
   {
      out << "The node is empty!";
   }
   return out;
  
}

#endif
