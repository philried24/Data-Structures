/**
 * @file WordListList.cpp
 * @brief Container for WordData object using a list including inherited pure virtual fns.
 */

#include <sstream>
#include <iostream>
#include <iomanip>
#include "WordListList.h"

using namespace std;

#define tabular_form 20

/*!
 * \fn WordCList
 * @brief WordCList constructor
 */
WordListList::WordListList()
{
}

/*!
 * \fn incMatch
 * @brief inputs a string and retuns a boolean if the word is already in the list. If there is a match the set is incremented.
 * @param string temp
 * @param bool returns true if the word is in the list (export)
 */
bool WordListList::incMatch(string temp)
{
    if (list1.empty())
    {
        return false;
    }
    else
    {
        ::list<WordData>::iterator itr;

        for (itr = list1.begin(); itr != list1.end() && (*itr).getWord() != temp; itr++)
        {
        }

        if (itr != list1.end())
        {
            (*itr).setCount((*itr).getCount() + 1);
            return true;
        }

        return false;
    }
}

/*!
 * \fn parseIntoList
 * @brief inserts the words in the file into a circular linked list using the insertion function of the CLinkedList.h
 * @param ifstream inf (import)
 */
void WordListList::parseIntoList(ifstream &inf)
{
    string temp;
    while (inf >> temp)
        if (!incMatch(temp))
        {
            WordData newWord;
            newWord.setWord(temp);
            newWord.setCount(1);
            list1.push_front(newWord);
        }
    inf.clear();
    inf.seekg(0);
}

/*!
 * \fn printIteratively
 * @brief print the data iteratively
 */
void WordListList::printIteratively()
{
    cout << "**** STL LIST ITERATIVE ****" << endl;
    cout << "------------------------------" << endl;
    cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
    cout << "------------------------------" << endl;

    list1.sort([](const WordData &f, const WordData &s)
               { return f.getWord() < s.getWord(); });

    for (WordData x : list1)
    {
        cout << x << '\n';
    }
}

/*!
 * \fn printRecursivelyWorker
 * @brief print the data recursively
 */
void WordListList::printRecursivelyWorker(::list<WordData>::iterator itr2, ::list<WordData>::iterator end)
{
    if (itr2 == list1.begin())
    {
        cout << "**** STL LIST RECURSIVE ****" << endl;
        cout << "------------------------------" << endl;
        cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
        cout << "------------------------------" << endl;
    }
    if (itr2 == end)
    {
        return;
    }
    cout << *itr2 << endl;
    printRecursivelyWorker(++itr2, end);
}

/*!
 * \fn printRecursively
 * @brief Call worker function to print the data recursively
 */
void WordListList::printRecursively()
{
    list1.sort([](const WordData &f, const WordData &s)
               { return f.getWord() < s.getWord(); });
    ::list<WordData>::iterator itr2;
    itr2 = list1.begin();
    ::list<WordData>::iterator end;
    end = list1.end();
    printRecursivelyWorker(itr2, end);
}