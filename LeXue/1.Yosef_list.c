#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int id;
    int book;
    struct node *link;
} NODE;

NODE *head, **term = NULL;

void create(int n)
{
    NODE *p;
    int i;
    for (i = n; i >= 1; i--)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->id = i;
        p->book = 0;
        p->link = head->link;
        if (i == n)
        {
            term = &(p->link);
        }
        head->link = p;
    }
}

NODE *init(int k)
{
    NODE *q;
    q = head->link;
    while (k > 1)
    {
        --k;
        q = q->link;
    }
    return q;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    NODE *p;
    p = (NODE *)malloc(sizeof(NODE));
    p->link = NULL;
    head = p;
    create(n);
    *term = head->link;
    p = init(1);
    int cnt = 0, num = 0, tot = 0;
    while (tot != n)
    {
        if (p->id == 1)
            tot = 0;
        if (p->book == 1)
        {
            tot++;
            p = p->link;
            continue;
        }
        cnt++;
        if (cnt % m == 0)
        {
            num++;
            printf("%d\n", p->id);
            p->book = 1;
        }
        p = p->link;
    }
    return 0;
}