#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "fatal.h"
/*二叉查找树中的每个节点X，它的左子树中所有的关键字值小于X的关键字值，而它的右子树中所有关键字值大于X的关键字值*/

/* Place in the implementation file */
struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

static void
PrintElement(SearchTree T)
{
    printf("%d", T->Element);
}

/* Inorder travelsal implementation */
static void
PrintTree(SearchTree T)
{
    if(T != NULL)
    {
        PrintTree(T->Left);
        PrintElement(T->Element);
        PrintTree(T->Right);
    }
}

/* Postorder travelsal */
static int
Height(SearchTree T)
{
    if(T == NULL)
        return -1;
    else
        return 1 + Max(Height(T->Left), Height(T->Right));
}

static int
Max(int Lhs, int Rhs)
{
    return Lhs > Rhs ? Lhs : Rhs; 
}

SearchTree /* Initialize a searchtree */
MakeEmpty(SearchTree T)
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
Find(ElementType X, SearchTree T)
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
IterFind(ElementType X, SearchTree T)
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
FindMin(SearchTree T)
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
IterFindMin(SearchTree T)
{
    if(T != NULL)
        while(T->Left != NULL)
            T = T->Left;
    return T;
}
*/

/* Use iterative implementation */
Position
FindMax(SearchTree T)
{
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;
    return T;
}

/* Use recursive implementation:
Position
FindMaxRecursion(SearchTree T)
{
    if(T ==     NULL)
        return NULL;
    else if(T->Right = NULL)
        return T;
    else
        return FindMaxRecursion(T->Right);
}
*/

/* Do nothing when X is in the tree already */
SearchTree
Insert(ElementType X, SearchTree T)
{
    if (T == NULL)
    {
        /* Create and return a one-node tree */
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL)
            FatalError("Out of place!");
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
        T->Left = Insert(X, T->Left);
    else if (X > T->Element)
        T->Right = Insert(X, T->Right);
    /* Else X is in the tree already; we'll do nothing */
    return T; /* Don't forget this line! */
}

SearchTree
Delete(ElementType X, SearchTree T)
{
    Position TmpCell;

    if (T == NULL)
        Error("Element not found");
    else if (X < T->Element) /* Go left */
        T->Left = Delete(X, T->Left);
    else if (X > T->Element) /* Go Right */
        T->Right = Delete(X, T->Left);
    else if (T->Left && T->Right) /* Found element to be deleted owns two children */
    {
        /* Replace the smallest in right subtree */
        TmpCell = FindMin(T->Right);             /* Search the mininum in right subtree */
        T->Element = TmpCell->Element;           /* Assign the mininum in right subtree to this node */
        T->Right = Delete(T->Element, T->Right); /* Delete the mininum in right subtree */
    }
    else /* One or zero children */
    {
        TmpCell = T;
        if (T->Left == NULL)       /* Left subtree element is samller */
            T = T->Right;          /* Skip this node, return NULL while not found left subtree */
        else if (T->Right == NULL) /* For those only have right subtree */
            T = T->Left;
        free(TmpCell);
    }
    return T;
}

ElementType
Retrieve(Position P)
{
    return P->Element;
}