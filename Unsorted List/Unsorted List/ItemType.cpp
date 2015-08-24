//
//  ItemType.cpp
//  Unsorted List
//
//  Created by Shawon Ashraf on 10/11/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#include "ItemType.h"
#include <iostream>
using namespace std;

ItemType::ItemType()
{
    value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem)
{
    if(value < otherItem.value) return LESS;
    else if(value > otherItem.value) return GREATER;
    else return EQUAL;
}

void ItemType::Initialize(int number)
{
    value = number;
}

void ItemType::Print()
{
    cout << value << " ";
}
