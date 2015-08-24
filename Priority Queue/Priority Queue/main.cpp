#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

int main()
{
    priority_queue<int> pq;
    
    pq.empty() ? cout << "pq is empty" : cout << "pq is not empty";
    cout << endl;
    cout << endl;
    
    int data[10];
    for (int i = 0; i < 10; i++)
    {
        data[i] = 15 + rand() % (85 - 15 + 1);
        cout << data[i] << " ";
        pq.push(data[i]);
    }
    
    cout << "\nData has been succesfully inserted" << endl;
    
    pq.empty() ? cout << "pq is empty" : cout << "pq is not empty";
    cout << endl;
    cout << endl;
    
    cout << "Size of pq : " << pq.size() << endl;
    
    cout << "contents of pq : ";
    for (int i = 0; !pq.empty(); i++)
    {
        int top = pq.top();
        cout << top << " ";
        pq.pop();
    }
    cout << endl;
    
    pq.empty() ? cout << "pq is empty" : cout << "pq is not empty";
    cout << endl;
    cout << endl;
    
    return 0;
}