#include <iostream>
#include "QueueType.cpp"
using namespace std;

int main()
{
    QueueType<int> q;
    
    cout << "Enqueue :::" << endl;
    
    for(int i = 10; i <= 50; i += 10)
    {
        q.Enqueue(i);
    }
    
    cout << "Print :::" << endl;
    q.Print();
    
    cout << "Dequeue :::" << endl;
    int x;
    q.Dequeue(x);
    
    cout << "Print :::" << endl;
    q.Print();
    
    //cout << "Value of x : " << x << endl;
    
    cout << "Reversing a queue ::::: " << endl;
    q.ReverseQue(q);
    
    cout << "Queue after reversing.........." << endl;
    q.Print();
    cout << endl;
    cout << endl;
    
    return 0;
}