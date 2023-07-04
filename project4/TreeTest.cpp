/************************************************************/
/* Author:          Philipp Riedel                          */
/* Due Date:        April 30, 2023                          */
/* Course:          CSC237                                  */
/* Professor Name:  Dr. Spiegel                             */
/* Project:         #4                                      */
/* Filename:        TreeTest.cpp                            */
/* Purpose:         This program will store given numbers   */
/*                  in a binarySearchTree and the user can  */
/*                  remove nodes and print the tree.         */
/************************************************************/

/**
 * @mainpage Documentation of Project 4 (Binary Search Tree)
 * @author Philipp Riedel
 * @brief This programm will store given numbers in a Binary Search Tree and the user can remove nodes and print the tree.
 */

/**
 * @file TreeTest.cpp
 * @brief Driver for Binary Tree ADT
 */

#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

typedef BinaryTree<int> IntTree;

/*!
 * \fn getChoice
 * @brief gets what the user inputs
 */
char getChoice(string ok);

/*!
 * \fn addToTree
 * @brief Insert Value to Search Tree
 */
void addToTree(IntTree &TheTree);

/*!
 * \fn removeFromTree
 * @brief Remove Value from Search Tree
 */
void removeFromTree(IntTree &TheTree);

/*!
 * \fn change
 * @brief change value from Search Tree
 */
void change(IntTree &TheTree);

/*!
 * \fn main
 * @brief main program
 */
int main()
{
  IntTree Tree;
  int entry, *result;
  char Choice;
  do
  {
    cout << "Select: A)dd    R)emove    C)hange     P)rint     T)ree Print     Q)uit\n";
    Choice = getChoice("ARCPTQ");
    switch (Choice)
    {
    case 'A':
      addToTree(Tree);
      break;
    case 'C':
      change(Tree);
      break;
    case 'P':
      cout << "The Tree:" << endl;
      Tree.inorder();
      break;
    case 'R':
      removeFromTree(Tree);
      break;
    case 'T':
      cout << "The tree, as it appears (sort of)..\n";
      Tree.treePrint();
    }
  } while (Choice != 'Q');
}

// get the choice of the user
char getChoice(string ok)
{
  char ch = ' ';
  do
    ch = toupper(cin.get());
  while (ok.find(ch) == string::npos);
  cin.get(); // eat CR
  return (toupper(ch));
}

// Insert Value to Search Tree
void addToTree(IntTree &TheTree)
{
  int entry;
  cout << " Enter an Integer >";
  cin >> entry;
  TheTree.insertToTree(entry);
}

// Remove Value from Search Tree
void removeFromTree(IntTree &TheTree)
{
  int entry, *result;
  cout << "Value to Delete? >";
  cin >> entry;
  result = TheTree.treeSearch(entry);
  if (!result)
    cout << entry << " Not Found\n";
  else
    TheTree.deleteFromTree(entry);
}

// Change value
void change(IntTree &TheTree)
{
  int entry, *result;
  cout << "Enter the number you wish to replace: ";
  cin >> entry;
  result = TheTree.treeSearch(entry);
  if (!result)
  {
    cout << entry << " Not Found\n";
    return;
  }
  else
    TheTree.deleteFromTreeChange(entry);

  int entry2;
  cout << "What number would you like to put in place of " << entry << ": ";
  cin >> entry2;
  TheTree.insertToTree(entry2);
}