#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100


using namespace std;


vector<int> G[MAX] = {};


void bfs(int n, int src);



int main()
{
    int e, n;
    
    cin >> n >> e;
    
    for (int i = 0; i < e; i++)
    {
        int x, y;
        
        cin >> x >> y;
        
        G[x].push_back(y); // directed graph
    }
    
    cout << endl;
    cout << endl;
    
    bfs(n, 1);
    
    return 0;
}



void bfs(int n, int src)
{
    queue<int> q;
    
    int u;
    int visited[MAX] = {};
    int level[MAX] = {};
    
    
    q.push(src);
    visited[src] = 0;
    level[src] = 0;
    
    
    while(!q.empty())
    {
        u = q.front();
        
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u].at(i);
            if(!visited[v])
            {
                level[v] = level[u] + 1;
                visited[v] = 1;
                q.push(v);
            }
        }
        
        q.pop();
    }
    
    
    for(int i = 1; i <= n; i++)
    {
        printf("Distance of %d from %d is : %d\n", i, src, level[i]);
    }
    printf("\n");
    
}