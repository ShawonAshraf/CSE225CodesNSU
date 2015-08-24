#include <iostream>
#include "IntDLList.h"

using namespace std;

IntDLList::IntDLList()
{
    head = tail = 0;
}

IntDLList::~IntDLList(){
    delete head;
    head = tail = 0;
}

void IntDLList::addToTail(int el)
{
    if(tail != 0){
        tail = new IntDLNode(el, 0, tail);
        tail->prev->next = tail;
    }
    else head = tail = new IntDLNode(el);
}

void IntDLList::addToHead(int el)
{
    head = new IntDLNode(el, head, 0);
    if(tail == 0) tail = head;
}

int IntDLList::deleteFromTail()
{
    int el = tail->info;
    
    if(head == tail){
        delete head;
        delete tail;
        head = tail = 0;
    }
    
    else{
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }
    
    return el;
}

int IntDLList::deleteFromHead()
{
    int el = head->info;
    
    if(head == tail){
        delete head;
        //delete tail;
        head = tail = 0;
    }
    
    else{
        IntDLNode *tmp;
        
        tmp = head;
        head->next->prev = 0;
        head = head->next;
        
        delete tmp;
        tmp = 0;
    }
    
    return el;
}

void IntDLList::display()
{
    IntDLNode *tmp;
        
    cout << "Contents of the list : ";
    for(tmp = head; tmp != 0; tmp = tmp->next){
        cout << tmp->info << " ";
    }
    cout << endl;
}

void IntDLList::deleteNode(int el)
{
    if(head != 0){
        if(head->info == el && head == tail){
            delete head;
            head = tail = 0;
        }
        
        else if(head->info == el){
            IntDLNode *tmp;
            
            tmp = head;
            head = head->next;
            head->next->prev = 0;
            
            delete tmp;
            tmp = 0;
        }
        
        else if(tail->info == el){
            IntDLNode *tmp;
            
            tmp = tail;
            tail->prev->next = 0;
            
            delete tmp;
            tmp = 0;
        }
        
        else{
            IntDLNode *tmp;
            
            for(tmp = head; (tmp != 0) && !(tmp->info == el); tmp = tmp->next);
            
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            
            delete tmp;
            tmp = 0;
            
        }
    }
    else cout << "List is empty. Add elements." << endl;
}

bool IntDLList::isEmpty()
{
    return head == 0;
}

void IntDLList::deleteWholeList()
{
    delete head;
    
    head = tail = 0;
}

bool IntDLList::isInList(int el)
{
    IntDLNode *tmp;
    
    for(tmp = head; (tmp != 0) && !(tmp->info == el); tmp = tmp->next);
    
    return (tmp != 0);
    
}