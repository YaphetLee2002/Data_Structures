#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int m;
    int n;
    int num;
};
typedef struct node Node;

int row1, row2, number1, col1, col2, number2;
Node S1[100], S2[100], S3[100];
int p;

int getelem(int x, int i, int j)
{
    int ii;
    int answer = 0;
    if (x == 1)
    {
        for (ii = 1; ii <= number1; ii++)
        {
            if (S1[ii].m == i && S1[ii].n == j)
                answer = S1[ii].num;
        }
    }

    else
    {
        for (ii = 1; ii <= number2; ii++)
        {
            if (S2[ii].m == i && S2[ii].n == j)
                answer = S2[ii].num;
        }
    }
    return answer;
}

int main()
{
    scanf("%d %d %d", &row1, &col1, &number1);
    int i, j, k, sum = 0;
    p = 0;
    for (i = 1; i <= number1; i++)
        scanf("%d %d %d", &S1[i].m, &S1[i].n, &S1[i].num);
    scanf("%d %d %d", &row2, &col2, &number2);
    for (i = 1; i <= number2; i++)
        scanf("%d %d %d", &S2[i].m, &S2[i].n, &S2[i].num);
    for (i = 1; i <= row1; i++)
    {
        for (j = 1; j <= col2; j++)
        {
            sum = 0;
            for (k = 1; k <= col1; k++)
                sum += getelem(1, i, k) * getelem(2, k, j);
            if (sum)
            {
                p++;
                S3[p].m = i;
                S3[p].n = j;
                S3[p].num = sum;
            }
        }
    }
    printf("%d\n", row1);
    printf("%d\n", col2);
    printf("%d\n", p);
    for (i = 1; i <= p; i++)
        printf("%d,%d,%d\n", S3[i].m, S3[i].n, S3[i].num);
    return 0;
}