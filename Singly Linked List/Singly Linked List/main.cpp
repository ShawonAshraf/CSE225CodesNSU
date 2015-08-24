#include <iostream>
#include "IntSLList.h"

using namespace std;

int main()
{
    IntSLList list;
    
    cout << "\t\t**********************************" << endl;
    cout << "\t\tA Singly Linked list with integers" << endl;
    cout << "\t\t**********************************\n\n" << endl;
    
    cout << "Before initializing......." << endl;
    list.display();
    
    list.addToHead(10);
    cout << "After adding 10 to the list......." << endl;
    list.display();
    
    list.addToTail(8);
    cout << "After adding 8 to the list........" << endl;
    list.display();
    
    list.addToTail(56);
    cout << "After adding 56 to the list.........." << endl;
    list.display();
    
    
    cout << endl;
    cout << "Searching for 78 in the list..........." << endl;
    list.isInList(78) ? cout << "78 is in the list" << endl : cout << "78 is not in the list" << endl;
    cout << endl;
    
    cout << "Searching for 8 in the list..........." << endl;
    list.isInList(8) ? cout << "8 is in the list" << endl : cout << "8 is not in the list" << endl;
    cout << endl;
    cout << endl;
    
    
    cout << "Deleting contents from the top of the list.............." << endl;
    list.deleteFromHead();
    list.display();
    
    cout << "Deleting from the tail of the list.........." << endl;
    list.deleteFromTail();
    list.display();
    
    cout << "Deleting 8 from the list............." << endl;
    list.deleteNode(8);
    list.display();
    
    cout << "Checking if the list is empty..........." << endl;
    list.isEmpty() ? cout << "EMPTY" << endl : cout << "NOT EMPTY" << endl;
    
    
    return 0;
}
