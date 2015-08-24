//
//  PriorityQueue.h
//  Priority Queue using Heap
//
//  Created by Shawon Ashraf on 12/11/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#ifndef __Priority_Queue_using_Heap__PriorityQueue__
#define __Priority_Queue_using_Heap__PriorityQueue__

#include <iostream>
#include <algorithm> 
#include <queue>
#include <stack>


using namespace std;


template<class ItemType>
struct HeapType
{
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);
    ItemType* elements;
    int numElements;
};


template <class ItemType>
void Swap(ItemType& one, ItemType& two)
{
    swap(one, two);
}


template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
{
    int parent;
    
    if (bottom > root)
    {
        parent = (bottom-1) / 2;
        if (elements[parent] < elements[bottom])
        {
            Swap(elements[parent], elements[bottom]);
            ReheapUp(root, parent);
        }
    }
}


template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
{
    int maxChild, rightChild = root*2+2, leftChild = root*2+1;
    if (leftChild <= bottom) //there is at least one child
    {
        if (leftChild == bottom) //it is the only child
            maxChild = leftChild;
        else //there are two children
        {
            if (elements[leftChild] <= elements[rightChild])
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }
        if (elements[root] < elements[maxChild])
        {
            Swap(elements[root], elements[maxChild]);
            ReheapDown(maxChild, bottom);
        }
    }
}



class FullPQ{};
class EmptyPQ{};

template<class ItemType>
class PQType
{
public:
    PQType(int);
    ~PQType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
private:
    int length;
    HeapType<ItemType> items;
    int maxItems;
};

template<class ItemType>
PQType<ItemType>::PQType(int max)
{
    maxItems = max;
    items.elements = new ItemType[max];
    length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
    delete [] items.elements;
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
    length = 0;
}

template<class ItemType>
bool PQType<ItemType>::IsFull()
{
    return length == maxItems;
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty()
{
    return length == 0;
}


template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
{
    if (length == 0)
        throw EmptyPQ();
    else
    {
        item = items.elements[0];
        items.elements[0] = items.elements[length-1];
        length--;
        items.ReheapDown(0, length-1);
    }
}


template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
{
    if (length == maxItems)
        throw FullPQ();
    else
    {
        length++;
        items.elements[length-1] = newItem;
        items.ReheapUp(0, length-1);
    }
}


#endif /* defined(__Priority_Queue_using_Heap__PriorityQueue__) */
