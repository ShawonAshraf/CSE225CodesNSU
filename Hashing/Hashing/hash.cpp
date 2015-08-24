#include "hash.h"


template <class ItemType>
Hash<ItemType>::Hash(int size)
{
    numItems = 0;
    maxItems = size;
    info = new int[maxItems];
    initialize();
}


template <class ItemType>
void Hash<ItemType>::initialize()
{
    for(int i = 0; i < maxItems; i++) info[i] = 0;
}


template <class ItemType>
Hash<ItemType>::~Hash()
{
    makeEmpty();
}


template <class ItemType>
void Hash<ItemType>::makeEmpty()
{
    delete [] info;
}

template <class ItemType>
int Hash<ItemType>::hash(int key)
{
    return key % maxItems;
}

template <class ItemType>
bool Hash<ItemType>::loadFactor()
{
    return (double(numItems) / double(maxItems)) > 0.5;
}


template <class ItemType>
int Hash<ItemType>::isPrime(int size)
{
    for(int i = 2; i < size; i++)
    {
        if(size % 2 == 0) size++;
    }
    
    return size;
}


template <class ItemType>
void Hash<ItemType>::reAllocate()
{
    int size = isPrime(maxItems * 2);
    int prevSize = maxItems;
    maxItems = size;
    
    ItemType *temp = new ItemType[maxItems];
    for(int i = 0; i < maxItems; i++)
    {
        if(i < prevSize)
        {
            if(info[i] != 0) temp[i] = info[i];
            else temp[i] = 0;
        }
        else temp[i] = 0;
    }
    
    delete [] info;
    info = temp;
    
    cout << "realloate successfull" << endl;
}



template <class ItemType>
void Hash<ItemType>::insert(int key, ItemType item)
{
    int hval = hash(key);
    if(loadFactor()) reAllocate();
    
    if(info[hval] != 0)
    {
        cout << "Collision detected" << endl;
        int hval2 = quadriaticProbing(hval);
        hval = hash(hval2);
    }
    
    info[hval] = item;
    numItems++;
}


template <class ItemType>
int Hash<ItemType>::quadriaticProbing(int key)
{
    int c = 0;
    int c1 = pow(c, 2.0);
    while(info[key + c1] != 0)
    {
        c++;
        c1 = (int) pow(c, 2.0);
    }
    
    return c1 + key;
}



template <class ItemType>
void Hash<ItemType>::print()
{
    for(int i = 0; i < maxItems; i++)
    {
        cout << "info[" << i << "] : " << info[i] << endl;
    }
}





template <class ItemType>
void Hash<ItemType>::changeSize(int size)
{
    maxItems = size;
}