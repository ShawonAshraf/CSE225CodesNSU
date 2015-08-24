#include "SortedLinkedList.h"


template <class T>
SortedList<T>::SortedList()
{
    head = NULL;
    currentPos = NULL;
    length = 0;
}

template <class T>
SortedList<T>::~SortedList()
{
    makeEmpty();
}

template <class T>
bool SortedList<T>::isEmpty()
{
    return (head == NULL);
}

template <class T>
bool SortedList<T>::isFull()
{
    try
    {
        NodeType<T> *t = new NodeType<T>;
        delete t;
        t = NULL;
        
        return false;
    }
    
    catch(bad_alloc e)
    {
        return true;
    }
}

template <class T>
void SortedList<T>::makeEmpty()
{
    if(isEmpty()) return;
    
    else
    {
        while(!isEmpty())
        {
            NodeType<T> *t = new NodeType<T>;
            
            t = head;
            head = head->next;
            
            delete t;
            t = NULL;
        }
    }
}


template <class T>
void SortedList<T>::insertItem(T item)
{
    NodeType<T> *loc;
    NodeType<T> *pred;
    NodeType<T> *newNode;
    
    loc = new NodeType<T>;
    loc = head;
    
    pred = NULL;
    
    while(loc != NULL)
    {
        if(loc->element < item)
        {
            pred = loc;
            loc = loc->next;
        }
        
        else break;
    }
    
    newNode = new NodeType<T>;
    newNode->element = item;

    if(pred == NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        newNode->next = loc;
        pred->next = newNode;
    }
    
    length++;
}


template <class T>
void SortedList<T>::deleteItem(T item)
{
    NodeType<T> *loc;
    NodeType<T> *t;
    
    loc = new NodeType<T>;
    t = NULL;
    
    loc = head;
    
    if(item == (head->next)->element)
    {
        t = head;
        head = head->next;
    }
    
    else
    {
        while(!(item == (loc->next)->element))
        {
            loc = loc->next;
        }
        t = loc->next;
        loc->next = loc->next->next;
    }
    
    delete t;
    t = NULL;
    
    length--;
}

template <class T>
void SortedList<T>::retreiveItem(T& item, bool& found)
{
    found = false;
    bool moreToSearch;
    
    NodeType<T> *t = new NodeType<T>;
    t = head;
    
    moreToSearch = (t != NULL);
    
    while(moreToSearch && !found)
    {
        if(item == t->element) found = true;
        else
        {
            t = t->next;
            moreToSearch = (t != NULL);
        }
    }
}

template <class T>
void SortedList<T>::getNextItem(T& item)
{
    if(currentPos == NULL) currentPos = head;
    else currentPos = currentPos->next;
    
    item = currentPos->element;
}

template <class T>
void SortedList<T>::resetList()
{
    currentPos = NULL;
}

template <class T>
void SortedList<T>::printList()
{
    NodeType<T> *t = new NodeType<T>;
    
    t = head;
    
    while(t != NULL)
    {
        cout << t->element << " ";
        t = t->next;
    }
    cout << endl;
}

template <class T>
void SortedList<T>::revreseList()
{
    NodeType<T> *current;
    NodeType<T> *next;
    NodeType<T> *prev;
    
    current = head;
    next = NULL;
    prev = NULL;
    
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        
        prev = current;
        
        current = next;
    }
    
    head = prev;
}