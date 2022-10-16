#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "fatal.h"

struct Node
{
    ElementType Element; /* The element stored in this node */
    Position Next;       /* Point to the next node */
};

/* Create a new list */
List CreateList(void)
{
    List L;
    L = malloc(sizeof(struct Node)); /* Allocate memory space for list L */
    if (L == NULL)
        FatalError("Out of space!"); /* Insufficient memort space */
    L->Next = NULL;                  /* Waiting for the first node */
    return L;
}

List MakeEmpty(List L)
{
    if (L != NULL) /* Make sure a new list */
        DeleteList(L);
    L = malloc(sizeof(struct Node));
    if (L == NULL) /* Invalid memory allocation for L */
        FatalError("Out of space!");
    L->Next = NULL; /* Waiting for the first node */
    return L;
}

/* Return true if L is empty */
int IsEmpty(List L)
{
    return L->Next == NULL;
}

/* Return true if P is the last position in List L */
/* Parameter L is unused in this implementation */
int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

/* Return Position of X in L; NULL if nut found */
Position
Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next; /* Move to the next node */
    return P;
}

/* Delete first occurrence of X from a list */
/* Assume use of header node */
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
    P = L;                                           /* Find from the first position */
    while (P->Next != NULL && P->Next->Element != X) /* Run until X is found or move to the end already */
        P = P->Next;                                 /* Move to the next position */
    return P;
}

/* Insert after legal position P */
/* Header implementation assumed */
/* Parameter L is unused in this implemetation */
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

/* Return the next position of position P */
Position
Advance(Position P)
{
    return P->Next;
}

/* Return the element of position P */
ElementType
Retrieve(Position P)
{
    return P->Element;
}