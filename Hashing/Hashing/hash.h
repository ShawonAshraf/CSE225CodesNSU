#ifndef __Hashing__hash__
#define __Hashing__hash__

#include <iostream>
#include <cmath>

using namespace std;


template <class ItemType>
class Hash
{
public:
    Hash(int);
    ~Hash();
    void initialize();
    void makeEmpty();
    int hash(int key);
    void insert(int key, ItemType);
    int quadriaticProbing(int key);
    int isPrime(int size);
    void reAllocate();
    bool loadFactor();
    void print();
    
    
    void changeSize(int size);
    
    
private:
    int numItems;
    int maxItems;
    ItemType *info;
};

#endif /* defined(__Hashing__hash__) */
