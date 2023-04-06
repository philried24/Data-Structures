/**
 * @file WordCList.cpp
 * @brief Container for WordData object using a circular linked list including inherited pure virtual fns.
 */

#include <sstream>
#include <iostream>
#include <iomanip>
#include "WordCList.h"
#include "CLinkedList.h"

using namespace std;

#define tabular_form 20

/*!
 * \fn WordCList
 * @brief WordCList constructor
 */
WordCList::WordCList()
{
}

/*!
 * \fn incMatch
 * @brief inputs a string and retuns a boolean if the word is already in the list
 * @param string temp
 * @param bool returns true if the word is in the list (export)
 */
bool WordCList::incMatch(string temp)
{
    CListItr<WordData> lt(clinkedlist);
    if (!lt.isEmpty())
    {
        for (lt.begin(); !lt.isLastNode(); ++lt)
        {
            if (temp == (*lt).getWord())
            {
                WordData match;
                WordData newWord2;
                match = (*lt);
                int i = 1;
                i = ((*lt).getCount() + 1);
                newWord2.setWord((*lt).getWord());
                newWord2.setCount(i);
                (*lt).setCount(i);
                return true;
            }
        }
        if (lt.isLastNode() && temp == (*lt).getWord())
        {
            WordData match;
            WordData newWord2;
            match = (*lt);
            int i = 1;
            i = ((*lt).getCount() + 1);
            newWord2.setWord((*lt).getWord());
            newWord2.setCount(i);
            (*lt).setCount(i);
            return true;
        }
        return false;
    }
    return false;
}

/*!
 * \fn parseIntoList
 * @brief inserts the words in the file into a circular linked list using the insertion function of the CLinkedList.h
 * @param ifstream inf (import)
 */

void WordCList::parseIntoList(ifstream &inf)
{
    string temp;
    while (inf >> temp)
    {
        if (!incMatch(temp))
        {
            WordData newWord;
            newWord.setWord(temp);
            newWord.setCount(1);
            clinkedlist.insert(newWord);
        }
    }
    inf.clear();
    inf.seekg(0);
}

/*!
 * \fn printIteratively
 * @brief print the data iteratively
 */
void WordCList::printIteratively()
{
    cout << "**** CIRCULAR LINKED LIST ITERATIVE ****" << endl;
    cout << "------------------------------" << endl;
    cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
    cout << "------------------------------" << endl;
    clinkedlist.printForward();
}

/*!
 * \fn printRecursivelyWorker
 * @brief print the data recursively
 */
void WordCList::printRecursivelyWorker(CListItr<WordData> lt)
{
    if (lt.isFirstNode())
    {
        cout << "**** CIRCULAR LINKED LIST RECURSIVE ****" << endl;
        cout << "------------------------------" << endl;
        cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
        cout << "------------------------------" << endl;
        cout << *lt << endl;
        printRecursivelyWorker(++lt);
    }
    else if (!lt.isLastNode())
    {
        cout << *lt << endl;
        printRecursivelyWorker(++lt);
    }
    else if (lt.isLastNode())
    {
        cout << *lt << endl;
        return;
    }
    return;
}

/*!
 * \fn printRecursively
 * @brief Call worker function to print the data recursively
 */
void WordCList::printRecursively()
{
    CListItr<WordData> lt(clinkedlist);
    ++lt;
    printRecursivelyWorker(lt);
}