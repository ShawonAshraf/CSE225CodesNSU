//
//  bst.cpp
//  Binary Search Tree
//
//  Created by Shawon Ashraf on 11/28/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#include "bst.h"

template<class ItemType>
BST<ItemType>::BST()
{
    root = NULL;
}


template<class ItemType>
bool BST<ItemType>::isEmpty()
{
    return (root == NULL);
}


template<class ItemType>
void BST<ItemType>::insert(ItemType item)
{
    root = insert(root,item);
}


template<class ItemType>
TreeNode<ItemType> *BST<ItemType>::insert(TreeNode<ItemType> *n, ItemType item)
{
    if(n == NULL)
    {
        TreeNode<ItemType> *t=new TreeNode<ItemType>;
        t->element = item;
        t->left = NULL;
        t->right = NULL;
        n=t;
        return n;
    }
    
    if(item < n->element)
    {
        n->left = insert(n->left,item);
        return n;
    }
    
    else
    {
        n->right = insert(n->right,item);
        return n;
    }
}


template<class ItemType>
bool BST<ItemType>::find(ItemType item)
{
    bool r = find(root, item);
    return r;
}


template<class ItemType>
bool BST<ItemType>::find(TreeNode<ItemType> *n, ItemType item)
{
    if(n == NULL) return false;
    
    if(item == n->element) return true;
    
    if(item > n->element) return find(n->right,item);
    
    else return find(n->left,item);
}


template<class ItemType>
void BST<ItemType>::printInorder(ofstream &file)
{
    printInorder(root,file);
}


template<class ItemType>
void BST<ItemType>::printInorder(TreeNode<ItemType>*n,ofstream &file)
{
    if(n == NULL) return;
    
    printInorder(n->left,file);
    
    file << n->element << " ";
    
    printInorder(n->right,file);
}

template <class ItemType>
void BST<ItemType>::remove(ItemType item)
{
    root = remove(root, item);
}

template <class ItemType>
TreeNode<ItemType> *BST<ItemType>::remove(TreeNode<ItemType> *n, ItemType item)
{
    if(n == NULL) return n;
    
    if(n->left == NULL  && n->right == NULL)
    {
        delete n;
        return NULL;
    }
    
    if(item < n->element)
    {
        n->left = remove(n->left, item);
        return n;
    }
    
    if(item > n->element)
    {
        n->right = remove(n->right, item);
        return n;
    }
    
    if(n->left != NULL && n->right != NULL)
    {
        int x = findMin(n->right);
        n->element = x;
        n->right = remove(n->right, item);
        return n;
    }
    
    if(n->left != NULL)
    {
        TreeNode<ItemType> *p = n;
        n = n->right;
        delete p;
        return n;
    }
    
    TreeNode<ItemType> *p = n;
    n = n->right;
    delete p;
    return n;
}


template <class ItemType>
void BST<ItemType>::postOrder(ofstream &file)
{
    postOrder(root, file);
}


template <class ItemType>
void BST<ItemType>::postOrder(TreeNode<ItemType> *t, ofstream &file)
{
    if(t == NULL) return;
    postOrder(t->right, file);
    postOrder(t->left, file);
    file << t->element << " ";
}


template <class ItemType>
int BST<ItemType>::numLeaves()
{
    return ( numLeaves(root) - 1 );
}


template <class ItemType>
int BST<ItemType>::numLeaves(TreeNode<ItemType> *t)
{
    if( t == NULL ) return 0;
    else if( t->left == NULL && t->right == NULL ) return 1;
    else return ( numLeaves(t->left) + numLeaves(t->right) );
}


template <class ItemType>
int BST<ItemType>::findMin()
{
    return findMin(root);
}

template <class ItemType>
int BST<ItemType>::findMin(TreeNode<ItemType> *t)
{
    if(t->left == NULL) return t->element;
    return findMin(t->left);
}


template <class ItemType>
int BST<ItemType>::maxDepth()
{
    return maxDepth(root);
}

template <class ItemType>
int BST<ItemType>::maxDepth(TreeNode<ItemType> *t)
{
    int c_l, c_r;
    if(t == NULL) return 0;
    
    c_l = maxDepth(t->left);
    c_r = maxDepth(t->right);
    
    if(c_l > c_r) return (c_l + 1);
    else return (c_r + 1);
}

template <class ItemType>
void BST<ItemType>::printPaths(TreeNode<ItemType> *node, ItemType path[], int pathLength)
{
    if(root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    
    else if(node == NULL) return;
    
    path[pathLength] = node->element;
    pathLength++;
    
    if(node->left == NULL && node->right == NULL)
    {
        printArray(path, pathLength);
    }
    
    else
    {
        printPaths(node->left, path, pathLength);
        printPaths(node->right, path, pathLength);
    }
}

template <class ItemType>
void BST<ItemType>::printPaths()
{
    ItemType path[100];
    int l = 0;
    
    printPaths(root, path, l);
}


template <class ItemType>
void BST<ItemType>::printArray(ItemType path[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << path[i] << "  ";
    }
    
    cout << endl;
}



template <class ItemType>
int BST<ItemType>::lengthIs()
{
    return lengthIs(root);
}

template <class ItemType>
int BST<ItemType>::lengthIs(TreeNode<ItemType> *node)
{
    if(node == NULL) return 0;
    else
    {
        return (lengthIs(node->left) + lengthIs(node->right) + 1);
    }
}
