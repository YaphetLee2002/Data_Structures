#include <stdio.h>
#include <stdlib.h>
#include "HashSep.h"
#include "fatal.h"
#define FALSE 0
#define TRUE 1

struct ListNode
{
    ElemenType Element;
    Position Next;
};

typedef Position List;
typedef int Bool;

/* List *TheList will be an array of lists, allocated later */
/* The lists use headers (for simplicity) */
/* though this wastes space */
struct HashTbl
{
    int TableSize;
    List *TheLists;
};

/* Personal add this implementation */
static int NextPrime(int n)
{
    if (n % 2 == 0)
        ++n;
    int i;
    Bool NotPrime = FALSE;
    for (;; n += 2)
    {
        NotPrime = TRUE;
        for (i = 3; i * i <= n; i += 2)
            if (n % i == 0)
            {
                NotPrime = TRUE;
                break;
            }
        if (!NotPrime)
            return n;
    }
}

HashTable
InitializeTable(int TableSize)
{
    HashTable H;
    int i;

    if (TableSize < MINTABLESIZE)
    {
        Error("Table size too small!");
        return NULL;
    }

    /* Allocate table */
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL)
        FatalError("Out of space!");

    H->TableSize = NextPrime(TableSize);

    /* Allocate list headers */
    for (i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL)
            FatalError("Out of space!");
        H->TheLists[i]->Next = NULL;
    }
    return H;
}

Position
Find(ElemenType Key, HashTable H)
{
    Position P;
    List L;

    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    while (P != NULL && P->Element != Key)
        /* Strcmp needed when string elementype*/
        P = P->Next;
    return P;
}

void Insert(ElemenType Key, HashTable H)
{
    Position Pos, NewCell;
    List L;

    Pos = Find(Key, H);
    if (Pos == NULL) /* Not found Key */
    {
        NewCell = malloc(sizeof(struct ListNode));
        if (NewCell == NULL)
            FatalError("Out of space!");
        else
        {
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key; /* Probably need strcpy */
            L->Next = NewCell;
        }
    }
}