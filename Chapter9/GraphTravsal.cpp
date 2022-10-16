#include "ALGraph.h"
#include <queue>
using namespace std;
void Operation(int v);

//DFS
void DFS_recur(ALGraph G, int v, bool visited[])
{
    Operation(v);
    visited[v] = true;
    int w = FirstNeighbor(G, v);
    if (w != -1)
    {
        if (!visited[w])
            DFS_recur(G, w, visited);
        w = NextNeighbor(G, v, w);
    }
}
void DFS(ALGraph G, int v)
{
    int n = NumberOfVertices(G);
    bool visited[maxVertices] = {false};
    DFS_recur(G, v, visited);
}

//BFS
void BFS(ALGraph G, int v, bool visited[])
{
    bool visited[maxVertices] = {false};
    queue<int> Q;
    Q.push(v);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        Operation(u);
        visited[u] = true;
        int w = FirstNeighbor(G, u);
        if (w != -1)
        {
            if (!visited[w])
                Q.push(w);
            w = NextNeighbor(G, u, w);
        }
    }
}

void calcComponents(ALGraph G)
{
    int n = NumberOfVertices(G);
    bool visited[maxSize] = {false};
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            Operation(i);
            DFS_recur(G, i, visited);
        }
    }
}