#include "UFSets.h"

void Initial(UFSets S)
{
    for (int i = 0; i < size; i++)
        S.parent[i] = -1;
}

int Find(UFSets S, int X)
{
    while (S.parent[X] >= 0)
        X = S.parent[X];
    return X;
}

void Merge(UFSets S, int R1, int R2)
{
    if (R2 == R1)
        return;
    S.parent[R1] = S.parent[R1] + S.parent[R2];
    S.parent[R2] = R1;
}

void MergebyWeight(UFSets S, int R1, int R2)
{
    int i = Find(S, R1);
    int j = Find(S, R2);
    if (i == j)
        return;
    int temp = S.parent[i] + S.parent[j];

    if (S.parent[j] < S.parent[j])
    {
        S.parent[i] = j;
        S.parent[j] = temp;
    }
    else
    {
        S.parent[j] = i;
        S.parent[i] = temp;
    }
}

int CollapsingFind(UFSets S, int i)
{
    int k,
        temp;

    for (int k = i; S.parent[k] >= 0; k = S.parent[k])
    {
    }

    while (i != k)
    {
        temp = S.parent[i];
        S.parent[i] = k;
        i = temp;
    }

    return k;
}