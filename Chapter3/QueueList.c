#include <stdio.h>
#include <stdlib.h>
#include "QueueList.h"
#include "fatal.h"

struct QueueRecord
{
    List L;
    PtrToNode Rear;
    int Size;
};

struct Node
{
    ElementType Element;
    Position Next;
};

static void
DeleteList(List L)
{
    Position P, Tmp;
    P = L->Next;      /* Header node assumed */
    L->Next = NULL;   /* Delete the first node */
    while (P != NULL) /* Delete the rest node */
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

static void
DisposeList(List L) /* Entirely clear list L including header node */
{
    DeleteList(L);
    free(L);
}

static void
Insert(ElementType X, Queue Q, Position P) /* Position P is the rear of queue when use this implementation actually */
{
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        FatalError("Out of space!"); /* Insufficient memory space for a new node */
    TmpCell->Element = X;            /* Assign the new element to this node */
    if (P->Next == NULL)
        Q->Rear = TmpCell; /* Give the rear of queue the position of TmpCell while the new node is the last in list */
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

static List
CreateList(void)
{
    List L = malloc(sizeof(struct Node));
    if (L == NULL)
        FatalError("Out of space!"); /* Insufficient memory space for a new list */
    L->Next = NULL;                  /* Waiting for the first node */
    return L;
}

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

Queue CreateQueue(void)
{
    Queue Q;
    Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        FatalError("Out of space!");
    Q->L = CreateList();
    Q->Rear = Q->L;
    Q->Size = 0; /*Inconsequential because of the existence of MakeEmpty */
    return Q;
}

void DisposeQueue(Queue Q) /* Entirely clear a queue */
{
    if (Q != NULL)
    {
        DisposeList(Q->L);
        free(Q);
    }
}

void MakeEmpty(Queue Q)
{
    DeleteList(Q->L);
    Q->Rear = Q->L;
    Q->Size = 0;
}

void Enqueue(ElementType X, Queue Q)
{
    Insert(X, Q, Q->Rear); /* Insert a new element to the rear of queue*/
    Q->Size++;             /* Size of queue increase */
}

/* The first element as return value */
ElementType
Front(Queue Q)
{
    if (IsEmpty(Q)) /* No element to get */
        Error("Empty queue");
    return Q->L->Next->Element; /* The first element locates in list L's first node */
}

/* Only delete the first element and without a return value */
void Dequeue(Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue");            /* No element to delete */
    Position TmpCell = Q->L->Next->Next; /* Assign the second node to TmpCell */
    free(Q->L->Next);                    /* Release the first node */
    Q->L->Next = TmpCell;                /* Turn the first node to the next */
    Q->Size--;                           /* Size of queue decrease*/
}

/* The first element as return value then delete it */
ElementType
FrontAndDequeue(Queue Q)
{
    ElementType X = Front(Q); /* Get the first element */
    Dequeue(Q);               /* Delete the first element */
    return X;
}