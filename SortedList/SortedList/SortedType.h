//
//  SortedType.h
//  SortedList
//
//  Created by Shawon Ashraf on 10/11/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#ifndef __SortedList__SortedType__
#define __SortedList__SortedType__

#include <iostream>
#include "ItemType.h"

using namespace std;

class SortedType
{
private:
    
    int length;
    int currentPos;
    ItemType info[MAX_ITEM];
    
public:
    
    SortedType();
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    void RetreiveItem(ItemType& , bool& );
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    void GetNextElement(ItemType& );
};

#endif /* defined(__SortedList__SortedType__) */
