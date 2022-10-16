#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"
#include "BinTree.h"

struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

/* Recursion is too easy */
/* Preorder travelsal */
void PreOrderTraversal(BinTree BT)
{
    if (BT)
    {
        printf("%d", BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}

/* Inorder travelsal */
void InOrderTraversal(BinTree BT)
{
    if (BT)
    {
        InOrderTraversal(BT->Left);
        printf("%d", BT->Data);
        InOrderTraversal(BT->Right);
    }
}

/* Postorder travelsal */
void PostOrderTraversal(BinTree BT)
{
    if (BT)
    {
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right);
        printf("%d", BT->Data);
    }
}

/* Print all the leaves node */
void PreOrderPrintLeaves(BinTree BT)
{
    if (BT)
    {
        if (!BT->Left && !BT->Right)
            printf("%d", BT->Data);
        PreOrderPrintLeaves(BT->Left);
        PreOrderPrintLeaves(BT->Right);
    }
}

/* Find the height of tree */
int PostOrderGetHeight(BinTree BT)
{
    int HL, HR, MaxH;
    if (BT)
    {
        HL = PostOrderGetHeight(BT->Left);
        HR = PostOrderGetHeight(BT->Right);
        MaxH = (HL > HR) ? HL : HR;
        return (MaxH + 1);
    }
    else
        return 0;
}