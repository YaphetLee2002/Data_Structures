#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"
#include "BinTree.h"
#include "Queue.h"

/* Place in implementation file */
/* Queue implementation is a dynamicallu allocated array */

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    BinTree *Array;
};

struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void LevelOrderTraversal(BinTree BT)
{
    Queue Q;
    BinTree T;
    if (!BT)
        Error("Empty Tree!");
    Q = CreateQueue(MaxQueueSize);
    Enqueue(BT, Q);     /* BinTree enqueue */
    while (!IsEmpty(Q)) /* A tree node dequeue, and two subtree enqueue */
    {
        T = FrontAndDequeue(Q);
        printf("%d", T->Data);
        if (T->Left)
            Enqueue(T->Left, Q);
        if (T->Right)
            Enqueue(T->Right, Q);
    }
}