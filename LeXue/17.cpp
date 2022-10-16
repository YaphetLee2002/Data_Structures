#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

typedef char ElementType;
typedef struct TreeNode *BinTree;
static int CountLeafNode = 0;

struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
    int Depth;
};

void PrintBinTree(const BinTree BT)
{
    BinTree T = BT;
    stack<BinTree> S;
    while(T || !S.empty())
    {
        while(T)
        {
            S.push(T);
            cout.width(T->Depth * 4 + 1);
            cout << T->Data << endl;
            T = T->Left;
        }
        if(!S.empty())
        {
            T = S.top();
            S.pop();
            T = T->Right;
        }
    }
}

void PreOrderTravelsal(const BinTree BT)
{
    BinTree T = BT;
    stack<BinTree> S;
    while (T || !S.empty())
    {
        while (T)
        {
            S.push(T);
            cout << T->Data;
            if (T->Left == NULL && T->Right == NULL)
                CountLeafNode++;
            T = T->Left;
        }
        if (!S.empty())
        {
            T = S.top();
            S.pop();
            T = T->Right;
        }
    }
}

void InOrderTravelsal(const BinTree BT)
{
    BinTree T = BT;
    stack<BinTree> S;
    while (T || !S.empty())
    {
        while (T)
        {
            S.push(T);
            T = T->Left;
        }
        if (!S.empty())
        {
            T = S.top();
            S.pop();
            cout << T->Data;
            T = T->Right;
        }
    }
}

void PostOrderTraversal(const BinTree BT)
{
    BinTree T = BT;
    BinTree pre = NULL;
    BinTree Ttop;
    stack<BinTree> S;
    while (T || !S.empty())
    {
        while (T)
        {
            S.push(T);
            T = T->Left;
        }
        Ttop = S.top();
        if (Ttop->Right == NULL || Ttop->Right == pre)
        {
            cout << Ttop->Data;
            pre = Ttop;
            S.pop();
        }
        else
            T = Ttop->Right;
    }
}

void BuildBinTree(BinTree &BT, int d)
{
    char ch = getchar();
    if (ch == '#')
        BT = NULL;
    else
    {
        BT = new TreeNode;
        BT->Data = ch;
        BT->Depth = d;
        BuildBinTree(BT->Left, d + 1);
        BuildBinTree(BT->Right, d + 1);
    }
}

void SwapLeftRight(BinTree &BT)
{
    if (BT == NULL)
        return;
    else
    {
        BinTree TempNode = BT->Left;
        BT->Left = BT->Right;
        BT->Right = TempNode;
        SwapLeftRight(BT->Left);
        SwapLeftRight(BT->Right);
    }
}

void ThreeOrderTravelsal(BinTree BT)
{
    cout << "pre_sequence  : ";
    PreOrderTravelsal(BT);
    cout << endl
         << "in_sequence   : ";
    InOrderTravelsal(BT);
    cout << endl
         << "post_sequence : ";
    PostOrderTraversal(BT);
    cout << endl;
}

int main(void)
{
    BinTree BinaryTree;
    BuildBinTree(BinaryTree, 0);
    cout << "BiTree" << endl;
    PrintBinTree(BinaryTree);
    ThreeOrderTravelsal(BinaryTree);
    cout << "Number of leaf: " << CountLeafNode << endl;
    SwapLeftRight(BinaryTree);
    cout << "BiTree swapped" << endl;
    PrintBinTree(BinaryTree);
    ThreeOrderTravelsal(BinaryTree);
    return 0;
}
