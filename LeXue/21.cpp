#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int main()
{
    int sum;
    int a, m;

    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &a);
        q.push(a);
    }
    sum = 0;
    while (q.size() > 1)
    {
        int b = q.top();
        q.pop();
        int c = q.top();
        q.pop();
        int d = b + c;
        sum = sum + d;
        q.push(d);
    }
    printf("WPL=%d\n", sum);
    q.pop();

    return 0;
}