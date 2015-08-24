//
//  StackLinked.h
//  Stack Linked List
//
//  Created by Shawon Ashraf on 11/9/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#ifndef __Stack_Linked_List__StackLinked__
#define __Stack_Linked_List__StackLinked__

template <class T>
class StackNode
{
public:
    T element;
    StackNode<T> *next;
};

template <class T>
class Stack
{
public:
    
    Stack();
    ~Stack();
    bool IsEmpty();
    void MakeEmpty();
    void Push(T);
    void Pop();
    T Top();
    T TopPop();
    void Print();
    int Length();
    void ReverseStack();
    
private:
    
    StackNode<T> *head;
    int length;
};


#endif /* defined(__Stack_Linked_List__StackLinked__) */
