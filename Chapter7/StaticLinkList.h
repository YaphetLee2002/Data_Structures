//静态链表的结构定义

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define MAXVALUE 32767

typedef int ElementType;

typedef struct {
    ElementType Element;
    int link;
} SLNode;

typedef struct {
    SLNode Elem[MAXSIZE];
    int n;
} StaticLinkList;

void CreateSList(StaticLinkList SL, ElementType a[], int n)
{
    for (int i = 0; i < n; i++) {
        SL.Elem[i + 1].Element = a[i];
        SL.Elem[i + 1].link = i + 2;
    }
    SL.Elem[0].Element = MAXVALUE;
    SL.Elem[0].link = 1;
    SL.Elem[n].link = 0;
    SL.n = n;
}

void OutputSList(StaticLinkList SL)
{
    for (int i = SL.Elem[0].link; i != 0; i = SL.Elem[i].link)
        printf("'%d ", SL.Elem[i].Element);
    putchar('\n');
}