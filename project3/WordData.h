/**
 * @file WordData.h
 * @brief header file for the WordData.cpp
 */

#ifndef WORDDATA_H
#define WORDDATA_H
#include <iostream>
#include <string>

using namespace std;

/**
 * @class WordData
 * @brief With the WordData class it is possible to create WordData objects
 */
class WordData
{

public:
    /*!
     * \fn WordData
     * @brief WordData constructor
     */
    WordData(string wrd = "", int cnt = 1);

    /*!
     * \fn setWord
     * @brief setter for the word
     * @param string wrd (input)
     */
    void setWord(string wrd);
    /*!
     * \fn setCount
     * @brief setter for the count
     * @param int cnt (input)
     */
    void setCount(int cnt);

    /*!
     * \fn setWordData
     * @brief setter for the count and the word
     * @param int cnt (input)
     * @param string wrd (input)
     */
    void setWordData(string, int);

    /*!
     * \fn getWord
     * @brief getter for the word
     * @param string word (export)
     */
    string getWord() const;
    /*!
     * \fn getCount
     * @brief getter for the count
     * @param int count (export)
     */
    int getCount() const;

    /*!
     * \fn incCount
     * @brief increment the count
     * @param int inc (import)
     */
    void incCount(int inc = 1);

    /*!
     * \fn operator>
     * @brief > operator to compare and then store the WordData objects alphabetically (ascending)
     * @param bool true/false (export)
     * @param WordData words (input)
     */
    bool operator>(const WordData &words);

private:
    // variables
    string word;
    int count;
};

/*!
 * \fn operator<<
 * @brief << operator to output the WordData objects
 * @param ostream output (input/export)
 * @param WordData words (input)
 */
ostream &operator<<(ostream &output, const WordData &words);

#endif