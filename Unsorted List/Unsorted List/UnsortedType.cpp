//
//  UnsortedType.cpp
//  Unsorted List
//
//  Created by Shawon Ashraf on 10/11/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#include "UnsortedType.h"
#include <iostream>
using namespace std;

UnsortedType::UnsortedType()
{
    length = 0;
    currentPos = -1;
}

void UnsortedType::MakeEmpty()
{
    length = 0;
}

bool UnsortedType::IsFull()
{
    return (length == MAX_ITEM);
}

int UnsortedType::LengthIs()
{
    return length;
}

void UnsortedType::RetrieveItem(ItemType& item, bool& found)
{
    int location = 0;
    bool moreToSearch = (location < length);
    found = false;
    
    while(moreToSearch && !found)
    {
        switch(item.ComparedTo(info[location]))
        {
            case LESS:
            case GREATER:
                location++;
                moreToSearch = (location < length);
                break;
            case EQUAL:
                found = true;
                item = info[location];
                break;
        }
    }
}

void UnsortedType::InsertItem(ItemType item)
{
    info[length] = item;
    length++;
}

void UnsortedType::DeleteItem(ItemType item)
{
    int location = 0;
    
    while(item.ComparedTo(info[location]) != EQUAL) location++;
    
    info[location] = info[length - 1];
    length--;
}

void UnsortedType::ResetList()
{
    currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType& item)
{
    currentPos++;
    item = info[currentPos];
}