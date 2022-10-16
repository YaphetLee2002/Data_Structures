#include "MGraph.h"

int GetVertexPos(MGraph G, ElementType X)
{
    for (int i = 0; i < G.numVertices; i++)
    {
        if (G.VerticesList[i] == X)
            return i;
        return -1;
    }
}

int FirstNeighbor(MGraph G, int v)
{
    if (v != -1)
    {
        for (int i = 0; i < G.numVertices; i++)
            if (G.Edge[v][i] > 0 && G.Edge[v][i] < maxWeight)
                return i;
        return -1;
    }
}

int NextNeighbor(MGraph G, int v, int w)
{
    if (v != -1 && w != -1) {
        for (int j = w + 1; j < G.numVertices; j++)
        {
            if(G.Edge[v][j] > 0 && G.Edge[v][j] < maxWeight)
                return j;
        }
    }
    return -1;
}

int NumberOfVertices(MGraph G)
{
    return G.numVertices;
}

int NumberOfEdges(MGraph G)
{
    return G.numEdges;
}

ElementType GetValue(MGraph G, int v)
{
    if(v != -1)
        return G.VerticesList[v];
    else
        return impossibleValue;
}

Weight GetWeight(MGraph G, int v, int w)
{
    if(v != -1 && w != -1)
        return G.Edge[v][w];
    else
        return impossibleWeight;
}