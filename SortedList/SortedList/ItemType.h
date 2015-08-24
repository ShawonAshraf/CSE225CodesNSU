//
//  ItemType.h
//  Unsorted List
//
//  Created by Shawon Ashraf on 10/11/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#ifndef __Unsorted_List__ItemType__
#define __Unsorted_List__ItemType__

#include <iostream>
using namespace std;

// definitions and enums

const int MAX_ITEM = 5;
enum RelationType { LESS, GREATER, EQUAL };

class ItemType
{
private:
    
    int value;
    
public:
    
    ItemType();
    RelationType ComparedTo(ItemType otherItem);
    void Print();
    void Initialize(int number);
};

#endif /* defined(__Unsorted_List__ItemType__) */
