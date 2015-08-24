#include <iostream>
#include "IntDLList.h"

using namespace std;

int main()
{
    IntDLList list;
    int dataAr[6] = {10, 20, 30, 56, 78, 89};
    int choiceTodelete;
    int search_key;
    
    cout << "\t\t\t***********************************" << endl;
    cout << "\t\t\t     A doubly linked list" << endl;
    cout << "\t\t\t***********************************" << endl;
    cout << endl;
    
    cout << "Adding 10, 20, 30, 56, 78, 89 to the list............." << endl;
    for(int i = 0; i < 6; i++){
        list.addToTail(dataAr[i]);
    }
    list.display();
    cout << endl;
    
    
    
    cout << "Adding 23 to the head.........." << endl;
    list.addToHead(23);
    list.display();
    cout << endl;
    
    
    
    cout << "Deleting from the tail........" << endl;
    list.deleteFromTail();
    list.display();
    cout << endl;
    
    cout << "Deleting from the head............." << endl;
    list.deleteFromHead();
    list.display();
    cout << endl;
    
    
    
    cout << "Enter the node you want to delete : ";
    cin >> choiceTodelete;
    list.deleteNode(choiceTodelete);
    list.display();
    cout << endl;
    
    
    
    cout << "Enter a key to search in the list : ";
    cin >> search_key;
    cout << search_key << " ";
    list.isInList(search_key) ? cout << "is in the list" : cout << "is not in the list";
    cout << endl;
    cout << endl;
    
    
    cout << "Deleting the whole list............" << endl;
    list.deleteWholeList();
    cout << endl;
    
    cout << "Checking if the list is empty now............." << endl;
    list.isEmpty() ? cout << "List is empty" : cout << "List is not empty";
    cout << endl;
    
    cout << endl;
    cout << endl;
    cout << "\t\t\t***********************************" << endl;
    
    return 0;
}