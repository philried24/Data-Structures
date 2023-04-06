/*!	\file CLinkedList.h
 * 	\brief contains Circular Linked List class with Circular Link List Iterator class.
 */

#ifndef _CLinkedList_
#define _CLinkedList_
#include <assert.h>
#include <iostream>
#include "Node.h"

using namespace std;

template <typename eltType>
class CLinkedList;
template <typename eltType>
class CListItr;

/**
 * @class CLinkedList
 * @brief With the CLinkedList class you can create a circular linked list that has no null pointer.
 *
 * Unless it is empty, each node points to the next node, and the last node points to the first node.
 */
template <typename eltType>
class CLinkedList
{
public:
    /*!
     * \fn CLinkedList Constructor
     * Construct empty CLinkedList
     **************************************************************************/
    CLinkedList();
    /*!
     * \fn Copy Constructor
     * Construct deep copy of another CLinkedList
     * Parameter: CLinkedList (import/export)
     **************************************************************************/
    CLinkedList(CLinkedList &);
    /*!
     * \fn Destructor
     * destroys CLinkedList
     **************************************************************************/
    ~CLinkedList();
    /*!
     * Assignment Operator
     * Assign another CLinkedList to this CLinkedList
     **************************************************************************/
    CLinkedList &operator=(const CLinkedList &);
    /*!
     * returns true if the linked list is empty and false if it is not
     * \n
     * Member Type: Inspector
     * \n
     * Parameter: bool (export)
     **************************************************************************/
    bool empty();
    /*!
     * inserts the data given into the circular linked list
     * \n
     * Member Type: Mutator
     * \n
     * Parameter: eltType (import)
     * @param eltype inserted data
     **************************************************************************/
    void insert(eltType);
    /*!
     * removes the data given from the circular linked list
     * \n
     * Member Type: Mutator
     * \n
     * Parameter: eltType (import)
     * \n
     * @param eltype the data that should be removed
     **************************************************************************/
    void remove(eltType);
    /*!
     * prints the circular linked list forwards
     * \n
     * Member Type: Facilitator
     **************************************************************************/
    void printForward();
    /*!
     * prints the circular linked list backwards
     * \n
     * Member Type: Facilitator
     * \n
     * Parameter: CListItr (import)
     **************************************************************************/
    void printBackward(CListItr<eltType> itr);

private:
    /*!
     *	a pointer that points to the last node in the circular linked list
     */
    Node<eltType> *last;
    /*!
     *	get a copy of a node
     */
    Node<eltType> *copy(Node<eltType> *);

    /*!
     *	free all nodes of the circular linked list
     */
    void destroy(Node<eltType> *);

    /*!
     *	circular linked list iterator
     */
    friend class CListItr<eltType>;
};

/**
 * @class CListItr
 * @brief Creates an iterator for the circular linked list
 */
template <typename eltType>
class CListItr
{
public:
    /*!
     * \fn CListItr Constructor
     **************************************************************************/
    CListItr(const CLinkedList<eltType> &l);
    /*!
     * isEmpty
     * Checks if the circular linked list is empty
     * Return: true/false (export)
     **************************************************************************/
    bool isEmpty();
    /*!
     * begin
     * sets curr pointer to the point of the first node of itr
     **************************************************************************/
    void begin();
    /*!
     * isFirstNode
     * returns whether or not the node is the first node
     * Return value: true/false (export)
     **************************************************************************/
    bool isFirstNode();
    /*!
     * isLastNode
     * returns whether or not the node is the last node
     * Return value: true/false (export)
     **************************************************************************/
    bool isLastNode();
    /*!
     * operator*
     * returns the data of the node currently pointing at
     * Return value: teltType (export)
     **************************************************************************/
    eltType &operator*();
    /*!
     * operator++
     * pre-increment operator advances the pointer to the next node in the list, if there is one
     **************************************************************************/
    CListItr<eltType> operator++();
    /*!
     * operator++(int)
     * post-increment operator advances the pointer to the next node in the list, if there is one
     **************************************************************************/
    CListItr<eltType> operator++(int);

private:
    const CLinkedList<eltType> &itr;
    Node<eltType> *curr;
};

template <typename eltType>
CLinkedList<eltType>::CLinkedList() : last(NULL)
{
}

template <typename eltType>
CLinkedList<eltType>::CLinkedList(CLinkedList<eltType> &cl)
{
    last = copy(cl.last);
}

template <typename eltType>
CLinkedList<eltType>::~CLinkedList()
{
    destroy(NULL);
}

template <typename eltType>
CLinkedList<eltType>
    &CLinkedList<eltType>::operator=(const CLinkedList<eltType> &cl)
{
    if (this != &cl)
    {
        destroy(NULL);
        last = copy(cl.last);
    }
    return *this;
}

// Place x into the list
template <typename eltType>
void CLinkedList<eltType>::insert(eltType x)
{

    if (empty())
    {
        Node<eltType> *p = new Node<eltType>(x, NULL);
        p->next = p;
        last = p;
    }
    else if (x > last->data)
    {
        last->next = new Node<eltType>(x, last->next);
        last = last->next;
    }
    else
    {
        Node<eltType> *start1 = last->next;
        Node<eltType> *last1 = last;
        while (x > start1->data)
        {
            start1 = start1->next;
            last1 = last1->next;
        }
        last1->next = new Node<eltType>(x, start1);
    }
}

template <typename eltType>
inline bool CLinkedList<eltType>::empty()
{
    return (last == NULL);
}

// Remove a Node in an ordered list
// Pre: Node will be found
template <typename eltType>
void CLinkedList<eltType>::remove(eltType x)
{
    assert(!empty());
    Node<eltType> *p = last->next;
    Node<eltType> *trailp = last;
    Node<eltType> *test = p;
    while (p != last && p->data != x)
    {
        trailp = p;
        p = p->next;
    }
    eltType p1;
    p1 = p->data;
    if (p == last && p1 != x)
    {
        cout << x << " not found \n";
        return;
    }
    if (p != last && p->data == x)
    {
        test = p;
        test = test->next;
        delete p;
        trailp->next = test;
        cout << x << " is removed \n";
        return;
    }
    if (p == last && p->data == x)
    {
        test = p;
        test = test->next;
        last = trailp;
        delete p;
        trailp->next = test;
        cout << x << " is removed \n";
        return;
    }
}

// Remove all Nodes in the linked list, starting at l
template <typename eltType>
void CLinkedList<eltType>::destroy(Node<eltType> *l)
{
    if (l != last)
    {
        if (l == NULL)
        {
            l = last->next;
        }
        Node<eltType> *doomed = l;
        l = l->next;
        delete doomed;
        destroy(l);
    }
    else if (l == last && last != NULL)
    {
        delete l;
    }
}

// The deep copy. Copy the source list l, one Node at a time
template <typename eltType>
Node<eltType> *CLinkedList<eltType>::copy(Node<eltType> *l)
{
    Node<eltType> *first1 = NULL;
    Node<eltType> *last1 = NULL;
    if (l != NULL)
    {
        assert((first1 = last1 = new Node<eltType>(l->data, NULL)) != NULL);
        for (Node<eltType> *source = l->next; source != last;
             source = source->next, last1 = last1->next)
        {
            last1->next = new Node<eltType>(source->data, NULL);
            assert(last->next);
        }
        last1->next = first1;
    }
    return first1;
}

template <typename eltType>
void CLinkedList<eltType>::printForward()
{
    CListItr<eltType> lt(*this);
    if (lt.isEmpty())
    {
        cout << "The list is empty, nothing to print";
    }
    else
    {
        for (lt.begin(); !lt.isLastNode(); ++lt)
        {
            cout << *lt << " \n";
            // cout << " " << (*lt).getWord() << " " << (*lt).getCount() << endl;
        }
        cout << *lt << " \n";
    }
}

template <typename eltType>
void CLinkedList<eltType>::printBackward(CListItr<eltType> itr)
{
    CListItr<eltType> lt(*this);
    itr++;
    if (!(itr.isLastNode()))
    {
        printBackward(itr);
    }
    cout << *itr << " ";
}

/* **************************************************************
 ************** List Iterator Implementations *******************
 ****************************************************************/

template <typename eltType>
CListItr<eltType>::CListItr(const CLinkedList<eltType> &l) : itr(l), curr(l.last)
{
}

template <typename eltType>
void CListItr<eltType>::begin(void)
{
    curr = itr.last;
    if (curr != NULL)
    {
        curr = curr->next;
    }
}

template <typename eltType>
bool CListItr<eltType>::isEmpty()
{
    if (curr == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename eltType>
bool CListItr<eltType>::isFirstNode()
{
    assert(curr != NULL);
    if (curr == itr.last->next)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename eltType>
bool CListItr<eltType>::isLastNode()
{
    assert(curr != NULL);
    if (curr == itr.last)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename eltType>
eltType &CListItr<eltType>::operator*()
{
    assert(curr != NULL);
    return curr->data;
}

template <typename eltType>
CListItr<eltType> CListItr<eltType>::operator++()
{
    if (curr != NULL)
    {
        curr = curr->next;
    }
    return *this;
}

template <typename eltType>
CListItr<eltType> CListItr<eltType>::operator++(int)
{
    CListItr<eltType> lt1(itr);

    if (curr != NULL)
    {
        while (lt1 != curr)
        {
            ++lt1;
        }
        curr = curr->next;
    }

    return lt1;
}

#endif