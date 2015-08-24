#include <iostream>

using namespace std;

class IntSLNode
{
public:
    
    int info;
    IntSLNode *next;
    
    IntSLNode()
    {
        next = 0;
    }
    
    IntSLNode(int el, IntSLNode *ptr = 0)
    {
        info = el;
        next = ptr;
    }
    
    ~IntSLNode()
    {
    }
};

class IntCSList
{
private:
    IntSLNode *tail;
    
public:
    
    IntCSList();
    ~IntCSList();
    
    void addToHead(int el);
    void addToTail(int el);
    void deleteFromTail();
    bool isInList(int el);
    bool isEmpty();
    
    void deleteFromHead();
    void deleteNode(int el);
    int numberOfNodes();
    
    void deleteList();
    void display();
};