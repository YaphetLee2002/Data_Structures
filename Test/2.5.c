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
    NODE *TmpNode = malloc(sizeof(struct node));
    NODE *TmpCell;
    TmpCell = head;

    int Remainder[100000];
    for (int i = 1;; i++)
    {
        TmpCell->data = n * 10 / m;
        Remainder[i] = n * 10 % m;
        n = Remainder[i];
        for (int j = 1; j < i; j++)
        {
            if (Remainder[j] == Remainder[i])
            {
                return;
            }
        }
    }
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