#include<stdio.h>
#include<stdlib.h>
#define MaxVertices 30
#define maxEdges 900
#define maxWeight 32767
#define impossibleValue '#'
#define impossibleWeight -1
typedef int ElementType;
typedef int Weight;
typedef struct {
    int numVertices;
    int numEdges;
    ElementType VerticesList[MaxVertices];
    Weight Edge[MaxVertices][MaxVertices];
} MGraph;

#ifndef _MGraph_H
#define _MGraph_H

void CreateGraph(MGraph G, int n, int m);
void PrintGraph(MGraph G);
void InitializeGraph(MGraph G);
int GetVertexPos(MGraph G, ElementType X);
int NumberOfVertices(MGraph G);
int NumberOfEdges(MGraph G);
ElementType GetValue(MGraph G, int i);
Weight GetWeight(MGraph G, int v1, int v2);
int FirstNeighbor(MGraph G, int v);
int NextNeighbor(MGraph G, int v, int w);
void InsertVertex(MGraph G, ElementType Vertex);
void InsertEdge(MGraph G, int v1, int v2, int Weight);
void RemoveVertex(MGraph G, int v);
void RemoveEdge(MGraph G, int v1, int v2);

#endif /* _MGraph_H */