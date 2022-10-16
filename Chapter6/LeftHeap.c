#include "LeftHeap.h"
#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};

static void
SwapChildren(PriorityQueue PNode)
{
    PriorityQueue Tmp = malloc(sizeof(struct TreeNode));
    *Tmp = *(PNode->Left);
    *(PNode->Left) = *(PNode->Right);
    *(PNode->Right) = *Tmp;
}

static PriorityQueue
Merge1(PriorityQueue H1, PriorityQueue H2)
{
    if (H1->Left == NULL) /* Single node */
        H1->Left = H2; /* H1->Right is already NULL; H1->Npl is already 0 */
    else
    {
        H1->Right = Merge(H1->Right, H2);
        if (H1->Left->Npl < H1->Right->Npl)
            SwapChildren(H1);
        
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}

int
IsEmpty(PriorityQueue H)
{
    return H->Left == NULL && H->Right == NULL;
}

PriorityQueue
Initialize(ElementType X)
{
    PriorityQueue H;

    H = malloc(sizeof(struct TreeNode));
    if(H == NULL)
        FatalError("Out of space!");

    H->Element = X;
    H->Left = H->Right = NULL;
    H->Npl = 0;
    return H;
}

PriorityQueue
Merge(PriorityQueue H1, PriorityQueue H2)
{
    if (H1 == NULL)
        return H2;
    if (H2 == NULL)
        return H1;
    if (H1->Element < H2->Element)
        return Merge1(H1, H2);
    else
        return Merge1(H2, H1);
}

PriorityQueue
Insert1(ElementType X, PriorityQueue H)
{
    PriorityQueue SingleNode;

    SingleNode = malloc(sizeof(struct TreeNode));
    if(SingleNode == NULL)
        FatalError("Out of space!");
    else
    {
        SingleNode->Element = X;
        SingleNode->Npl = 0;
        SingleNode->Left = SingleNode->Right = NULL;
        H = Merge(SingleNode, H);
    }
    return H;
}

/* DeleteMin1 returns the new tree */
/* To get the mimimun, use FindMin */
/* This is for convience */
PriorityQueue
DeleteMin1(PriorityQueue H)
{
    PriorityQueue LeftHeap, RightHeap;

    if (IsEmpty(H))
    {
        Error("Priority queue is empty ");
        return H;
    }

    LeftHeap = H->Left;
    RightHeap = H->Right;
    free(H);
    return Merge(LeftHeap, RightHeap);
}

ElementType
FindMin(PriorityQueue H)
{
    return H->Element;
}