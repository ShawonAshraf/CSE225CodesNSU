#include <iostream>
#include "SortedLinkedList.cpp"

using namespace std;

int main()
{
    SortedList<int> sl;
    int k;
    bool f;
    
    
    sl.insertItem(4);
    sl.insertItem(5);
    sl.insertItem(1);
    sl.insertItem(9);
    sl.insertItem(7);
    
    cout << "list : ";
    sl.printList();
    cout << endl;
    
    
    cout << "6 ? ";
    k = 6;
    sl.retreiveItem(k, f);
    f ? cout << "F" << endl : cout << "N F" << endl;
    cout << endl;
    
    cout << "delete 7" << endl;
    sl.deleteItem(7);
    cout << "list : ";
    sl.printList();
    cout << endl;
    
    cout << "insert 3" << endl;
    sl.insertItem(3);
    cout << "list : ";
    sl.printList();
    cout << endl;
    
    cout << "reverse : ";
    sl.revreseList();
    // cout << "list : ";
    sl.printList();
    cout << endl;
    
    return 0;
}