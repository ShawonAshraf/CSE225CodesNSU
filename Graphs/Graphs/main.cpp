#include "Graph.h"
#include <iostream>

using namespace std;

int main()
{
    Graph g;
    Vertex v[4];
    
    for(int i = 0; i < 4; i++)
    {
        v[i].num = i;
        v[i].dist = INF;
        
        g.addVertex(&v[i]);
    }
    
    
    g.addEdge(&v[0], &v[3], 1);
    g.addEdge(&v[1], &v[0], 5);
    g.addEdge(&v[1], &v[2], 3);
    g.addEdge(&v[2], &v[3], 8);
    g.addEdge(&v[3], &v[0], 3);
    g.addEdge(&v[3], &v[1], 2);
    
    
    g.printVertices();
    cout << endl;
    g.printEdges();
    cout << endl;
    cout << endl;
    
    
    
    cout << "\t\t========================= task 1 =================\n" << endl;
    
    cout << "Out degree of vertex 3 is : " << g.outDegree(&v[3]) << endl;
    cout << endl;
    
    
    
    cout << "\t\t========================= task 2 =================\n" << endl;
    
    g.isEdge(&v[1], &v[0]) ? cout << "There's an edge" : cout << "No edge";
    cout << endl;
    
    
    g.isEdge(&v[1], &v[1]) ? cout << "There's an edge" : cout << "No edge";
    cout << endl;
    cout << endl;
    
    
    cout << "\t\t========================= task 3 =================\n" << endl;
    
    Graph g2;
    Vertex v2[7];
    
    v2[0].num = 1;
    v2[1].num = 2;
    v2[2].num = 3;
    v2[3].num = 4;
    v2[4].num = 5;
    v2[5].num = 6;
    v2[6].num = 7;
    
    
    for(int i = 0; i < 7; i++) g2.addVertex(&v2[i]);
    
    g2.addEdge(&v2[0], &v2[1], 1);
    g2.addEdge(&v2[0], &v2[2], 1);
    g2.addEdge(&v2[1], &v2[3], 1);
    g2.addEdge(&v2[2], &v2[3], 1);
    g2.addEdge(&v2[2], &v2[5], 1);
    g2.addEdge(&v2[3], &v2[6], 1);
    g2.addEdge(&v2[5], &v2[4], 1);
    g2.addEdge(&v2[4], &v2[6], 1);
    
    
    g2.BFS(v2);
    cout << endl;
    cout << endl;
    
    g2.DFS(&v2[1], &v2[6]);
    
    return 0;
}