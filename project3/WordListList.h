/**	\file WordListList.h
 * 	\brief List container
 */

#ifndef WORDLISTLIST_H
#define WORDLISTLIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"
#include <list>

using namespace std;

/**
 * @class WordListList
 * @brief With the WordListList class it is possible to create a list with WordData objects
 */

class WordListList : public WordList
{
public:
    /*!
     * \fn WordCList
     * @brief WordCList constructor
     */
    WordListList();

    /*!
     * \fn parseIntoList
     * @brief inserts the words in the file into a circular linked list using the insertion function of the CLinkedList.h
     * @param ifstream inf (import)
     */
    virtual void parseIntoList(ifstream &inf);

    /*!
     * \fn printIteratively
     * @brief print the data iteratively
     */
    virtual void printIteratively();

    /*!
     * \fn printRecursively
     * @brief Call worker function to print the data recursively
     */
    virtual void printRecursively();

private:
    list<WordData> list1;

    /*!
     * \fn incMatch
     * @brief inputs a string and retuns a boolean if the word is already in the list. If there is a match the set is incremented.
     * @param string temp
     * @param bool returns true if the word is in the list (export)
     */
    bool incMatch(string temp);

    /*!
     * \fn printRecursivelyWorker
     * @brief print the data recursively
     */
    void printRecursivelyWorker(::list<WordData>::iterator itr2, ::list<WordData>::iterator end);
};

#endif