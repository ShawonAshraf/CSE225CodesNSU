//
//  QueueType.cpp
//  Queue_Array
//
//  Created by Shawon Ashraf on 10/21/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#include "QueueType.h"

QueueType::QueueType()
{
    maxQueue = 6;
    front = maxQueue - 1;
    rear = maxQueue - 1;
    
    info = new ItemType[maxQueue];
    
}

QueueType::QueueType(int max)
{
    maxQueue = max + 1;
    front = maxQueue - 1;
    rear = maxQueue - 1;
    
    info = new ItemType[maxQueue];
}


QueueType::~QueueType() { delete [] info; }

void QueueType::MakeEmpty()
{
    front = maxQueue - 1;
    rear = maxQueue - 1;
}

bool QueueType::IsFull()
{
    return ((rear + 1) % maxQueue) == front;
}

bool QueueType::IsEmpty()
{
    return front == rear;
}

void QueueType::Enqueue(ItemType newItem)
{
    if(IsFull()) throw FullQueue();
    
    rear = (rear + 1) % maxQueue;
    info[rear] = newItem;
}

void QueueType::Dequeue(ItemType& item)
{
    if(IsEmpty()) throw EmptyQueue();
    
    front = (front + 1) % maxQueue;
    item = info[front];
}

