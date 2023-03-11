/*!	\file Node.h
 * 	\brief Node definition/implementation \n
 *
 */

#ifndef NODE_H
#define NODE_H

// Need to prototype template classes if they are to be friends
template <typename eltType>
class CLinkedList;
template <typename eltType>
class CListItr;

/*!	\class Node
 * 	\brief Node definition/implementation \n
 */

template <typename eltType>
class Node
{
private: // changed this from private to public
	Node(eltType info, Node *link = NULL) : data(info), next(link){};
	eltType data;
	Node *next;
	friend class CLinkedList<eltType>;
	friend class CListItr<eltType>;
};

#endif
