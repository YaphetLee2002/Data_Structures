#include "BinHeap.h"
#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
};

PriorityQueue
Initialize(int MaxElements)
{
    PriorityQueue H;

    if (MaxElements < MINPQSIZE)
        Error("Priority queue is too small");

    H = malloc(sizeof(struct HeapStruct));
    if (H == NULL)
        FatalError("Out of space!");

    /* Allocate the array plus one extra for sentinel */
    H->Elements = malloc(sizeof(ElementType) * (MaxElements + 1));
    if (H->Elements == NULL)
        FatalError("Out of space!");

    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;

    return H;
}

void Insert(ElementType X, PriorityQueue H)
{
    int i;

    if (IsFull(H))
    {
        Error("Priority queue is full");
        return;
    }
    for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2) /* break when root smaller than new element */
        H->Elements[i] = H->Elements[i / 2];            /* Create a cavity and move up */
    H->Elements[i] = X;
}

ElementType
DeleteMin(PriorityQueue H)
{
    int i, Child;
    ElementType MinElement, LastElement;

    if (IsEmpty(H))
    {
        Error("Priority queue is empty");
        return H->Elements[0];
    }

    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];

    for (i = 1; i * 2 <= H->Size; i = Child)
    {
        /* Find smaller child */
        Child = i * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;

        /* Percolate one level */
        if (LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] - LastElement;
    return MinElement;
}

void MakeEmpty(PriorityQueue H)
{
    H->Size = 0;
}

ElementType
FindMin(PriorityQueue H)
{
    if (!IsEmpty)
        return H->Elements[1];
    Error("Priority is empty");
    return H->Elements[0];
}

int IsEmpty(PriorityQueue H)
{
    return H->Size == 0;
}

int IsFull(PriorityQueue H)
{
    return H->Size == H->Capacity;
}

void Destory(PriorityQueue H)
{
    free(H->Elements);
    free(H);
}