#include <stdio.h>
#include <stdlib.h>
#include "Cursor.h"
#include "fatal.h"

/* Place in the implementation file */
struct Node
{
    ElementType Element;
    Position Next;
};

struct Node CursorSpace[SpaceSize]; /* An array of structures */

/* Take the place of malloc() */
static List
CursorAlloc(void)
{
    Position P;
    P = CursorSpace[0].Next; /* Release node P from the cycle of zero */
    CursorSpace[0].Next = CursorSpace[P].Next;
    return P;
}

/* Take the place of free() */
static void
CursorFree(Position P)
{
    CursorSpace[P].Next = CursorSpace[0].Next; /* Put node P into the cycle of zero */
    CursorSpace[0].Next = P;
}

/* Just a simple cycle */
void InitializeCursorSpace(void)
{
    for (int i = 0; i < SpaceSize - 1; i++)
        CursorSpace[i].Next = i + 1;
    CursorSpace[SpaceSize - 1].Next = 0; /* Last position zero */
}

/* Create a new list */
List CreateList(void)
{
    List L;
    L = CursorAlloc();
    if (L == 0)
        FatalError("Out of space!");
    CursorSpace[L].Next = 0;
    return L;
}

List MakeEmpty(List L)
{
    if (L != 0)
    {
        DeleteList(L);
        CursorSpace[0].Next = 0;
        return L;
    }
    else
    {
        L = CursorAlloc();
        if (L == 0)
            FatalError("Out of space!");
        CursorSpace[L].Next = 0;
        return L;
    }
}

/* Return true if L is empty */
int IsEmpty(List L)
{
    return CursorSpace[L].Next == 0; /* The first position of L */
}

/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
int IsLast(Position P, List L)
{
    return CursorSpace[P].Next == 0; /* Any position in L */
}

/* Return Position of X in L; 0 if not found*/
/* Uses a header node */
Position
Find(ElementType X, List L)
{
    Position P;
    P = CursorSpace[L].Next;                 /* Start from the first position of L */
    while (P && CursorSpace[P].Element != X) /* Position P is not the last and the element is not X */
        P = CursorSpace[P].Next;             /* The next position */
    return P;
}

/* Delete first occurrence of X from a list */
/* Assumed use of a header node */
void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if (!IsLast(P, L))
    {
        TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell);
    }
}

Position
FindPrevious(ElementType X, List L)
{
    Position P;
    P = L;
    while (CursorSpace[P].Next != 0 && CursorSpace[CursorSpace[P].Next].Element != X)
        P = CursorSpace[P].Next;
    return P;
}

/* Insert after legal position P */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    TmpCell = CursorAlloc();
    if (TmpCell == 0)
        FatalError("Out of space!");

    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}

/* Delete entire list L */
void DeleteList(List L)
{
    Position P;
    P = CursorSpace[L].Next;
    CursorSpace[L].Next = 0; /* Delete header node first */
    while (P != 0)           /* Delete until all in zero cycle */
    {
        Position TmpCell;
        TmpCell = CursorSpace[P].Next;
        CursorFree(P);
        P = TmpCell;
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
    return CursorSpace[L].Next;
}

/* Return the next position of position P */
Position
Advance(Position P)
{
    return CursorSpace[P].Next;
}

/* Return the element of position P */
ElementType
Retrieve(Position P)
{
    return CursorSpace[P].Element;
}