/************************************************************/
/* Author:          Philipp Riedel                          */
/* Due Date:        April 5, 2023                           */
/* Course:          CSC237                                  */
/* Professor Name:  Dr. Spiegel                             */
/* Project:         #3                                      */
/* Filename:        app.cpp                                 */
/* Purpose:         This program will read a given text     */
/*                  file and count the number of occurrences*/
/*                  with 3 different data structures using  */
/*                  inheritance and polymorphism.           */
/************************************************************/

/**
 * @mainpage Documentation of Project 3 (Inheritance and Polymorphism)
 * @author Philipp Riedel
 * @brief This program inputs a string and demonstrates how to store it using subclasses
 * (Array, Circular Linked List and a STL List is used) of an abstract base class that
 * incorporates virtual functions to enable polymorphism.
 * It will read a given text file and count the number of occurrences. This can be done by interacting with the command line
 * or it can be run in batch mode.
 * \n
 * Date: 2023-04-05
 * \n
 * Due Date: 2023-04-05
 * \n
 * Professor Name: Dr. Spiegel
 * \n
 * Project: #3
 * \n
 * Course: CSC237
 * \n
 */

/**
 * @file app.cpp
 * @brief This is the application for the programm with the menu and all possible options
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cmath>
#include "WordList.h"
#include "WordDataList.h"
// #include "WordData.h" //app only knows about the lists !
#include "WordCList.h"
#include "WordListList.h"

using namespace std;

using namespace chrono;
/*!
 * \fn displayMenu
 * @brief displays the menu with all possible options
 */
void displayMenu();

/*!
 * \fn printArrayIterative
 * @brief prints the words and the occurences stored in the array iteratively
 * @param inf - the ifstream of the inserted textfile
 * @param TheList - the array of objects
 */

void printArrayIterative(ifstream &inf, WordList *TheList);

/*!
 * \fn printArrayRecursive
 * @brief prints the words and the occurences stored in the array recursively
 * @param inf - the ifstream of the inserted textfile
 * @param TheList - the array of objects
 */
void printArrayRecursive(ifstream &inf, WordList *TheList);

/*!
 * \fn printArrayPointer
 * @brief prints the words and the occurences stored in the array with a pointer
 * @param inf - the ifstream of the inserted textfile
 * @param TheList - the array of objects
 */
void printArrayPointer(ifstream &inf, WordList *TheList);

/*!
 * \fn printCListIterative
 * @brief prints the words and the occurences stored in the circular linked list iteratively
 * @param inf - the ifstream of the inserted textfile
 * @param TheList - the circular linked list of objects
 */
void printCListIterative(ifstream &inf, WordList *TheList);

/*!
 * \fn printCListRecursive
 * @brief prints the words and the occurences stored in the circular linked list recursively
 * @param inf - the ifstream of the inserted textfile
 * @param TheList - the circular linked list of objects
 */
void printCListRecursive(ifstream &inf, WordList *TheList);

/*!
 * \fn printListIterative
 * @brief prints the words and the occurences stored in a list iteatively
 * @param inf - the ifstream of the inserted textfile
 * @param TheList - list of objects
 */
void printListIterative(ifstream &inf, WordList *TheList);

/*!
 * \fn printListRecursive
 * @brief prints the words and the occurences stored in a list recursively
 * @param inf - the ifstream of the inserted textfile
 * @param TheList - list of objects
 */
void printListRecursive(ifstream &inf, WordList *TheList);

/*!
 * \fn main
 * @brief main program
 */
int main(int argc, char *argv[])
{
    ifstream inf;
    WordList *TheList;
    if (argc > 1) // if there was an input on the command line
    {
        inf.open(argv[1]); // try and open the file
        if (inf.fail())    // if the file does not open
        {                  // terminate
            cout << "Sorry, the file failed to open." << endl;
            return 0;
        }
        WordList *TheList1a = new WordDataList;
        WordList *TheList1b = new WordDataList;
        WordList *TheList1c = new WordDataList;
        WordList *TheList2a = new WordCList;
        WordList *TheList2b = new WordCList;
        WordList *TheList3a = new WordListList;
        WordList *TheList3b = new WordListList;
        printArrayIterative(inf, TheList1a);
        printArrayRecursive(inf, TheList1b);
        printArrayPointer(inf, TheList1c);
        printCListIterative(inf, TheList2a);
        printCListRecursive(inf, TheList2b);
        printListIterative(inf, TheList3a);
        printListRecursive(inf, TheList3b);
        return 0;
    }

    char selection;
    string fileName;
    cout << "Please enter a file name:" << endl;
    getline(cin, fileName);
    inf.open(fileName.c_str());

    while (true)
    {
        displayMenu();
        cin >> selection;
        switch (selection)
        {
        case '1':
        {
            TheList = new WordDataList;
            printArrayIterative(inf, TheList);
            break;
        }
        case '2':
        {
            TheList = new WordDataList;
            printArrayRecursive(inf, TheList);
            break;
        }
        case '3':
        {
            TheList = new WordDataList;
            printArrayPointer(inf, TheList);
            break;
        }
        case '4':
        {
            TheList = new WordCList;
            printCListIterative(inf, TheList);
            break;
        }
        case '5':
        {
            TheList = new WordCList;
            printCListRecursive(inf, TheList);
            break;
        }
        case '6':
        {
            TheList = new WordListList;
            printListIterative(inf, TheList);
            break;
        }
        case '7':
        {
            TheList = new WordListList;
            printListRecursive(inf, TheList);
            break;
        }
        case '8':
            cout << "Goodbye" << endl;
            return 0;
        default:
            cout << "I cannot understand " << selection << ".  Try again." << endl;
            break;
        }
    }

    return 0;
}

void displayMenu()
{
    cout << endl;
    cout << "How do you want to print your sentence elements?" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Enter a number, 1-8, to choose from the menu below: \n";
    cout << "1: OBJECT ARRAY ITERATIVE\n";
    cout << "2: OBJECT ARRAY RECURSIVE\n";
    cout << "3: OBJECT ARRAY POINTER ONLY\n";
    cout << "4: CIRCULAR LIST ITERATOR\n";
    cout << "5: CIRCULAR LIST ITERATOR RECURSIVE\n";
    cout << "6: STL LIST ITERATIVE\n";
    cout << "7: STL LIST RECURSIVE\n";
    cout << "8: EXIT\n";
}

void printArrayIterative(ifstream &inf, WordList *TheList)
{
    auto beginParse = high_resolution_clock::now();
    TheList->parseIntoList(inf);
    auto endParse = high_resolution_clock::now();
    auto beginPrint = high_resolution_clock::now();
    TheList->printIteratively();
    auto endPrint = high_resolution_clock::now();
    auto ticksParse = duration_cast<microseconds>(endParse - beginParse);
    auto ticksPrint = duration_cast<microseconds>(endPrint - beginPrint);
    cout << "------------------------------------------------" << endl;
    cout << "It took: " << ticksParse.count() << " microseconds to parse the list \n";
    cout << "It took: " << ticksPrint.count() << " microseconds to print the result \n";
}

void printArrayRecursive(ifstream &inf, WordList *TheList)
{
    auto beginParse = high_resolution_clock::now();
    TheList->parseIntoList(inf);
    auto endParse = high_resolution_clock::now();
    auto beginPrint = high_resolution_clock::now();
    TheList->printRecursively();
    auto endPrint = high_resolution_clock::now();
    auto ticksParse = duration_cast<microseconds>(endParse - beginParse);
    auto ticksPrint = duration_cast<microseconds>(endPrint - beginPrint);
    cout << "------------------------------------------------" << endl;
    cout << "It took: " << ticksParse.count() << " microseconds to parse the list \n";
    cout << "It took: " << ticksPrint.count() << " microseconds to print the result \n";
}

void printArrayPointer(ifstream &inf, WordList *TheList)
{
    auto beginParse = high_resolution_clock::now();
    TheList->parseIntoList(inf);
    auto endParse = high_resolution_clock::now();
    auto beginPrint = high_resolution_clock::now();
    TheList->printPtr();
    auto endPrint = high_resolution_clock::now();
    auto ticksParse = duration_cast<microseconds>(endParse - beginParse);
    auto ticksPrint = duration_cast<microseconds>(endPrint - beginPrint);
    cout << "------------------------------------------------" << endl;
    cout << "It took: " << ticksParse.count() << " microseconds to parse the list \n";
    cout << "It took: " << ticksPrint.count() << " microseconds to print the result \n";
}

void printCListIterative(ifstream &inf, WordList *TheList)
{
    auto beginParse = high_resolution_clock::now();
    TheList->parseIntoList(inf);
    auto endParse = high_resolution_clock::now();
    auto beginPrint = high_resolution_clock::now();
    TheList->printIteratively();
    auto endPrint = high_resolution_clock::now();
    auto ticksParse = duration_cast<microseconds>(endParse - beginParse);
    auto ticksPrint = duration_cast<microseconds>(endPrint - beginPrint);
    cout << "------------------------------------------------" << endl;
    cout << "It took: " << ticksParse.count() << " microseconds to parse the list \n";
    cout << "It took: " << ticksPrint.count() << " microseconds to print the result \n";
}

void printCListRecursive(ifstream &inf, WordList *TheList)
{
    auto beginParse = high_resolution_clock::now();
    TheList->parseIntoList(inf);
    auto endParse = high_resolution_clock::now();
    auto beginPrint = high_resolution_clock::now();
    TheList->printRecursively();
    auto endPrint = high_resolution_clock::now();
    auto ticksParse = duration_cast<microseconds>(endParse - beginParse);
    auto ticksPrint = duration_cast<microseconds>(endPrint - beginPrint);
    cout << "------------------------------------------------" << endl;
    cout << "It took: " << ticksParse.count() << " microseconds to parse the list \n";
    cout << "It took: " << ticksPrint.count() << " microseconds to print the result \n";
}

void printListIterative(ifstream &inf, WordList *TheList)
{
    auto beginParse = high_resolution_clock::now();
    TheList->parseIntoList(inf);
    auto endParse = high_resolution_clock::now();
    auto beginPrint = high_resolution_clock::now();
    TheList->printIteratively();
    auto endPrint = high_resolution_clock::now();
    auto ticksParse = duration_cast<microseconds>(endParse - beginParse);
    auto ticksPrint = duration_cast<microseconds>(endPrint - beginPrint);
    cout << "------------------------------------------------" << endl;
    cout << "It took: " << ticksParse.count() << " microseconds to parse the list \n";
    cout << "It took: " << ticksPrint.count() << " microseconds to print the result \n";
}

void printListRecursive(ifstream &inf, WordList *TheList)
{
    auto beginParse = high_resolution_clock::now();
    TheList->parseIntoList(inf);
    auto endParse = high_resolution_clock::now();
    auto beginPrint = high_resolution_clock::now();
    TheList->printRecursively();
    auto endPrint = high_resolution_clock::now();
    auto ticksParse = duration_cast<microseconds>(endParse - beginParse);
    auto ticksPrint = duration_cast<microseconds>(endPrint - beginPrint);
    cout << "------------------------------------------------" << endl;
    cout << "It took: " << ticksParse.count() << " microseconds to parse the list \n";
    cout << "It took: " << ticksPrint.count() << " microseconds to print the result \n";
}