//
//  Graph.h
//  Graphs
//
//  Created by Shawon Ashraf on 12/3/14.
//  Copyright (c) 2014 Shawon Ashraf. All rights reserved.
//

#ifndef __Graphs__Graph__
#define __Graphs__Graph__

#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>

using namespace std;

#define INF 111


class Vertex
{
public:
    int num;
    int dist;
};

class Graph
{
public:
    Graph();
    ~Graph();
    
    bool isFull();
    bool isEmpty();
    void makeEmpty();
    void initialize();
    void addVertex(Vertex *v);
    int indexOf(Vertex *v);
    void addEdge(Vertex *v, Vertex *w, int);
    int weightIs(Vertex *v, Vertex *w);
    void printVertices();
    void printEdges();
    
    
    int outDegree(Vertex *v);
    bool isEdge(Vertex *v, Vertex *w);
    
    
    void markVertex(Vertex *v);
    bool isMarked(Vertex *v);
    void BFS(Vertex *v);
    bool DFS(Vertex *v, Vertex *w);
    
    
private:
    int numVertices;
    int maxVertices;
    Vertex *vertices[50];
    int edges[50][50];
    bool marked[50];
};

#endif /* defined(__Graphs__Graph__) */
