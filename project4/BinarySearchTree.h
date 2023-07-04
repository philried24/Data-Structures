// File: BinarySearchTree.h
// Binary Tree ADT defined using Linked Structures

/**
 * @file BinarySearchTree.h
 * @brief Binary Tree ADT defined using Linked Structures (header file)
 */
#ifndef TREE_H
#define TREE_H

template <typename treeEltType>
class BinaryTree;

/*!
 * \class TreeNode
 * @brief TreeNode class
 */
template <typename eltType>
class TreeNode
{
private:
    eltType info;
    int count;
    TreeNode<eltType> *left, *right;
    TreeNode(const eltType &data, const int &count2 = 0, TreeNode<eltType> *lChild = NULL, TreeNode *rChild = NULL)
    {
        count = count2;
        info = data;
        left = lChild;
        right = rChild;
    }

    friend class BinaryTree<eltType>;
};

/*!
 * \class BinaryTree
 * @brief BinaryTree class
 */
template <typename treeEltType>
class BinaryTree
{

public:
    // Constructor
    BinaryTree();

    // Place Element into Tree
    // Returns 1 if inserted, 0 if Data already in tree
    int insertToTree(const treeEltType &data);

    // Search for Element in Tree
    // Assumes == is defined for treeEltType
    // Returns pointer to data, or NULL, according to success
    treeEltType *treeSearch(const treeEltType &data);

    // Retrieve Element from Tree (leaving Tree Intact)
    // Precondition: Item is in Tree
    treeEltType &retrieveFromTree(const treeEltType &data);

    // Remove an Element from the tree
    // Pre: Element is in the Tree
    void deleteFromTree(const treeEltType &data);

    // Display Tree using InOrder Traversal
    void inorder() const;

    // Display Tree using PreOrder Traversal
    void preorder() const;

    // Display Tree using PostOrder Traversal
    void postorder() const;

    // Breadth first print
    void treePrint() const;

    // Remove an Element from the tree
    // Pre: Element is in the Tree
    void deleteFromTreeChange(const treeEltType &data);

private:
    TreeNode<treeEltType> *root;

    // Display Tree using InOrder Traversal
    void printInorder(TreeNode<treeEltType> *) const;

    // Display Tree using PreOrder Traversal
    void printPreorder(TreeNode<treeEltType> *) const;

    // Display Tree using PostOrder Traversal
    void printPostorder(TreeNode<treeEltType> *) const;

    void treePrintHelper(TreeNode<treeEltType> *) const;
};

#endif