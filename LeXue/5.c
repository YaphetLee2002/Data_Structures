#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int remainder;
    struct node *next;
} NODE;
typedef struct node *Position;
typedef struct node *List;

void output(NODE *, int);
void change(int, int, NODE *, int);

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

NODE* FindRemainder(int remainder, Position L, Position Now)
{
    Position P;
    P = L->next;
    while (P->remainder != remainder)
        P = P->next;
    if(P == Now)
        P = NULL;
    return P;
}

void change1(int n, int m, NODE *head, int k)
{
    NODE *TmpHead;
    TmpHead = head;
    int Remainder = 1;
    for (int i = 1; i <= k && Remainder; i++)
    {
        NODE *TmpCell = malloc(sizeof(struct node));
        TmpCell->data = n * 10 / m;
        Remainder = n * 10 % m;
        n = Remainder;
        TmpHead->next = TmpCell;
        TmpHead = TmpCell;
        TmpHead->next = NULL;
    }
}

void change(int n, int m, NODE *head, int k)
{
    NODE *TmpHead;
    TmpHead = head;
    for (int i = 1; i <= k; i++)
    {
        NODE *TmpCell = malloc(sizeof(struct node));
        TmpCell->data = n * 10 / m; 
        TmpCell->remainder = n * 10 % m;
        n = TmpCell->remainder;
        Position Pt;
        TmpHead->next = TmpCell;
        Pt = FindRemainder(TmpCell->remainder, head, TmpCell);
        TmpHead = TmpCell;
        if (Pt != NULL)
        {
            TmpHead->next = Pt;
            break;
        }
        TmpHead->next = NULL;
        if (!TmpCell->remainder)
            break;
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
    if(k < 100000)
        change1(n, m, head, k);
    else
        change(n, m, head, k);
    output(head, k);
    return 0;
}