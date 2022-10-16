#define MinQueueSize (5)
#define MaxQueueSize (1024)

#include <stdio.h>
#include "fatal.h"
#include "BinTree.h"

#ifndef _Queue_h
#define _Queue_h

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElement);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
BinTree Front(Queue Q);
void Dequeue(Queue Q);
BinTree FrontAndDequeue(Queue Q);

#endif /* _Queue_h */