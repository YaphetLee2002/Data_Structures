#include<iostream>
using namespace std;
const int inf = 0x3f3f3f;
int road[1010][1010], d[1010];
bool vis[1010];
int n, m;
void dijkstra(int s)
{
    for (int i = 0; i < n; i++)
    {
        d[i] = road[s][i];
        vis[i] = false;
    }
    d[s] = 0;
    vis[s] = true;
    for (int i = 0; i < n; i++)
    {
        int temp = inf, v;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && temp > d[j])
            {
                temp = d[j];
                v = j;
            }
        }
        if (temp == inf)
        {
            break;
        }
        vis[v] = true;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && d[v] + road[v][j] < d[j])
            {
                d[j] = d[v] + road[v][j];
            }
        }
    }
}

int main()
{
    char c, ch;
    cin >> m >> ch >> n >> ch >> c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                road[i][j] = 0;
            }
            else
            {
                road[i][j] = inf;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int dis;
        char a, b;
        cin >> ch >> a >> ch >> b >> ch >> dis >> ch;
        int x = a - 'a';
        int y = b - 'a';
        if (road[x][y] > dis)
        {
            road[x][y] = dis;
        }
    }
    int num = c - 'a';
    dijkstra(num);
    for (int i = 0; i < m; i++)
    {
        cout << (char) (i + 'a') << ":" << d[i] << endl;
    }
    return 0;
}