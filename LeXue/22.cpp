#include<stdio.h>
int P[13][13], Q[13][13], F[13][13], MAX[13];
int women[13] = {0}, n;
static int totalmax = 0;
int max(int a, int b)
{
    return a > b ? a : b;
}
void dfs(int men, int sum)
{
    if(men == n || sum + MAX[n - 1] - MAX[men - 2] < totalmax)
    {
        totalmax = max(totalmax, sum);
        return ;
    }
    for (int j = 0; j < n; j++)
    {
        if(women[j] == 0)
        {
            women[j] = 1;
            dfs(men + 1, sum + F[men][j]);
            women[j] = 0;
        }
    }
    return ;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &P[i][j]);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &Q[i][j]);
            F[j][i] = P[j][i] * Q[i][j];
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            MAX[i] = max(MAX[i], P[i][j] * Q[j][i]);
        }
        MAX[i] += MAX[i - 1];
    }
    dfs(0, 0);
    printf("%d\n", totalmax);
    return 0;
}