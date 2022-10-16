//数据表的结构定义

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int ElementType;

typedef struct {
    ElementType Elem[MAXSIZE];
    int n;
} DataList;

void Swap(DataList L, int i, int j)
{
    if (i >= 0 && i < L.n && j < L.n) {
        ElementType temp = L.Elem[i];
        L.Elem[i] = L.Elem[j];
        L.Elem[j] = temp;
    }
}