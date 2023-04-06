/**
 * @file WordDataList.h
 * @brief Container for WordData objects using an array including inherited pure virtual fns.
 */

#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"

using namespace std;

/**
 * @class WordDataList
 * @brief With the WordDataList class it is possible to create an array with WordData objects
 */

class WordDataList : public WordList
{
public:
    /*!
     * \fn WordDataList
     * @brief WordDataList constructor
     */
    WordDataList();
    /*!
     * \fn parseIntoList
     * @brief inserts the words in the file into an array
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

    /*!
     * \fn printPtr
     * @brief call worker function to print the data recursively with a pointer
     */
    virtual void printPtr();

private:
    WordData TheWords[10];
    int numWords;

    /*!
     * \fn incMatch
     * @brief inputs a string and returns a boolean if the word is already in the array. If a match is found the count is going to increment.
     * @param string temp
     * @param bool returns true if the word is in the array - otherwise false (export)
     */
    bool incMatch(string temp);

    /*!
     * \fn printRecursivelyWorker
     * @brief print the data recursively
     */
    void printRecursivelyWorker(int numWords);

    /*!
     * \fn printPtrWorker
     * @brief print the data recursively with a pointer
     */
    void printPtrWorker(int numWords);
};

#endif