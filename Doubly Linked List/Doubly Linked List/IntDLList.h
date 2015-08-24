#include <iostream>

class IntDLNode
{
public:
    
    IntDLNode *next, *prev;
    int info;
    
    IntDLNode()
    {
        next = prev = NULL;
    }
    
    IntDLNode(int el, IntDLNode *next = NULL, IntDLNode *prev = NULL)
    {
        info = el;
        this->next = next;
        this->prev = prev;
    }
};

class IntDLList
{
private:
    IntDLNode *head, *tail;
    
public:
    
    IntDLList();
    ~IntDLList();
    
    
    void addToTail(int el);
    void addToHead(int el);
    int deleteFromTail();
    int deleteFromHead();
    void display();
    
    void deleteNode(int el);
    bool isEmpty();
    void deleteWholeList();
    
    bool isInList(int el);
};



