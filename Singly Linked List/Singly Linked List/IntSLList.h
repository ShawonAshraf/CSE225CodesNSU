#include <iostream>

class IntSLNode
{
public:
    IntSLNode()
    {
        next = NULL;
    }
    
    IntSLNode(int el, IntSLNode *ptr = 0)
    {
        info = el;
        next = ptr;
    }
    
    ~IntSLNode()
    {
    }
    
    int info;
    IntSLNode *next;
};


class IntSLList
{
private:
    IntSLNode *head, *tail;
    
public:
    IntSLList();
    ~IntSLList();
    
    int isEmpty();
    void addToHead(int);
    void addToTail(int);
    
    int deleteFromTail();
    int deleteFromHead();
    
    void deleteNode(int);
    bool isInList(int) const;
    
    void display();
};

