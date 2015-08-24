#include <iostream>
#include "IntCSLList.h"


using namespace std;


IntCSList::IntCSList()
{
    tail = 0;
}

IntCSList::~IntCSList() {}


void IntCSList::addToHead(int el)
{
    if(tail == 0){
        tail = new IntSLNode(el);
        tail->next = tail;
    }
    
    else{
        tail->next = new IntSLNode(el, tail);
    }
}


void IntCSList::addToTail(int el)
{
    if(tail != 0){
        tail->next = new IntSLNode(el, tail->next);
        tail = tail->next;
    }
    
    else{
        tail = new IntSLNode(el);
        tail->next = tail;
    }
}


void IntCSList::deleteFromTail()
{
    IntSLNode *tmp;
    IntSLNode *p;
    int n = numberOfNodes();
    int i;

    for(i = 0, p = tail->next; i < (n - 2); p = p->next, i++);
    
    tmp = tail;
    p->next = tail->next;
    tail = p;
    delete tmp;
    tmp = 0;
}

bool IntCSList::isInList(int el)
{
    IntSLNode *tmp;
    int n = numberOfNodes();
    int i;
    
    for(i = 0, tmp = tail->next; i < n ; tmp = tmp->next, i++){
        if(tmp->info == el) return true;
    }
    
    return false;
}

bool IntCSList::isEmpty()
{
    return tail == 0;
}


void IntCSList::display()
{
    IntSLNode *tmp;
    
    cout << "Contents of the list : ";
    
    tmp = tail->next;
    do{
        
        cout << tmp->info << " ";
        tmp = tmp->next;
        
    } while(tmp != tail->next);
    
    cout << endl;
}


void IntCSList::deleteFromHead()
{
    IntSLNode *tmp;
    
    tmp = tail->next;
    
    tail->next = tail->next->next;
    
    delete tmp;
    tmp = 0;
}

void IntCSList::deleteNode(int el)
{
    IntSLNode *it;
    IntSLNode *p;
    
    for(it = tail->next, p = tail; !(el == it->info); it = it->next, p = p->next);
    
    if(it == tail->next) deleteFromHead();
    
    else if(it == tail) deleteFromTail();
    
    else{
        IntSLNode *tmp;
        
        tmp = it;
        p->next = it->next;
        
        delete tmp;
        tmp = 0;
    }
}

int IntCSList::numberOfNodes()
{
    int n = 0;
    IntSLNode *i;
    
    for(i = tail->next; i != tail; i = i ->next) n++;
    
    return (n + 1);
}

void IntCSList::deleteList()
{
    delete tail;
    tail = 0;
}