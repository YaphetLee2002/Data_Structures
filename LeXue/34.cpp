#include <stdio.h>
#include <stdlib.h>

int r[100];
int length;
void HeapAdjust(int s, int m)
{
    int rc = r[s];
    for (int j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && r[j] < r[j + 1])
            ++j;
        if (!(rc < r[j]))
            break;
        r[s] = r[j];
        s = j;
    }
    r[s] = rc;
}

void HeapSort()
{
    int i;
    for (i = length / 2; i > 0; --i)
    {
        HeapAdjust(i, length);
    }
    for (i = 1; i <= length; i++)
        printf("%d ", r[i]);
    printf("\n");
    r[1] = r[length];
    length--;
}

int main()
{
    scanf("%d", &length);
    for (int i = 1; i <= length; i++)
        scanf("%d", &r[i]);
    HeapSort();
    HeapSort();
    HeapSort();
}