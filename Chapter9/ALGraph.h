#include<stdio.h>
#include<stdlib.h>
#define maxVertices 30
#define maxEdge 450
#define maxSize 100
typedef char ElementType;
typedef int Weight;
#define impossibleValue '#'
#define impossibleWeight -1

typedef struct Enode {
    int dest;
    Weight cost;
    struct Enode *link;
} EdgeNode;

typedef struct Vnode {
    ElementType Element;
    struct Enode *adj;
} VertexNode;

typedef struct {
    VertexNode VerticesList[maxVertices];
    int numVertices, numEdge;
} ALGraph;

#ifndef _ALGraph_H
#define _ALGraph_H

void CreateGraph(ALGraph G, int n, int m);
void PrintGraph(ALGraph G);
void InitializeGraph(ALGraph G);
int GetVertexPos(ALGraph G, ElementType X);
int NumberOfVertices(ALGraph G);
int NumberOfEdges(ALGraph G);
ElementType GetValue(ALGraph G, int i);
Weight GetWeight(ALGraph G, int v1, int v2);
int FirstNeighbor(ALGraph G, int v);
int NextNeighbor(ALGraph G, int v, int w);
void InsertVertex(ALGraph G, ElementType Vertex);
void InsertEdge(ALGraph G, int v1, int v2, int Weight);
void RemoveVertex(ALGraph G, int v);
void RemoveEdge(ALGraph G, int v1, int v2);

#endif /* _ALGraph_H */