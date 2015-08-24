//
//  UnsortedType.h
//  Unsorted List
//
//  Created by Shawon Ashraf on 10/11/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#ifndef __Unsorted_List__UnsortedType__
#define __Unsorted_List__UnsortedType__

#include <iostream>
#include "ItemType.h"
using namespace std;


class UnsortedType
{
private:
    
    int length;
    ItemType info[MAX_ITEM];
    int currentPos;
    
public:
    
    UnsortedType();
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    void GetNextItem(ItemType& item);
};

#endif /* defined(__Unsorted_List__UnsortedType__) */
