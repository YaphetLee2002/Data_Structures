#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
    int x;
    int y;
    int cost;
};

node road[5005];

struct Rule
{
    bool operator()(const node &A, const node &B) const
    {
        return A.cost < B.cost;
    }
};

int tree[1010];
int n, m;

void init()
{
    for (int i = 0; i <= n; i++)
        tree[i] = i;
}

int find(int t)
{
    if (tree[t] == t)
    {
        return t;
    }
    else
    {
        return tree[t] = find(tree[t]);
    }
}

int judge(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if (a != b)
    {
        tree[a] = b;
        return 1;
    }
    else
    {
        return 0;
    }
}

void kruskal()
{
    int side = 0;
    int sum = 0;
    init();
    sort(road, road + m, Rule());
    for (int i = 0; i < m; i++)
    {
        if (judge(road[i].x, road[i].y))
        {
            side++;
            sum += road[i].cost;
        }
        if (side == n - 1)
        {
            break;
        }
    }
    if (side != n - 1)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << sum << endl;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> road[i].x >> road[i].y >> road[i].cost;
    kruskal();
    return 0;
}