#include "ALGraph.h"

int GetVertexPos(ALGragh G, ElementType X)
{
    int i = 0;
    while (i < G.numVertices && G.VerticesList[i].Element != X)
        i++;
    if (i < G.numVertices)
        return i;
    else
        return -1;
}

int NumberOfVertices(ALGragh G)
{
    return G.numVertices;
}

int NumberOfEdges(ALGragh G)
{
    return G.numEdge;
}

int FirstNeighbor(ALGragh G, int v)
{
    if (v != -1) {
        EdgeNode *p = G.VerticesList[v].adj;
        if(p != NULL)
            return p->dest;
    }
    return -1;
}

int NextNeighbor(ALGragh G, int v, int w)
{
    if (v != -1) {
        EdgeNode *p = G.VerticesList[v].adj;
        while (p != NULL && p->dest != w)
            p = p->link;
        if (p != NULL && p->link != NULL)
            return p->link->dest;
    }
    return -1;
}

ElementType GetValue(ALGragh G, int v)
{
    if (v != -1)
        return G.VerticesList[v].Element;
    else
        return impossibleValue;
}

Weight GetWeight(ALGragh G,int v, int w)
{
    EdgeNode *p = G.VerticesList[v].adj;
    while (p != NULL && p->dest != w)
        p = p->link;
    if(p != NULL)
        return p->cost;
    else
        return impossibleWeight;
}