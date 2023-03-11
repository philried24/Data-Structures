// File: LinkedList.h
// Linked List class with List Iterator class

#ifndef _LinkedList_
#define _LinkedList_
#include <assert.h>
#include <iostream>

using namespace std;

// Need to prototype template classes if they are to be friends
template <typename eltType>
class LinkedList;
template <typename eltType>
class ListIterator;
/*
// and also the friend...note <> in header declaration of <<
template <typename eltType>
        ostream& operator<<(ostream&,LinkedList<eltType>);
*/

template <typename eltType>
class node
{
private:
    node(eltType info = 0, node *link = NULL) : data(info), next(link){};
    eltType data;
    node *next;
    friend class LinkedList<eltType>;
    friend class ListIterator<eltType>;
};

template <typename eltType>
class LinkedList
{
public:
    // Construct empty LinkedList
    LinkedList();
    // Construct deep copy of another LinkedList
    LinkedList(LinkedList &);

    // destroy LinkedList
    ~LinkedList();

    // Assign another LinkedList to this LinkedList; deep copy
    LinkedList &operator=(const LinkedList &);

    // Is the LinkedList empty?
    bool empty();

    bool find(eltType);

    // Ordered insert/remove
    void orderedInsert(eltType);
    void remove(eltType);

private:
    // linked list pointer
    node<eltType> *head;

    // Get a copy of a (deep) node
    node<eltType> *copy(node<eltType> *);

    // Free nodes of a linked list
    void destroy(node<eltType> *);

    // Needed to use a list iterator
    friend class ListIterator<eltType>;
};

template <typename eltType>
ostream &operator<<(ostream &os, const LinkedList<eltType> &l);

// Set up an iterator;
//	an object that provides a pointer to a linked list (in this case)
template <typename eltType>
class ListIterator
{
public:
    // Construc a List Iterator
    ListIterator(const LinkedList<eltType> &l);

    // Set curr to point at the first node of itr
    void start();
    // Is curr null?
    bool more();
    // Go to curr->next
    void next();
    // Get the value out of curr's node
    eltType value();

private:
    const LinkedList<eltType> &itr;
    node<eltType> *curr;
};

// Construct empty LinkedList
template <typename eltType>
LinkedList<eltType>::LinkedList() : head(NULL)
{
}

// Copy constructor. copy() does the deep copy
template <typename eltType>
LinkedList<eltType>::LinkedList(LinkedList<eltType> &cl)
{
    head = copy(cl.head);
}

// Free all nodes
template <typename eltType>
LinkedList<eltType>::~LinkedList()
{
    destroy(head);
}

// Assignment operator: copy() does the deep copy
template <typename eltType>
LinkedList<eltType>
    &LinkedList<eltType>::operator=(const LinkedList<eltType> &cl)
{
    if (this != &cl)
    {
        destroy(head);
        head = copy(cl.head);
    }
    return *this;
}

// Place x into the list in order
template <typename eltType>
void LinkedList<eltType>::orderedInsert(eltType x)
{
    if (empty() || x < head->data)
        assert(head = new node<eltType>(x, head));
    else // start at 2nd node...already checked first node
    {
        node<eltType> *p = head->next; // head;
        node<eltType> *trailp = head;  // NULL;
        while (p != NULL && x > p->data)
        {
            trailp = p;
            p = p->next;
        }
        assert((trailp->next = new node<eltType>(x, p)) != NULL);
    }
}

// Is this element in the linked list?
template <typename eltType>
bool LinkedList<eltType>::find(eltType x)
{
    node<eltType> *p = head;
    while (p != NULL && p->data != x)
        p = p->next;
    return (p != NULL && p->data == x);
}

// Inline: Look into this.
template <typename eltType>
inline bool LinkedList<eltType>::empty()
{
    return (head == NULL);
}

// Remove a node in an ordered list
// Pre: Node will be found
template <typename eltType>
void LinkedList<eltType>::remove(eltType x)
{
    assert(!empty());
    node<eltType> *p = head;
    node<eltType> *trailp = NULL;
    while (p != NULL && p->data != x)
    {
        trailp = p;
        p = p->next;
    }
    assert(p != NULL); // x is not in the LinkedList
    if (p == head)
        head = head->next; // x is first in the LinkedList
    else
        trailp->next = p->next; // x is farther down in the LinkedList
    delete p;
}

// Remove all nodes in the linked list, starting at l
template <typename eltType>
void LinkedList<eltType>::destroy(node<eltType> *l)
{
    while (l != NULL)
    {
        node<eltType> *doomed = l;
        l = l->next;
        delete doomed;
    }
}

// The deep copy. Copy the source list l, one node at a time
template <typename eltType>
node<eltType> *LinkedList<eltType>::copy(node<eltType> *l)
{
    node<eltType> *first = NULL; // ptr to beginning of copied LinkedList
    node<eltType> *last = NULL;  // ptr to last item insert in the copy
    if (l != NULL)
    {
        assert((first = last = new node<eltType>(l->data, NULL)) != NULL);
        for (node<eltType> *source = l->next; source != NULL;
             source = source->next, last = last->next)
        {
            last->next = new node<eltType>(source->data, NULL);
            assert(last->next);
        }
    }
    return first;
}

// Output a linked list, using a list iterator
template <typename eltType>
ostream &operator<<(ostream &os, const LinkedList<eltType> &l)
{
    ListIterator<eltType> lt(l);
    for (lt.start(); lt.more(); lt.next())
        os << lt.value() << " ";
    return os;
}

/* ****************************************************************
 ************** List Iterator Implementations *******************
 ****************************************************************/

// Construct a list iterator. It consists of:
//	 a reference to a linked list object
//	 a pointer to the actual list, initially pointing to its head
template <typename eltType>
ListIterator<eltType>::ListIterator(const LinkedList<eltType> &l) : itr(l), curr(l.head)
{
}

// Set curr to point at itr's head
template <typename eltType>
void ListIterator<eltType>::start(void)
{
    curr = itr.head;
}

// Is curr at the end of the list?
template <typename eltType>
bool ListIterator<eltType>::more(void)
{
    return curr != NULL;
}

// Move curr to next node
template <typename eltType>
void ListIterator<eltType>::next(void)
{
    assert(curr != NULL);
    curr = curr->next;
}

// Return data in curr's node. Regardless of assert(), this
//	function shouldn't be called until making sure more() returns true
template <typename eltType>
eltType ListIterator<eltType>::value(void)
{
    assert(curr != NULL);
    return curr->data;
}

#endif