// File: Application.cpp
// Test the template ordered linked list object type

#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
    LinkedList<int> l1, l2;
    int x;

    // build a couple of lists
    for (x = 0; x < 30; x += 3)
    {
        l1.orderedInsert(x);
    }
    cout << "list1: " << l1 << endl;

    for (x = 0; x < 25; x += 2)
    {
        l2.orderedInsert(x);
    }

    cout << "Original lists" << endl;
    cout << "list1: " << l1 << endl;
    cout << "list2: " << l2 << endl;
    cout << endl;

    LinkedList<int> l3(l1); // copy LinkedList 1 using a copy constructor

    LinkedList<int> l4; // copy LinkedList 2 using an assignment operator
    l4 = l2;

    cout << "Copies of the LinkedLists" << endl;
    cout << "LinkedList3: " << l3 << endl;
    cout << "LinkedList4: " << l4 << endl;
    cout << endl;

    cout << "15 is " << (l1.find(15) ? "" : "not ") << "in LinkList 1" << endl;
    cout << "16 is " << (l1.find(16) ? "" : "not ") << "in LinkList 1" << endl;
    cout << endl;

    cout << "remove item 12 from LinkedList 1" << endl;
    cout << "before: " << l1 << endl;
    l1.remove(12);
    cout << "after: " << l1 << endl;
    cout << endl;

    // use a list iterator to move through the LinkedList
    ListIterator<int> lt1(l1);

    cout << "LinkedList contents: ";
    for (lt1.start(); lt1.more(); lt1.next())
    {
        cout << lt1.value() << " ";
    }
    cout << endl;
    cout << endl;

    /*
    // uncomment to test your code

    l3 = l1 + l2;

    cout << "Concatenated list (l1+l2): " << l3 << endl;
    cout << endl;

    l3.sort();

    cout << "Ordered list: " << l3 << endl;
    */

    return (0);
}