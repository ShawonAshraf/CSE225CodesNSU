//
//  QueueType.h
//  Queue_Array
//
//  Created by Shawon Ashraf on 10/21/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#ifndef __Queue_Array__QueueType__
#define __Queue_Array__QueueType__

#include "ItemType.h"
#include <iostream>
using namespace std;

class FullQueue
{
public:
    FullQueue() { cout << "Queue is full" << endl; }
};

class EmptyQueue
{
public:
    EmptyQueue() { cout << "Queue is empty" << endl; }
};

class QueueType
{
private:
    
    int front;
    int rear;
    ItemType *info;
    int maxQueue;
    
public:
    QueueType();
    QueueType(int max);
    ~QueueType();
    void MakeEmpty();
    bool IsFull();
    bool IsEmpty();
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
    // void PrintQueue();
};

#endif /* defined(__Queue_Array__QueueType__) */
