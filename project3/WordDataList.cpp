/**
 * @file WordDataList.cpp
 * @brief Container for WordData objects using an array including inherited pure virtual fns.
 */

#include <sstream>
#include <iostream>
#include <iomanip>
#include "WordDataList.h"

using namespace std;

#define tabular_form 20

/*!
 * \fn WordDataList
 * @brief WordDataList constructor
 */
WordDataList::WordDataList()
{
    numWords = 0;
}

/*!
 * \fn incMatch
 * @brief inputs a string and returns a boolean if the word is already in the array. If a match is found the count is going to increment.
 * @param string temp
 * @param bool returns true if the word is in the array - otherwise false (export)
 */
bool WordDataList::incMatch(string temp)
{
    for (int i = 0; i < numWords; i++)
    {
        if (temp == TheWords[i].getWord())
        {
            TheWords[i].incCount();
            return true;
        }
    }
    return false;
}

/*!
 * \fn parseIntoList
 * @brief inserts the words in the file into an array
 * @param ifstream inf (import)
 */
void WordDataList::parseIntoList(ifstream &inf)
{
    string temp;
    while (inf >> temp)
        if (!incMatch(temp) && numWords < 10)
        {
            TheWords[numWords].setWord(temp);
            TheWords[numWords++].setCount(1);
        }
    inf.clear();
    inf.seekg(0);
}

/*!
 * \fn printIteratively
 * @brief print the data iteratively
 */
void WordDataList::printIteratively()
{
    cout << "**** OBJECT ARRAY ITERATIVE ****" << endl;
    cout << "------------------------------" << endl;
    cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < numWords; i++)
        cout << " " << TheWords[i] << endl;
}

/*!
 * \fn printRecursivelyWorker
 * @brief print the data recursively
 */
void WordDataList::printRecursivelyWorker(int numWords)
{
    if (numWords == 1)
    {
        cout << "**** OBJECT ARRAY RECURSIVE ****" << endl;
        cout << "------------------------------" << endl;
        cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
        cout << "------------------------------" << endl;
        cout << " " << TheWords[numWords - 1] << endl;
        return;
    }
    printRecursivelyWorker(numWords - 1);
    cout << " " << TheWords[numWords - 1] << endl;
}

/*!
 * \fn printRecursively
 * @brief Call worker function to print the data recursively
 */
void WordDataList::printRecursively()
{
    printRecursivelyWorker(numWords);
}

/*!
 * \fn printPtrWorker
 * @brief print the data recursively with a pointer
 */
void WordDataList::printPtrWorker(int numWords)
{
    if (!numWords)
    {
        cout << "**** OBJECT ARRAY POINTER ONLY ****" << endl;
        cout << "------------------------------" << endl;
        cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
        cout << "------------------------------" << endl;
        return;
    }
    printPtrWorker(numWords - 1);
    cout << " " << *(TheWords + (numWords - 1)) << endl;
}

/*!
 * \fn printPtr
 * @brief call worker function to print the data recursively with a pointer
 */
void WordDataList::printPtr()
{
    printPtrWorker(numWords);
}