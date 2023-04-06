/*!	\file WordCList.h
 * 	\brief Header file for the WordCList.cpp file
 */

#ifndef WORDCLIST_H
#define WORDCLIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"
#include "CLinkedList.h"

using namespace std;

/**
 * @class WordCList
 * @brief With the WordCList class it is possible to create a circular linked list with WordData objects
 */

class WordCList : public WordList
{
public:
    /*!
     * \fn WordCList
     * @brief WordCList constructor
     */
    WordCList();

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
    CLinkedList<WordData> clinkedlist;

    /*!
     * \fn incMatch
     * @brief inputs a string and retuns a boolean if the word is already in the list
     * @param string temp
     * @param bool returns true if the word is in the list (export)
     */
    bool incMatch(string temp);

    /*!
     * \fn printRecursivelyWorker
     * @brief print the data recursively
     */
    void printRecursivelyWorker(CListItr<WordData> lt);
};

#endif