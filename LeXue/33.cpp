#include <stdio.h>
#include <stdlib.h>
#include<stack>
#include<iostream>
using namespace std;
typedef char ElementType;
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
stack<AvlTree> s;

struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Depth;
    int Height;
};

static int
Depth(Position P)
{
    if (P == NULL)
        return -1;
    else
        return P->Depth;
}

static int
Max(int Lhs, int Rhs)
{
    return Lhs > Rhs ? Lhs : Rhs;
}

static Position
SingleRotateWithLeft(Position K2)
{
    Position K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Depth = Max(Depth(K2->Left), Depth(K2->Right)) + 1;
    K1->Depth = Max(Depth(K1->Left), Depth(K1->Right)) + 1;
    return K1;
}

static Position
SingleRotateWithRight(Position K1)
{
    Position K2;

    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;

    K2->Depth = Max(Depth(K2->Left), Depth(K2->Right)) + 1;
    K1->Depth = Max(Depth(K1->Left), Depth(K1->Right)) + 1;
    return K2;
}

static Position
DoubleRotateWithLeft(Position K3)
{
    K3->Left = SingleRotateWithRight(K3->Left);

    return SingleRotateWithLeft(K3);
}

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
Insert(ElementType X, AvlTree T)
{
    if (T == NULL)
    {
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        T->Element = X;
        T->Depth = 0;
        T->Left = T->Right = NULL;
    }
    else if (X < T->Element)
    {
        T->Left = Insert(X, T->Left);
        if (Depth(T->Left) - Depth(T->Right) == 2)
        {
            if (X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if (X > T->Element)
    {
        T->Right = Insert(X, T->Right);
        if (Depth(T->Right) - Depth(T->Left) == 2)
        {
            if (X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }

    T->Depth = Max(Depth(T->Left), Depth(T->Right)) + 1;
    return T;
}

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
        if (Depth(P->Left) - Depth(P->Right) == 2)
        {
            if ((Depth(P->Left->Left) - Depth(P->Right)) == 1)
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
        if (Depth(P->Right) - Depth(P->Left) == 2)
        {
            if (Depth(P->Right->Right) - Depth(P->Left) == 1)
                P = SingleRotateWithRight(P);
            else
                P = DoubleRotateWithRight(P);
        }
        P->Depth = Max(Depth(P->Left), Depth(P->Right)) + 1;
        return T;
    }
}

/* Preorder travelsal */
void PreOrderTraversal(AvlTree T, int H)
{
    if (T)
    {
        T->Height = H;
        putchar(T->Element);
        PreOrderTraversal(T->Left, H + 1);
        PreOrderTraversal(T->Right, H + 1);
    }
}

/* Inorder travelsal */
void InOrderTraversal(AvlTree T)
{
    if (T)
    {
        InOrderTraversal(T->Left);
        putchar(T->Element);
        s.push(T);
        InOrderTraversal(T->Right);
    }
}

/* Postorder travelsal */
void PostOrderTraversal(AvlTree T)
{
    if (T)
    {
        PostOrderTraversal(T->Left);
        PostOrderTraversal(T->Right);
        putchar(T->Element);
    }
}

int main(void)
{
    AvlTree newTree = CreateAvlTree();
    char ch;
    while((ch = getchar()) != '\n')
        newTree = Insert(ch, newTree);
    printf("Preorder: "); PreOrderTraversal(newTree, 0); putchar('\n');
    printf("Inorder: "); InOrderTraversal(newTree); putchar('\n');
    printf("Postorder: "); PostOrderTraversal(newTree); putchar('\n');
    printf("Tree:\n");
    while(!s.empty()) {
        for (int i = 0; i < s.top()->Height * 4; i++)
            putchar(' ');
        putchar(s.top()->Element);
        putchar('\n');
        s.pop();
    }
    return 0;
}