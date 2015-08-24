#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main()
{
    UnsortedType list;
    ItemType item[MAX_ITEM];
    ItemType searchKey;
    int key;
    
    // initializing the items
    
    item[0].Initialize(56);
    item[1].Initialize(78);
    item[2].Initialize(90);
    item[3].Initialize(12);
    item[4].Initialize(34);
    
    // inserting them in the list
    
    for(int i = 0; i < MAX_ITEM; i++)
    {
        list.InsertItem(item[i]);
    }
    
    
    // retreiving
    
    cout << "Elemnts in the list : ";
    for(int i = 0; i < list.LengthIs(); i++)
    {
        ItemType printItem;
        list.GetNextItem(printItem);
        
        printItem.Print();
    }
    cout << endl;
    cout << endl;
    
    cout << "Is the list full? : ";
    list.IsFull() ? cout << "List is full" : cout << "List is not full";
    cout << endl;
    
    cout << "Length of the list : " << list.LengthIs() << endl;
    
    // deletion
    
    cout << "Enter the element you want to delete : ";
    cin >> key;
    searchKey.Initialize(key);
    
    list.DeleteItem(searchKey);
    cout << "\nLength of the list after deletion : " << list.LengthIs() << endl;
    
    cout << "List after deletion : ";
    list.ResetList(); // sets the currentposition to the beginning
    for(int i = 0; i < list.LengthIs(); i++)
    {
        ItemType printItem;
        list.GetNextItem(printItem);
        printItem.Print();
    }
    cout << endl;
    cout << endl;
    
    cout << "Emptying the list.........." << endl;
    list.MakeEmpty();
    list.ResetList();
    list.IsFull() ? cout << "List is full" : cout << "List is not full";
    cout << endl;
    
    return 0;
}