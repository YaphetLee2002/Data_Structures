#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int i;
    int j;
    int num;
};

typedef struct node Node;

int main()
{
    Node term;
    int m, p;
    int row, column, number;
    scanf("%d %d %d", &row, &column, &number);
    Node square[number + 1];
    Node answer[number + 1];
    int check[number + 1];
    int col[column + 1];

    int num[column + 1];
    for (m = 1; m <= column; m++)
    {
        col[m] = 0;
        num[m] = 0;
    }
    for (m = 1; m <= number; m++)
    {
        scanf("%d %d %d", &square[m].i, &square[m].j, &square[m].num);
        num[square[m].j]++;
        check[m] = 0;
    }

    col[1] = 1;
    for (m = 1; m <= column - 1; m++)
        col[m + 1] = num[m] + col[m];
    printf("num:");
    for (m = 1; m <= column; m++)
        printf("%d,", num[m]);
    printf("\n");
    printf("cpot:");
    for (m = 1; m <= column; m++)
        printf("%d,", col[m]);
    printf("\n");

    for (m = 1; m <= number; m++)
    {
        p = col[square[m].j];
        while (check[p] != 0)
            p++;
        check[p] = 1;
        answer[p] = square[m];
    }

    for (m = 1; m <= number; m++)
        printf("%d,%d,%d\n", answer[m].j, answer[m].i, answer[m].num);
}