//
//  QueueType.h
//  Queue Linked List
//
//  Created by Shawon Ashraf on 10/26/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#ifndef __Queue_Linked_List__QueueType__
#define __Queue_Linked_List__QueueType__

#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType *next;
};

class FullQueue {};
class EmptyQueue {};

template <class ItemType>
class QueueType {
private:
    NodeType<ItemType> *front;
    NodeType<ItemType> *rear;
    
public:
    QueueType();
    ~QueueType();
    
    void MakeEmpty();
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
    
    bool IsEmpty();
    bool IsFull();
    
    void Print();
    void ReverseQue(QueueType<ItemType> &qu);
};

#endif /* defined(__Queue_Linked_List__QueueType__) */
