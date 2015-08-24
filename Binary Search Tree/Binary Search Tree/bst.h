//
//  bst.h
//  Binary Search Tree
//
//  Created by Shawon Ashraf on 11/28/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#ifndef __Binary_Search_Tree__bst__
#define __Binary_Search_Tree__bst__

#include <iostream>
#include <fstream>

using namespace std;


template<class ItemType>
class TreeNode
{
public:
    ItemType element;
    TreeNode *left;
    TreeNode *right;
};


template<class ItemType>
class BST
{
public:
    
    BST();
    bool isEmpty();
    void insert(ItemType);
    void remove(ItemType);
    bool find(ItemType);
    void printInorder(ofstream &file);
    
    void postOrder(ofstream &file);
    int findMin();
    int numLeaves();
    int maxDepth();
    
    void printPaths();
    
    int lengthIs();
    
private:
    
    TreeNode<ItemType> *root;
    
    TreeNode<ItemType> *insert(TreeNode<ItemType> *n,ItemType);
    TreeNode<ItemType> *remove(TreeNode<ItemType> *n,ItemType);
    bool find(TreeNode<ItemType> *n,ItemType);
    void printInorder(TreeNode<ItemType> *n, ofstream &file);
    
    void postOrder(TreeNode<ItemType> *t, ofstream &file);
    int findMin(TreeNode<ItemType> *t);
    int numLeaves(TreeNode<ItemType> *t);
    int maxDepth(TreeNode<ItemType> *t);
    
    
    void printPaths(TreeNode<ItemType> *node, ItemType path[], int pathLength);
    void printArray(ItemType path[], int length);
    
    int lengthIs(TreeNode<ItemType> *node);
    
};




#endif /* defined(__Binary_Search_Tree__bst__) */
