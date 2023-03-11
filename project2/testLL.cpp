/**
 * @mainpage Documentation of the circular linked list implementation.
 * @author Philipp Riedel
 * @brief This program can insert and remove an integer into a circular linked list
 * and print forward and print backward this circular linked list.
 * \n
 * date: 2023-03-09
 * \n
 * Due Date: 2023-03-12
 * \n
 * Professor Name: Dr. Spiegel
 * \n
 * Project: #2
 * \n
 * Course: CSC237
 * \n
 */

/**
 * @file testLL.cpp
 * @brief This is the test driver. The user can add and remove elements or can print the list backwards or forwards
 */

#include <iostream>
#include <stdlib.h>
#include "CLinkedList.h"

CLinkedList<int> clinkedlist;

/*!
 * \fn insertion
 * @brief calls the insert function in the CLinkedList.h
 */
int insertion();

/*!
 * \fn remove
 * @brief calls the remove function in the CLinkedList.h
 */
int remove();

/**
 * \fn printforward
 * @brief calls the printForward function in the CLinkedList.h
 */
int printforward();

/**
 * \fn printbackward
 * @brief calls the printBackward function in the CLinkedList.h
 */
int printbackward();

/*!
 * \fn menu
 * @brief generates the menu options for the user
 **************************************************************************/
int menu();

int main()
{
    menu();
    return 1;
}

int insertion()
{
    int input;
    cout << "What number would you like to insert? \n";
    cin >> input;
    if (cin.fail())
    {
        cout << "Invalid number \n";
        cin.clear();
        cin.ignore(10, '\n');
        insertion();
    }
    else
    {
        clinkedlist.insert(input);
    }
    return 1;
}

int remove()
{
    int input;
    cout << "What number would you like to remove? \n";
    cin >> input;
    if (cin.fail())
    {
        cout << "Invalid number \n";
        cin.clear();
        cin.ignore(10, '\n');
        insertion();
    }
    else
    {
        clinkedlist.remove(input);
    }
    return 1;
}

int printforward()
{
    clinkedlist.printForward();
    return 1;
}

int printbackward()
{
    CListItr<int> lt1(clinkedlist);
    clinkedlist.printBackward(lt1);
    return 1;
}

int menu()
{
    string input;
    int end;
    end = 0;

    while (end == 0)
    {
        cout << "\n";
        cout << "Choose from the following: \n";
        cout << "I - Insert Integer \n";
        cout << "R - Remove Integer \n";
        cout << "F - Forward Print \n";
        cout << "B - Backward Print \n";
        cout << "E - Exit \n";
        cout << "**************************************** \n";
        cin >> input;

        if (input == "I" || input == "i")
        {
            insertion();
        }
        else if (input == "R" || input == "r")
        {
            remove();
        }
        else if (input == "F" || input == "f")
        {
            printforward();
        }
        else if (input == "B" || input == "b")
        {
            printbackward();
        }
        else if (input == "E" || input == "e")
        {
            exit(0);
            end = 1;
        }
        else
        {
            cout << "Invalid menu choice \n";
        }
    }
    return 1;
}