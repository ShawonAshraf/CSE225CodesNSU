#include "SortedType.h"
#include <iostream>
using namespace std;

#define FOR() for(int i = 0; i < MAX_ITEM; i++)

int main()
{
    ItemType item[MAX_ITEM];
    SortedType list;
    
    item[0].Initialize(67);
    item[1].Initialize(89);
    item[2].Initialize(100);
    item[3].Initialize(12);
    item[4].Initialize(32);
    
    
    for(int i = 0; i < MAX_ITEM; i++)
    {
        list.InsertItem(item[i]);
    }
    
    list.IsFull() ? cout << "List is not empty" : cout << "list is empty";
    cout << endl;
    
    cout << "Length of the list is : " << list.LengthIs() << endl;
    
    cout << "Contents of the list : ";
    FOR()
    {
        ItemType printItem;
        
        list.GetNextElement(printItem);
        printItem.Print();
    }
    cout << endl;
    cout << endl;
    
    
    int key;
    ItemType deleteKey;
    cout << "Enter what you want to delete : ";
    cin >> key;
    deleteKey.Initialize(key);
    
    list.DeleteItem(deleteKey);
    
    cout << "After deletion the length of the list : " << list.LengthIs() << endl;
    cout << "Contents of the list  after deletion : ";
    list.ResetList();
    for(int i = 0; i < list.LengthIs(); i++)
    {
        ItemType printItem;
        
        list.GetNextElement(printItem);
        printItem.Print();
    }

    cout << endl;
    
    cout << "Emptying the list........." << endl;
    list.MakeEmpty();
    list.IsFull() ? cout << "List is not empty" : cout << "list is empty";
    cout << endl;
    
    cout << "Resetting the list.............." << endl;
    list.ResetList();
    
    
    
    return 0;
}