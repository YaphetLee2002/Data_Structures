#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"
#include "Queue.h"

/* Queue implementation is a dynamicallu allocated array */

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

/* Declare queue, array and capacity */
/* Then make the queue empty */
Queue CreateQueue(int MaxElements)
{
    if (MaxElements < MinQueueSize) /* Error while declare a too small queue */
        Error("Queue Size is too small");
    Queue Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL) /* FatalError while insufficient space for Queue */
        FatalError("Out of space!");
    Q->Array = malloc(MaxElements * sizeof(ElementType));
    if (Q->Array == NULL) /* FatalError while insufficient space for Array */
        FatalError("Out of space!");
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
    return Q;
}

/* Free the queue */
void DisposeQueue(Queue Q)
{
    if (!IsEmpty(Q))
    {
        free(Q->Array);
        free(Q);
    }
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1; /* Attention! Rear and Front both become 1 after enter an element */
    Q->Rear = 0;
}

/* Enter an element to queue */
void Enqueue(ElementType X, Queue Q)
{
    if (IsFull(Q))
        Error("Full Queue");
    Q->Size++;
    Q->Rear = (Q->Rear + 1) % Q->Capacity; /* Rear moves to the naxt place */
    Q->Array[Q->Rear] = X;                 /* Write in X */
}

/* Get the front element */
ElementType
Front(Queue Q)
{
    if (IsEmpty(Q))
        Error("Queue is empty");
    return Q->Array[Q->Front];
}

/* Delete the front element */
void Dequeue(Queue Q)
{
    if (IsEmpty(Q))
        Error("Queue is empty");
    Q->Size--;
    Q->Front = (Q->Front + 1) % Q->Capacity;
}

/* Get and delete the frint element */
ElementType
FrontAndDequeue(Queue Q)
{
    ElementType X = Front(Q);
    Dequeue(Q);
    return X;
}