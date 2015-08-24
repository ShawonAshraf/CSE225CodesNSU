//
//  QueueType.cpp
//  Queue Linked List
//
//  Created by Shawon Ashraf on 10/26/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#include "QueueType.h"

template <class ItemType>
QueueType<ItemType>::QueueType()
{
    front = NULL;
    rear = NULL;
}

template <class ItemType>
QueueType<ItemType>::~QueueType()
{
    MakeEmpty();
}

template <class ItemType>
void QueueType<ItemType>::MakeEmpty()
{
    NodeType<ItemType> *temp;
    
    while(front != NULL)
    {
        temp = new NodeType<ItemType>;
        temp = front;
        front = front->next;
        delete temp;
        temp = NULL;
    }
    
    rear = NULL;
}

template <class ItemType>
bool QueueType<ItemType>::IsEmpty()
{
    return (front == NULL);
}

template <class ItemType>
bool QueueType<ItemType>::IsFull()
{
    NodeType<ItemType> *location;
    
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        location = 0;
        
        return false;
    }
    
    catch(bad_alloc e)
    {
        return true;
    }
}

template <class ItemType>
void QueueType<ItemType>::Enqueue(ItemType newItem)
{
    if(IsFull()) throw FullQueue();
    else
    {
        
        NodeType<ItemType> *newNode;
        newNode = new NodeType<ItemType>;
        
        newNode->info = newItem;
        newNode->next = NULL;
        
        if(rear == NULL) front = newNode;
        else rear->next = newNode;
        
        rear = newNode;
    }
}

template <class ItemType>
void QueueType<ItemType>::Dequeue(ItemType& item)
{
    if(IsEmpty()) throw EmptyQueue();
    else
    {
        NodeType<ItemType> *temp;
        
        temp = front;
        item = front->info;
        front = front->next;
        
        if(front == NULL) rear = NULL;
        delete temp;
        temp = NULL;
    }
}

template <class ItemType>
void QueueType<ItemType>::Print()
{
    cout << "Queue : ";
    
    NodeType<ItemType> *it;
    
    for(it = front; it != NULL; it = it->next)
    {
        cout << it->info << " ";
    }
    cout << endl;
}


template <class ItemType>
void QueueType<ItemType>::ReverseQue(QueueType<ItemType> &qu)
{
    NodeType<ItemType> *current, *next, *prev;
    
    current = new NodeType<ItemType>;
    next = new NodeType<ItemType>;
    prev = new NodeType<ItemType>;
    
    
    current = front;
    prev = NULL;
    next = NULL;
    
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    front = prev;
}