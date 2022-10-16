#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

void output(NODE *, int);
void change(int, int, NODE *);

void output(NODE *head, int kk)
{
    int k = 0;

    printf("0.");
    while (head->next != NULL && k < kk)
    {
        printf("%d", head->next->data);
        head = head->next;
        k++;
    }
    printf("\n");
}

void change(int n, int m, NODE *head)
{
    NODE *p, *q;
    int i = 0, x = 0, modnum = 1;
    n *= 10;
    x = n / m;
    p = head;
    q = (NODE *)malloc(sizeof(NODE));
    q->data = x;
    p->next = q;
    p = q;
    while (modnum && i < 50)
    {
        n -= x * m;
        n *= 10;
        x = n / m;
        q = (NODE *)malloc(sizeof(NODE));
        q->data = x;
        p->next = q;
        p = q;
        i++;
        modnum = n % m;
    }
    p->next = NULL;
}

int main()
{
    int n, m, k;
    NODE *head;

    scanf("%d%d%d", &n, &m, &k);
    head = (NODE *)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = -1;
    change(n, m, head);
    output(head, k);
    return 0;
}