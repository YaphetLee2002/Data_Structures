#include<cstdio>
#include<cstdlib>
#include<string>
#include<stack>
using namespace std;

typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef struct TreeNode *BinTree;
typedef BinTree Position;

struct Node
{
    BinTree Element;
    PtrToNode Next;
};

struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

void Pop(Stack S)
{
    PtrToNode FirstCell;
    FirstCell = S->Next;
    S->Next = S->Next->Next;
    free(FirstCell);
}

void MakeEmpty(Stack S)
{
    while (!IsEmpty(S))
        Pop(S);
}

Stack CreateStack(void)
{
    Stack S;
    S = (Stack)malloc(sizeof(struct Node));
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void Push(BinTree BT, Stack S)
{
    PtrToNode TmpCell;
    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    TmpCell->Element = BT;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

BinTree Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Next->Element;
    return 0;
}

BinTree TopAndPop(Stack S)
{
    PtrToNode FirstCell;
    BinTree TopElem;
    FirstCell = S->Next;
    S->Next = FirstCell->Next;
    TopElem = FirstCell->Element;
    free(FirstCell);
    return TopElem;
}

void PreOrderTravelsal(BinTree BT)
{
    BinTree T = BT;
    Stack S = CreateStack();
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(T, S);
            printf("%d", T->Data);
            T = T->Left;
        }
        if (!IsEmpty(S))
        {
            T = TopAndPop(S);
            T = T->Right;
        }
    }
}

void InOrderTravelsal(BinTree BT)
{
    BinTree T = BT;
    Stack S = CreateStack();
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(T, S);
            T = T->Left;
        }
        if (!IsEmpty(S))
        {
            T = TopAndPop(S);

            printf("%d", T->Data);
            T = T->Right;
        }
    }
}

void PostOrderTraversal(BinTree BT)
{
    BinTree T = BT;
    BinTree pre = NULL;
    BinTree Ttop;
    Stack S = CreateStack();
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(T, S);
            T = T->Left;
        }
        Ttop = Top(S);
        if (Ttop->Right == NULL || Ttop->Right == pre)
        {
            printf("%d", Ttop->Data);
            pre = Ttop;
            Pop(S);
        }
        else
            T = Ttop->Right;
    }
}

int main(void)
{

    return 0;
}
