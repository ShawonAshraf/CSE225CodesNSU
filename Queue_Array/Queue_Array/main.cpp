#include "QueueType.h"
#include <iostream>
using namespace std;

int main()
{
    QueueType q1;
    ItemType data;
    
    data.Initialize(34);
    q1.Enqueue(data);

    
    data.Initialize(41);
    q1.Enqueue(data);
    
    data.Initialize(4);
    q1.Enqueue(data);
    
    data.Initialize(24);
    q1.Enqueue(data);
    
    data.Initialize(14);
    q1.Enqueue(data);
    
    
    cout << "Is the queue full ? ";
    q1.IsFull() ? cout << "Yes" << endl : cout << "No" << endl;
    
    cout << endl;
    cout << "Removing 14.........." << endl;
    
    data.Initialize(14);
    q1.Dequeue(data);
    
    cout << "Is the queue full ? ";
    q1.IsFull() ? cout << "Yes" << endl : cout << "No" << endl;
    
    cout << endl;
    cout << "Emptying the queue.........." << endl;
    q1.MakeEmpty();
    cout << "Is the queue empty? ";
    q1.IsEmpty() ? cout << "Yes" << endl : cout << "No" << endl;

    
    return 0;
}