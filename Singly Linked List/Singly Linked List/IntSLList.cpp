#include "IntSLList.h"
#include <iostream>

using namespace std;


IntSLList::IntSLList()
{
    head = tail = NULL;
}


IntSLList::~IntSLList()
{
    for (IntSLNode *p; !isEmpty();){
        p = head->next;
        delete head;
        head = p;
    }
}

int IntSLList::isEmpty()
{
    return head == 0;
}

void IntSLList::addToHead(int el)
{
    head = new IntSLNode(el, head);
    if (tail == 0) tail = head;
}

void IntSLList::addToTail(int el)
{
    // if list is not empty
    
    if (tail != NULL){
        tail->next = new IntSLNode(el);
        tail = tail->next;
    }
    else head = tail = new IntSLNode(el);
}

int IntSLList::deleteFromHead()
{
    int el = head->info;
    IntSLNode *tmp = head;
    
    // if there's only one node in the list
    
    if (head == tail) head = tail = NULL;
    else head = head->next;
    delete tmp;
    
    return el;
}


int IntSLList::deleteFromTail()
{
    int el = tail->info;
    
    if (head == tail){
        delete head;
        head = tail = NULL;
    }
    else{
        IntSLNode *tmp;
        
        for (tmp = head; tmp->next != tail; tmp = tmp->next);
        
        delete tail;
        tail = tmp;
        tail->next = NULL;
    }
    
    return el;
}

void IntSLList::deleteNode(int el)
{
    if (head != NULL){
        if (head == tail && el == head->info){
            delete head;
            head = tail = NULL;
        }
        else if(el == head->info){
            IntSLNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        else{
            IntSLNode *pred, *tmp;
            for (pred = head, tmp = head->next; tmp != NULL && !(tmp->info == el); );
            if (tmp != NULL){
                pred->next = tmp->next;
                if (tmp == tail) tail = pred;
                delete tmp;
            }
            
        }
    }
}

bool IntSLList::isInList(int el) const
{
    IntSLNode *tmp;
    for (tmp = head; tmp != NULL && !(tmp->info == el); tmp = tmp->next);
    return tmp != NULL;
}

void IntSLList::display()
{
    IntSLNode *i = head;
    
    if (i == NULL) cout << "EMPTY LIST" << endl;
    else{
        cout << "Contents of the list :   ";
        while (i != NULL){
            cout << i->info << " ";
            i = i->next;
        }
    }
    cout << endl;
    cout << endl;
}