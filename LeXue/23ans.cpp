#include <stdio.h>
int base[101];
int ans1[101] = {0};
int ans[101] = {0};
int best = 0;
int score = 0;
int n;
int c;
void back(int i)
{
    int k;
    if (i > n)
        return;
    if (score >= best)
    {
        best = score;
        for (k = 1; k <= n; k++)
        {
            ans[k] = ans1[k];
        }
    }
    if (best == c)
        return;
    int j;
    if (score + base[i] <= c)
    {
        score += base[i];
        ans1[i] = 1;
        back(i + 1);
        score -= base[i];
        ans1[i] = 0;
    }
    back(i + 1);
}
int main()
{
    int i, j, k;
    scanf("%d %d", &c, &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &base[i]);
    }
    back(1);
    printf("%d\n", best);
    for (i = 0; i < n; i++)
    {
        if (ans[i])
            printf("%d ", i);
    }
    printf("\n");
}