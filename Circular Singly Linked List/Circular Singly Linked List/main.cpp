#include <iostream>
#include "IntCSLList.h"

using namespace std;

int main()
{
    IntCSList list;
    int search_key;
    int nd;
    
    
    cout << "\t\t\t***************************" << endl;
    cout << "\t\t\tCircular Singly Linked List" << endl;
    cout << "\t\t\t***************************" << endl;
    
    
    cout << "\nList created." << endl;
    
    
    cout << "Adding 48 to the head.............." << endl;
    list.addToHead(48);
    list.display();
    cout << endl;
    
    cout << "Adding 10, 15, 56, 78, 100 to the tail........." << endl;
    list.addToTail(10);
    list.addToTail(15);
    list.addToTail(56);
    list.addToTail(78);
    list.addToTail(100);
    list.display();
    cout << "Number of nodes in the list : " << list.numberOfNodes() << endl;
    cout << endl;
    
    
    cout << "Deleting from head.........." << endl;
    list.deleteFromHead();
    list.display();
    cout << "Number of nodes in the list : " << list.numberOfNodes() << endl;
    cout << endl;
    
    
    cout << "Enter the node to delete : ";
    cin >> nd;
    cout << endl;
    list.deleteNode(nd);
    list.display();
    cout << "Number of nodes in the list : " << list.numberOfNodes() << endl;
    cout << endl;
    
    
    cout << "Enter the search key : ";
    cin >> search_key;
    cout << search_key << " ";
    list.isInList(search_key) ? cout << "is in the list" : cout << "is not in the list";
    cout << endl;
    cout << endl;
    
    
    cout << "Deleting the list.............." << endl;
    list.deleteList();

    cout << "Checking if the list is empty................." << endl;
    list.isEmpty() ? cout << "List is empty" : cout << "List is not empty";
    cout << endl;
    
    cout << "\t\t\t***************************" << endl;
    
    return 0;
}