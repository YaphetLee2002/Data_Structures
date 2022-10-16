#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

struct
{
    int sonList[100];
    int sonNum;
    int vir;
}Node[100];

int num, nx, ny;

void BFS(int x)
{
    queue<int>q;
    int k0 = x, k1, flag = 0;
    Node[k0].vir = 1;
    q.push(k0);
    while (!q.empty())
    {
        k0 = q.front();
        q.pop();
        if (flag)
            cout << "-";
        flag = 1;
        cout << k0;
        if (Node[k0].sonNum == 0)
            continue;
        sort(Node[k0].sonList, Node[k0].sonList + Node[k0].sonNum);
        for (int i = 0; i <= Node[k0].sonNum; i++)
        {
            k1 = Node[k0].sonList[i];
            if (Node[k1].vir == 1)
                continue;
            q.push(k1);
            Node[k1].vir = 1;
        }
    }
    cout << endl;
}

int main()
{
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        Node[i].sonNum = 0;
        Node[i].vir = 0;
    }
    while (1)
    {
        cin >> nx;
        if (nx == -1)
            break;
        cin >> ny;
        Node[nx].sonList[Node[nx].sonNum] = ny;
        Node[nx].sonNum++;
        Node[ny].sonList[Node[ny].sonNum] = nx;
        Node[ny].sonNum++;
    }
    for (int i = 0; i < num; i++)
    {
        if (Node[i].vir == 0)
            BFS(i);
    }

    return 0;
}