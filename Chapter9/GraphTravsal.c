#include "ALGraph.h"
void Operation(int v);
void DFS_recur(ALGragh G, int v, int visited[]) {
    Operation(v);
    visited[v] = 1;
    int w = FirstNeighbor(G, v);
    if(w != -1) {
        if(!visited[w])
            DFS_recur(G, w, visited);
        w = NextNeighbor(G, v, w);
    }
}
void DFS_Traversal(ALGragh G, int v)
{
    int n = NumberOfVertices(G);
    int visited[maxVertices];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    DFS_recur(G, v, visited);
}

void BFSTraverse(ALGragh G)
{
    int n = NumberOfVertices(G);
    int visited[maxVertices];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    int vexno[maxVertices];
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            Operation(i);
            visited[i] = 1;
            vexno[rear++] = i;
            while(front < rear) {
                int j = vexno[front++];
                int w = FirstNeighbor(G, j);
                while(w != -1) {
                    if(!visited[w]) {
                        Operation(w);
                        visited[w] = 1;
                        vexno[rear++] = w;
                    }
                    w = NextNeighbor(G, j, w);
                }
            }
        }
    }
}

void calcComponents(ALGragh G)
{
    int n = NumberOfVertices(G);
    int visited[maxSize];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]) {
            Operation(i);
            DFS_recur(G, i, visited);
        }
    }
}