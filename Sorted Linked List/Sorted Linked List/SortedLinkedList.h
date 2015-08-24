#ifndef __Sorted_Linked_List__SortedLinkedList__
#define __Sorted_Linked_List__SortedLinkedList__

#include <iostream>

using namespace std;

template <class T>
class NodeType
{
public:
    
    T element;
    NodeType<T> *next;
    
};


template <class T>
class SortedList
{
private:
    
    NodeType<T> *head;
    NodeType<T> *currentPos;
    int length;
    
public:
    
    SortedList();
    ~SortedList();
    
    bool isFull();
    bool isEmpty();
    void makeEmpty();
    
    void insertItem(T);
    void deleteItem(T);
    
    void retreiveItem(T&, bool&);
    void getNextItem(T&);
    void resetList();
    
    void printList();
    void revreseList();
    
};

#endif /* defined(__Sorted_Linked_List__SortedLinkedList__) */
