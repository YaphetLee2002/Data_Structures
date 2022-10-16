#include "HashQuad.h"
#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"

enum KindOfEntry
{
    Legitimate,
    Empty,
    Delete
};

struct HashEntry
{
    Elementype Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

/* Cell *TheCells will be an array of HashEntry cells, allocated later */
struct HashTbl
{
    int TableSize;
    Cell *TheCells;
};

HashTable
InitializeTable(int TableSize)
{
    HashTable H;
    int i;

    if(TableSize < MINTABLESIZE)
    {
        Error("Tabel size too small");
        return NULL;
    }

    /* Allocate table */
    H = malloc(sizeof(struct HashTbl));
    if(H == NULL)
        FatalError("Out of space!");

    for ( i = 0; i < H->TableSize; i++)
        H->TheCells[i].Info = Empty;

    return H;
}

Position
Find(Elementype Key, HashTable H)
{
    Position CurrentPos;
    int Collisionnum;

    Collisionnum = 0;
    CurrentPos = Hash(Key, H->TableSize);
    while(H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    /* Probably need strcmp */
    {
        CurrentPos += 2 * ++Collisionnum - 1;
        if(CurrentPos >= H->TableSize)
            CurrentPos -= H->TableSize;
    }
    return CurrentPos;
}

void
Insert(Elementype Key, HashTable H)
{
    Position Pos;

    Pos = Find(Key, H);
    if(H->TheCells[Pos].Info != Legitimate)
    {
        /* OK to insert here */
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
    /* Probably need strcpy */
}

HashTable
Rehash(HashTable H)
{
    int i, OldSize;
    Cell *OldCells;

    OldCells = H->TheCells;
    OldSize = H->TableSize;

    /* Get a new, empty table */
    H = InitializeTable(2 * OldSize);

    /* Scan through old table, reinserting into new */
    for (i = 0; i < OldSize; i++)
        if(OldCells[i].Info == Legitimate)
            Insert(OldCells[i].Element, H);

    free(OldCells);

    return H;
}