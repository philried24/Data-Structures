/**
 * @file WordList.h
 * @brief Abstract base class for containers of word data. Known subclasses: WordDataList, WordListList, WordCList
 */

#ifndef WORDLIST_H
#define WORDLIST_H

#include <fstream>
#include <string>

using namespace std;

/**
 * @class WordList
 * @brief This is the base class for containers of WordData
 */

class WordList
{
public:
    /*!
     * \fn parseIntoList
     * @brief inserts the words in the file into the data structure
     * @param ifstream inf (import)
     */
    virtual void parseIntoList(ifstream &inf) = 0;

    /*!
     * \fn printIteratively
     * @brief print the data iteratively
     */
    virtual void printIteratively() = 0;

    /*!
     * \fn printRecursively
     * @brief Call worker function to print the data recursively
     */
    virtual void printRecursively() = 0;

    /*!
     * \fn printPtr
     * @brief call worker function to print the data recursively with a pointer
     */
    virtual void printPtr() {}
};

#endif