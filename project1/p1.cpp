/************************************************************/
/* Author:          Philipp Riedel                          */
/* Creation Date:   February 3, 2023                        */
/* Due Date:        February 12, 2023                       */
/* Course:          CSC237                                  */
/* Professor Name:  Dr. Spiegel                             */
/* Project:         #1                                      */
/* Filename:        p1.cpp                                  */
/* Purpose:         This program will read a given text     */
/*                  file and count the number of occurrences*/
/*                  with several different data structures. */
/************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "WordData.cpp"
#include <vector>

using namespace std;

#define capacity 10
#define tabular_form 20

/*****************************************************************/
/*    Function name:   parallel                                  */
/*                                                               */
/*    Description:     Will count the number of occurrences and  */
/*                     store the string and the int in a parallel*/
/*                     array.                                    */
/*                                                               */
/*    Parameters:      ifstream &file3 - file                    */
/*                     string names1[] - array with the string   */
/*                     words                                     */
/*                     int count[] - array with the number of    */
/*                     occurrences                               */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/

void parallel(ifstream &file3, string names1[], int count[]);

/*****************************************************************/
/*    Function name:   parallel_iterative                        */
/*                                                               */
/*    Description:     Will call the parallel function and will  */
/*                     output the result iteratively.            */
/*                                                               */
/*    Parameters:      ifstream &file2 - file                    */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/

void parallel_iterative(ifstream &file2);

/*****************************************************************/
/*    Function name:   parallel_recursive                        */
/*                                                               */
/*    Description:     Will call the parallel function and will  */
/*                     call the output_recursion function.       */
/*                                                               */
/*    Parameters:      ifstream &file2 - file                    */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/

void parallel_recursive(ifstream &file2);

/*****************************************************************/
/*    Function name:   parallel_recursion                        */
/*                                                               */
/*    Description:     Will output the words and the occurrences */
/*                     recursively.                              */
/*                                                               */
/*    Parameters:      int n - counts the number of iterations   */
/*                     string names2[] - saves the words         */
/*                     int count2[] - saves the occurrences      */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/

void parallel_recursion(int n, string names2[], int count2[]);

/*****************************************************************/
/*    Function name:   object_array                              */
/*                                                               */
/*    Description:     Will count the number of occurrences and  */
/*                     store them in an object array.            */
/*                                                               */
/*    Parameters:      ifstream &file - file                     */
/*                     WordData array[] - array with WordData    */
/*                     objects.                                  */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/

void object_array(ifstream &file, WordData array[]);

/*****************************************************************/
/*    Function name:   object_array_iterative                    */
/*                                                               */
/*    Description:     Will output the words and the occurrences */
/*                     of the object array iteratively.          */
/*                                                               */
/*    Parameters:      ifstream &file - file                     */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/

void object_array_iterative(ifstream &file);

/*****************************************************************/
/*    Function name:   object_array_recursive                    */
/*                                                               */
/*    Description:     Will call the object_array function and   */
/*                     object_array_recursion function.          */
/*                                                               */
/*    Parameters:      ifstream &file - file                     */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/

void object_array_recursive(ifstream &file);

/*****************************************************************/
/*    Function name:   object_array_recursion                    */
/*                                                               */
/*    Description:     Will output the words and the occurrences */
/*                     of the object array recursively.          */
/*                                                               */
/*    Parameters:      int n - counts the number of iterations   */
/*                     WordData array[] - object array           */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/

void object_array_recursion(int n, WordData array[]);

/*****************************************************************/
/*    Function name:   object_array_pointer                      */
/*                                                               */
/*    Description:     Will output the words and the occurrences */
/*                     of the object array with a pointer.       */
/*                                                               */
/*    Parameters:      ifstream &file - file                     */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/

void object_array_pointer(ifstream &file);

/*****************************************************************/
/*    Function name:   sequential_container                      */
/*                                                               */
/*    Description:     Will count the number of occurrences and  */
/*                     store them in a sequential container      */
/*                     (vector).                                 */
/*                                                               */
/*    Parameters:      ifstream &file - file                     */
/*                     vector<WordData> &vector1 - vector with   */
/*                     informations to words and occurrences.    */
/*                                                               */
/*    Return Value:    vector<WordData>                          */
/*****************************************************************/

vector<WordData> sequential_container(ifstream &file, vector<WordData> &vector1);

/*****************************************************************/
/*    Function name:   sequential_container_indexing             */
/*                                                               */
/*    Description:     Will output the words and the occurrences */
/*                     stored in the sequential container        */
/*                     with indexing.                            */
/*                                                               */
/*    Parameters:      ifstream &file - file                     */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/

void sequential_container_indexing(ifstream &file);

/*****************************************************************/
/*    Function name:   sequential_container_iterator             */
/*                                                               */
/*    Description:     Will output the words and the occurrences */
/*                     stored in the sequential container        */
/*                     with an iterator.                         */
/*                                                               */
/*    Parameters:      ifstream &file - file                     */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/

void sequential_container_iterator(ifstream &file);

int main(int argc, char **argv)
{
    string filename;
    int input;
    int end;
    end = 0;

    if (argc > 1)
    {
        filename = argv[1];
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Not able to open the textfile" << endl;
            return 1;
        }

        parallel_iterative(file);
        parallel_recursive(file);
        object_array_iterative(file);
        object_array_recursive(file);
        object_array_pointer(file);
        sequential_container_indexing(file);
        sequential_container_iterator(file);

        file.close();
        cout << "EXIT\n";
        exit(0);
    }

    else
    {
        cout << "Please enter a filename. \n";
        cin >> filename;
        ifstream file(filename);

        if (!file.is_open())
        {
            cout << "Not able to open the textfile" << endl;
            return 1;
        }

        while (end == 0)
        {
            cout << "Enter a number, 1-8, to choose from the menu below: \n";
            cout << "1: PARALLEL ITERATIVE\n";
            cout << "2: PARALLEL RECURSIVE\n";
            cout << "3: OBJECT ARRAY ITERATIVE\n";
            cout << "4: OBJECT ARRAY RECURSIVE\n";
            cout << "5: OBJECT ARRAY POINTER\n";
            cout << "6: SEQ CONTAINER INDEXING\n";
            cout << "7: SEQ CONTAINER ITERATOR\n";
            cout << "8: EXIT\n";
            cout << "Choice entered: ";
            cin >> input;

            switch (input)
            {
            case 1:
                parallel_iterative(file);
                break;
            case 2:
                parallel_recursive(file);
                break;
            case 3:
                object_array_iterative(file);
                break;
            case 4:
                object_array_recursive(file);
                break;
            case 5:
                object_array_pointer(file);
                break;
            case 6:
                sequential_container_indexing(file);
                break;
            case 7:
                sequential_container_iterator(file);
                break;
            case 8:
                file.close();
                cout << "EXIT\n";
                exit(0);
            }
        }
        return 1;
    }
}

void parallel(ifstream &file3, string names1[], int count[])
{
    string word;
    while (file3 >> word)
    {
        bool found;
        found = false;
        for (int i = 0; i < capacity; i++)
        {
            if (names1[i] == word)
            {
                count[i]++;
                found = true;
                break;
            }
        }

        if (found == false)
        {
            for (int i = 0; i < capacity; i++)
            {
                if (names1[i].empty())
                {
                    names1[i] = word;
                    count[i] = 1;
                    break;
                }
            }
        }
    }
    file3.clear();
    file3.seekg(0, ios::beg);
}

void parallel_iterative(ifstream &file2)
{

    cout << "**** PARALLEL ITERATIVE ****" << endl;

    string names1[capacity];
    int count[capacity];

    parallel(file2, names1, count);

    int length;

    cout << "------------------------------" << endl;
    cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
    cout << "------------------------------" << endl;

    for (int j = 0; j < capacity; j++)
    {
        if (!names1[j].empty())
        {
            length = tabular_form - names1[j].length();
            cout << names1[j] << setw(length) << count[j] << endl;
        }
    }
}

void parallel_recursion(int n, string names2[], int count2[])
{
    if (n == 0)
    {
        cout << "**** PARALLEL RECURSION ****" << endl;
        cout << "------------------------------" << endl;
        cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
        cout << "------------------------------" << endl;
    }
    int length;

    if (!names2[n].empty() && n < 10)
    {
        length = tabular_form - names2[n].length();
        cout << names2[n] << setw(length) << count2[n] << endl;
        n = n + 1;
        parallel_recursion(n, names2, count2);
    }
}

void parallel_recursive(ifstream &file2)
{
    string names1[capacity];
    int count[capacity];

    parallel(file2, names1, count);

    int n;
    n = 0;
    parallel_recursion(n, names1, count);
}

void object_array(ifstream &file, WordData array[])
{
    string word;
    while (file >> word)
    {
        bool found;
        found = false;
        for (int i = 0; i < capacity; i++)
        {
            if (array[i].getWord() == word)
            {
                array[i].setCount(array[i].getCount() + 1);
                found = true;
                break;
            }
        }

        if (found == false)
        {
            for (int i = 0; i < capacity; i++)
            {
                if (array[i].getCount() == 0)
                {
                    array[i].setWord(word);
                    array[i].setCount(1);
                    break;
                }
            }
        }
    }
    file.clear();
    file.seekg(0, ios::beg);
}

void object_array_iterative(ifstream &file)
{
    WordData array[capacity];
    int length;
    object_array(file, array);
    cout << "**** OBJECT ARRAY ITERATIVE ****" << endl;
    cout << "------------------------------" << endl;
    cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
    cout << "------------------------------" << endl;
    for (int j = 0; j < capacity; j++)
    {
        if (array[j].getCount() > 0)
        {
            length = tabular_form - array[j].getWord().length();
            cout << array[j].getWord() << setw(length) << array[j].getCount() << endl;
        }
    }
}

void object_array_recursion(int n, WordData array[])
{
    if (n == 0)
    {
        cout << "**** OBJECT ARRAY RECURSION ****" << endl;
        cout << "------------------------------" << endl;
        cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
        cout << "------------------------------" << endl;
    }

    int length;

    if (array[n].getCount() > 0 && n < capacity)
    {
        length = tabular_form - array[n].getWord().length();
        cout << array[n].getWord() << setw(length) << array[n].getCount() << endl;
        n = n + 1;
        object_array_recursion(n, array);
    }
}

void object_array_recursive(ifstream &file2)
{
    WordData array[capacity];

    object_array(file2, array);

    int n;
    n = 0;
    object_array_recursion(n, array);
}

void object_array_pointer(ifstream &file)
{
    WordData array[capacity];
    int length;
    object_array(file, array);
    cout << "**** OBJECT ARRAY POINTER ****" << endl;
    cout << "------------------------------" << endl;
    cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
    cout << "------------------------------" << endl;
    WordData *pointer[capacity];
    for (int i = 0; i < capacity; i++)
    {
        pointer[i] = new WordData(array[i]);
    }
    for (int x = 0; x < capacity; x++)
    {
        if (pointer[x]->getCount() > 0)
        {
            length = tabular_form - pointer[x]->getWord().length();
            cout << pointer[x]->getWord() << setw(length) << pointer[x]->getCount() << endl;
        }
    }
}

vector<WordData> sequential_container(ifstream &file, vector<WordData> &vector1)
{
    string word;

    while (file >> word)
    {
        bool found = false;
        for (int i = 0; i < capacity; i++)
        {
            if (i < vector1.size() && vector1.at(i).getWord() == word)
            {
                vector1.at(i).setCount(vector1.at(i).getCount() + 1);
                found = true;
                break;
            }
        }
        if (found == false && vector1.size() < capacity)
        {
            WordData push;
            push.setWord(word);
            push.setCount(1);
            vector1.push_back(push);
        }
    }

    return vector1;
}

void sequential_container_indexing(ifstream &file)
{
    vector<WordData> vector1;
    int length;

    cout << "**** SEQ CONTAINER INDEXING ****" << endl;
    cout << "------------------------------" << endl;
    cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
    cout << "------------------------------" << endl;

    sequential_container(file, vector1);

    for (int j = 0; j < vector1.size(); j++)
    {
        if (vector1.at(j).getCount() > 0)
        {
            length = tabular_form - vector1.at(j).getWord().length();
            cout << vector1.at(j).getWord() << setw(length) << vector1.at(j).getCount() << endl;
        }
    }
    file.clear();
    file.seekg(0, ios::beg);
}

void sequential_container_iterator(ifstream &file)
{
    vector<WordData> vector1;
    int length;

    cout << "**** SEQ CONTAINER ****" << endl;
    cout << "------------------------------" << endl;
    cout << "Word" << setw(tabular_form) << "Occurrences" << endl;
    cout << "------------------------------" << endl;

    sequential_container(file, vector1);

    vector<WordData>::iterator it;
    for (it = vector1.begin(); it != vector1.end(); ++it)
    {
        if (it->getCount() > 0)
        {
            length = tabular_form - it->getWord().length();
            cout << it->getWord() << setw(length) << it->getCount() << endl;
        }
    }

    file.clear();
    file.seekg(0, ios::beg);
}