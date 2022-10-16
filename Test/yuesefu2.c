#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    ElementType Element;
    Position Next;
};


List CreateList(void)
{
    List L;
    L = malloc(sizeof(struct Node));
    L->Next = NULL;
    return L;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}


int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position
Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next; /* Move to the next node */
    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L); /* Get the previous node */
    if (!IsLast(P, L))
    {
        TmpCell = P->Next;       /* Get X's node */
        P->Next = TmpCell->Next; /* Skip X's node */
        free(TmpCell);           /* Release this temporary node */
    }
}

/* If X is not found, then Next field of returned */
/* Position is NULL */
/* Assumes a header */
Position
FindPrevious(ElementType X, List L)
{
    Position P;
    P = L;                                           
    while (P->Next != NULL && P->Next->Element != X) 
        P = P->Next;
    return P;
}

void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) //Insufficient space
        FatalError("Out of space!");
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

/* DeleteList algorithm */
void DeleteList(List L)
{
    Position P, Tmp;
    P = L->Next;      /* Header node assumed */
    L->Next = NULL;   /* Delete the first node */
    while (P != NULL) /* Delete all the rest node */
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

/* Return the header of list L */
Position
Header(List L)
{
    return L;
}

/* Return the first position of list L */
Position
First(List L)
{
    return L->Next;
}

/* Return the element of position P */
ElementType
Retrieve(Position P)
{
    return P->Element;
}

int
LegalJudge(int n, int k, int m)
{
    if(n < 1 || k < 1 || m < 1)
    {
        printf("n,m,k must bigger than 0.\n");
        return 1;
    }
    if(k > n)
    {
        printf("k should not bigger than n.\n");
        return 1;
    }
    return 0;
}

int main(void)
{
    int n, k, m, count = 0;
    scanf("%d,%d,%d", &n, &k, &m);
    if(LegalJudge(n, k, m))
        return 0;
    List FirstNum = CreateList();
    Position TargetCell;

}

Position
MoveToNext(Position P, int num)
{
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    TmpCell = P->Next;
    for (int i = 0; i < num; i++)
        TmpCell = TmpCell->Next;
    return TmpCell;
}