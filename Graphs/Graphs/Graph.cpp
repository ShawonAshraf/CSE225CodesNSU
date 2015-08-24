//
//  Graph.cpp
//  Graphs
//
//  Created by Shawon Ashraf on 12/3/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#include "Graph.h"


Graph::Graph()
{
    numVertices = 0;
    maxVertices = 50;
    initialize();
}

Graph::~Graph()
{
    makeEmpty();
}

bool Graph::isEmpty()
{
    return (numVertices == 0);
}

bool Graph::isFull()
{
    return (numVertices == maxVertices);
}


void Graph::makeEmpty()
{
    numVertices = 0;
}

void Graph::initialize()
{
    for(int i = 0; i < maxVertices; i++)
    {
        for(int j = 0; j < maxVertices; j++)
        {
            edges[i][j] = INF;
        }
    }
}


void Graph::addVertex(Vertex *v)
{
    vertices[numVertices] = v;
    numVertices++;
}



int Graph::indexOf(Vertex *v)
{
    for(int i = 0; i < maxVertices; i++)
    {
        if(v->num == vertices[i]->num) return i;
    }
    
    return -1;
}

void Graph::addEdge(Vertex *v, Vertex *w, int d)
{
    int x = indexOf(v);
    int y = indexOf(w);
    
    edges[x][y] = d;
    edges[y][x] = d;
}

int Graph::weightIs(Vertex *v, Vertex *w)
{
    int x = indexOf(v);
    int y = indexOf(w);
    
    return edges[x][y];
}

void Graph::printVertices()
{
    if(isEmpty())
    {
        cout << "No vertex on the graph" << endl;
        return;
    }
    
    cout << "Vertex" << setw(5) << "Dist" << endl;
    
    for(int i = 0; i < numVertices; i++)
    {
        cout << vertices[i]->num << setw(10) << vertices[i]->dist << endl;
    }
    cout << endl;
}


void Graph::printEdges()
{
    if(isEmpty())
    {
        cout << "There's no vertex on the graph" << endl;
        return;
    }
    
    for(int i = 0; i < numVertices; i++)
    {
        cout << i << " ";
        for(int j = 0; j < numVertices; j++)
        {
            if(weightIs(vertices[i], vertices[j]) == INF) cout << " *" << " ";
            else cout << " " << weightIs(vertices[i], vertices[j]) << " ";
        }
        cout << endl << endl;
    }
    cout << endl;
}





int Graph::outDegree(Vertex *v)
{
    int deg = 0;
    int x = indexOf(v);
    
    for(int i = 0; i < numVertices; i++)
    {
        if(edges[x][i] != INF) deg++;
    }
    
    return deg;
}


bool Graph::isEdge(Vertex *v, Vertex *w)
{
    bool r = false;
    
    int x = indexOf(v);
    int y = indexOf(w);
    
    if(edges[x][y] != INF) r = true;
    
    return r;
}



void Graph::markVertex(Vertex *v)
{
    marked[v->num] = true;
}

bool Graph::isMarked(Vertex *v)
{
    return (marked[v->num]);
}


void Graph::BFS(Vertex *w)
{
    for(int i = 0; i < numVertices; i++)
    {
        marked[vertices[i]->num] = false;
    }
    
    marked[w->num] = true;
    queue<int> q;
    q.push(w->num);
    
    cout << "Breadth firts search starting from vertex ";
    cout << w->num << " : " << endl;
    
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << "   ";
        
        for(int i = 0; i < numVertices; i++)
        {
            if(isEdge(vertices[v-1], vertices[i]) && !isMarked(vertices[i]))
            {
                q.push(vertices[i]->num);
                marked[vertices[i]->num] = true;
            }
        }
    }
    
    cout << endl;
}


bool Graph::DFS(Vertex *v, Vertex *w)
{
    stack<int> s;
    
    for(int i = 0; i < numVertices; i++)
    {
        marked[vertices[i]->num] = false;
    }
    
    s.push(v->num);
    marked[v->num] = true;
    bool found = false;
    
    if(v->num == w->num)
    {
        cout << "Same starting and Ending Vertex" << endl;
        cout << w->num << endl;
    }
    
    cout << "Depth firts search starting from vertex ";
    cout << v->num << " : " << endl;
    
    
    while(!s.empty())
    {
        int k = s.top();
        s.pop();
        
        if(k == w->num)
        {
            found = true;
            break;
        }
        cout << k << "   ";
        for(int i = numVertices - 1; i >= 0; i--)
        {
            if(isEdge(vertices[k - 1], vertices[i]) && !isMarked(vertices[i]))
            {
                s.push(vertices[i]->num);
                marked[vertices[i]->num] = true;
            }
        }
    }
    cout << endl;
    return found;
}