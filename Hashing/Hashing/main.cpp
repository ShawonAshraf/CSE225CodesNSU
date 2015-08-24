#include "hash.cpp"
#include <iostream>

using namespace std;

int main()
{
    Hash<int> h(13);
    
    
    h.insert(23, 14001);
    h.insert(21, 50003);
    h.insert(27, 10104);
    h.insert(29, 79606);
    h.insert(19, 33099);
    h.insert(10, 78006);
    h.insert(15, 49002);
    
    h.print();
    
    cout << endl;
    cout << endl;
    cout << "Inserting (14, 68902)........." << endl;
    
    
   h.insert(14, 68902);
    
   h.print();
    
    
    return 0;
}