//
//  StackLinked.cpp
//  Stack Linked List
//
//  Created by Shawon Ashraf on 11/9/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#include "StackLinked.h"
#include <iostream>

using namespace std;

template <class T>
Stack<T>::Stack()
{
    head = NULL;
    length = 0;
}

template <class T>
Stack<T>::~Stack()
{
    MakeEmpty();
}

template <class T>
bool Stack<T>::IsEmpty()
{
    return (head == NULL);
}

template <class T>
void Stack<T>::MakeEmpty()
{
    while(!IsEmpty()) Pop();
    length = 0;
}


template <class T>
void Stack<T>::Push(T item)
{
    if(head == NULL)
    {
        StackNode<T> *t = new StackNode<T>;
        
        t->element = item;
        t->next = NULL;
        head = t;
        
        length++;
        return;
    }
    
    else
    {
        StackNode<T> *t = new StackNode<T>;
        
        t->element = item;
        t->next = head;
        head = t;
        
        length++;
        return;
    }
}


template <class T>
void Stack<T>::Pop()
{
    if(IsEmpty()) cout << "Stack is Empty!" << endl;
    else
    {
        StackNode<T> *t = new StackNode<T>;
        
        t = head;
        head = head->next;
        delete t;
        t = NULL;
        return;
    }
    
    length--;
}


template <class T>
T Stack<T>::Top()
{
    return head->element;
}


template <class T>
T Stack<T>::TopPop()
{
    T it = head->element;
    Pop();
    return it;
}

template <class T>
void Stack<T>::Print()
{
    StackNode<T> *t = new StackNode<T>;
    
    t = head;
    while(t != NULL)
    {
        cout << t->element << " ";
        t = t->next;
    }
    cout << endl;
    delete t;
    t = NULL;
}

template <class T>
int Stack<T>::Length()
{
    return length;
}

template <class T>
void Stack<T>::ReverseStack()
{
    StackNode<T> *current, *next, *prev;
    
    current = new StackNode<T>;
    next = NULL;
    prev = NULL;
    
    current = head;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}