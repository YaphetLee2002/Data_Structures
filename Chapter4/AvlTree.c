#include <stdio.h>
#include <stdlib.h>
#include "AvlTree.h"
#include "fatal.h"

struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
    //int IsDeleted;
};

static int
Height(Position P)
{
    if (P == NULL)
        return -1;
    else
        return P->Height;
}

static int
Max(int Lhs, int Rhs)
{
    return Lhs > Rhs ? Lhs : Rhs;
}

/* This function can be called only if K2 has a left child */
/* Perform a rotate between a node(K2) and its left child */
/* Update heights, then return new root */
static Position
SingleRotateWithLeft(Position K2) /* K1 to K3 sort from left to right */
{
    Position K1; /* The node K1 to the left of the node K2 */

    K1 = K2->Left;        /* Assign for K1 */
    K2->Left = K1->Right; /* Excute the single rotate */
    K1->Right = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1; /* Update the height of K2 */
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1; /* Update the height of K1 */
    return K1;                                                 /* The position of K2 is K1 now */
}

/* This function can be called only if K1 has a right child */
static Position
SingleRotateWithRight(Position K1) /* K1 is the lefter node */
{
    Position K2;

    K2 = K1->Right;       /* Assign fore K2 */
    K1->Right = K2->Left; /* Excute the single rotate */
    K2->Left = K1;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1; /* Update the height */
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    return K2;
}

/* This function can be called only if K3 has a left child and K3's left child has a right child */
/* Do the left-right double rotation */
/* Update heights, then return new root */
static Position
DoubleRotateWithLeft(Position K3)
{
    /* Rotate between K1 and K2 */
    K3->Left = SingleRotateWithRight(K3->Left); /* K3->Left is K1, K1->Right is K2, return value is node K2 */

    /* Rotate between K3 and K2 */
    return SingleRotateWithLeft(K3); /* K3->Left is K2, now rotate between K3 and K2, make K2 a root node */
}

/* This function can be called only if K3 has a right child and K3's right child has a left child */
/* Do the left-right double rotation */
/* Update heights, then return new root */
static Position
DoubleRotateWithRight(Position K1)
{
    /* Rotate between K2 and K3 */
    K1->Right = SingleRotateWithLeft(K1->Right);
    /* Rotate between K1 and K2 */
    return SingleRotateWithRight(K1);
}

AvlTree
CreateAvlTree(void)
{
    return NULL;
}

AvlTree
MakeEmpty(AvlTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

/* Use recusive implementation */
Position
Find(ElementType X, AvlTree T)
{
    if (T == NULL)
        return NULL; /* Not found */
    if (X < T->Element)
        return Find(X, T->Left); /* Tail recursion */
    else if (X > T->Element)
        return Find(X, T->Right); /* Tail recursion */
    else
        return T;
}

/* Use iterative implementation:
Position
IterFind(ElementType X, AvlTree T)
{
    while (T)
    {
        if (X > T->Element)
            T = T->Right;
        else if (X < T->Element)
            T = T->Left;
        else
            return T;
        return NULL;
    }
}
*/

/* Use recusive implementation */
Position
FindMin(AvlTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

/* Use iternative implementation:
Position
IterFindMin(AvlTree T)
{
    if(T != NULL)
        while(T->Left != NULL)
            T = T->Left;
    return T;
}
*/

/* Use iterative implementation */
Position
FindMax(AvlTree T)
{
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;
    return T;
}

/* Use recursive implementation:
Position
FindMaxRecursion(AvlTree T)
{
    if(T ==     NULL)
        return NULL;
    else if(T->Right = NULL)
        return T;
    else
        return FindMaxRecursion(T->Right);
}
*/

AvlTree
Insert(ElementType X, AvlTree T)
{
    if (T == NULL) /* Create and return a one-node tree */
    {
        T = malloc(sizeof(struct AvlNode));
        if (T == NULL) /* Insufficient memory space */
            FatalError("Out of space!");
        else
        {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < Retrieve(T)) /* X is smaller than the element of this node, turn to left child */
    {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2)
        {
            if (X < Retrieve(T->Left))
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if (X > Retrieve(T)) /* X is bigger than the element of this node, turn to the right child */
    {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2)
        {
            if (X > Retrieve(T->Right))
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    /* Else X is in the tree already; we'll do nothing */

    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

/* Delete when the position is given */
static AvlTree
DeleteNode(AvlTree T, Position P)
{
    if (P == NULL)
    {
        P = T->Left;
        free(T);
        return P;
    }
    if (P->Left == NULL)
    {
        P->Left = T->Left;
        free(T);
        if (Height(P->Left) - Height(P->Right) == 2)
        {
            if (Heigth(P->Left->Left) - Height(P->Right) == 1)
                P = SingleRotateWithLeft(P);
            else
                P = DoubleRotateWithLeft(P);
            return P;
        }
    }
    if (P->Left->Left == NULL)
    {
        P->Left->Left = T->Left;
        P->Left->Right = T->Right;
        free(T);
        return P;
    }
    else
    {
        T = DeleteNode(T, P->Left);
        if (Height(P->Right) - Height(P->Left) == 2)
        {
            if (Height(P->Right->Right) - Height(P->Left) == 1)
                P = SingleRotateWithRight(P);
            else
                P = DoubleRotateWithRight(P);
        }
        P->Height = Max(Height(P->Left), Height(P->Right)) + 1;
        return T;
    }
}

AvlTree
Delete(ElementType X, AvlTree T)
{
    if (T == NULL)
        return NULL;
    if (X < T->Element)
    {
        if (T->Left = Delete(X, T->Left) == NULL)
            return NULL;
        if (Height(T->Right) - Height(T->Left) == 2)
        {
            if (Height(T->Right->Right) - Height(T->Left) == 1)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
        T->Height = Max(Height(T->Left), Height(T->Right));
    }
    else if (X > T->Element)
    {
        if (T->Right = Delete(X, T->Right) == NULL)
            return NULL;
        if (Height(T->Left) - Height(T->Right) == 2)
        {
            if (Height(T->Left->Left) - Height(T->Right) == 1)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
        T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    }
    else if (X == T->Element)
        return DeleteNode(T, T->Right);
    return T;
}

ElementType
Retrieve(Position P)
{
    return P->Element;
}