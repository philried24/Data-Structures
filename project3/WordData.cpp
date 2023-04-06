/**
 * @file WordData.cpp
 * @brief Creating the WordData object for using it in the project to count words in a .txt file.
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;

/*!
 * \fn WordData
 * @brief WordData constructor
 */

WordData::WordData(string wrd, int cnt)
{
    setWordData(wrd, cnt);
}

/*!
 * \fn setWord
 * @brief setter for the word
 * @param string wrd (input)
 */
void WordData::setWord(string wrd)
{
    word = wrd;
}
/*!
 * \fn setCount
 * @brief setter for the count
 * @param int cnt (input)
 */
void WordData::setCount(int cnt)
{
    count = cnt;
}

/*!
 * \fn setWordData
 * @brief setter for the count and the word
 * @param int cnt (input)
 * @param string wrd (input)
 */
void WordData::setWordData(string wrd, int cnt)
{
    setWord(wrd);
    setCount(cnt);
}

/*!
 * \fn getWord
 * @brief getter for the word
 * @param string word (export)
 */
string WordData::getWord() const
{
    return (word);
}

/*!
 * \fn getCount
 * @brief getter for the count
 * @param int count (export)
 */
int WordData::getCount() const
{
    return (count);
}

/*!
 * \fn incCount
 * @brief increment the count
 * @param int inc (import)
 */
void WordData::incCount(int inc)
{
    count += inc;
}

/*!
 * \fn operator<<
 * @brief << operator to output the WordData objects
 * @param ostream output (input/export)
 * @param WordData words (input)
 */
ostream &operator<<(ostream &output, const WordData &words)
{
    output << words.getWord() << "\t\t" << words.getCount();
    return output;
}

/*!
 * \fn operator>
 * @brief > operator to compare and then store the WordData objects alphabetically (ascending)
 * @param bool true/false (export)
 * @param WordData words (input)
 */
bool WordData::operator>(const WordData &words)
{
    if ((*this).getWord() > words.getWord())
    {
        return true;
    }
    return false;
}