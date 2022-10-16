#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"
#include "fatal.h"
#include "Stack.h"

/* Place in implementation file */
/* Stack implementation is a linked list with a header */

struct Node /* List definition of stack */
{
    BinTree Element;
    PtrToNode Next;
};

struct TreeNode /* Define treenode */
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

/* Preorder travelsal */
void PreOrderTravelsal(BinTree BT)
{
    BinTree T = BT;
    Stack S = CreateStack();
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(T, S);            /* Push a bintree node to stack */
            printf("%d", T->Data); /* Output it when first access a node */
            T = T->Left;           /* Turn to left */
        }
        if (!IsEmpty(S)) /* Pop the top node of stack and return the right subtree */
        {
            T = TopAndPop(S);
            T = T->Right;
        }
    }
}

/* Inorder travelsal */
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

/* Postorder travelsal */
void PostOrderTraversal(BinTree BT)
/*算法思想：
1：将当前结点(根节点)压入堆栈，然后一路向左，将经过元素全部压入堆栈，直到达到最左子树
2：获取栈顶元素并判断当前栈顶元素能否被输出：有三种情况
            a:当前节点没有右子树-->可以访问当前节点-->执行第一步
            b:当前节点的右子树访问已经完成-->可以访问当前结点-->执行第一步
            c:当前节点有右子树，并且还没有访问-->不可以访问当前结点-->首先进入该右子树(以该右子树的根节点为当前结点继续想左访问，重复步骤一)-->执行第一步
*/
{
    BinTree T = BT;
    BinTree pre = NULL; //存储当前节点的前一个结点
    BinTree Ttop;       //存储栈顶元素
    Stack S = CreateStack();
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(T, S);
            T = T->Left;
        }
        Ttop = Top(S); //查看当前栈顶元素
        if (Ttop->Right == NULL || Ttop->Right == pre)
        {
            //当前结点，既是当前结点，当前节点没有右子树或者右子树已经访问完成(即使pre这个节点已经被访问了)}
            {
                printf("%d", Ttop->Data); //访问数据域
            }
            pre = Ttop; //更新前一个节点的位置
            Pop(S);     //弹出该节点
        }
        else
        {                    //当前栈顶结点的右子树还没有被进入
            T = Ttop->Right; //转向当前节点的右子树，然后从该节点位置开始往最左路径开始压入堆栈，重复操作
        }
    }
}

/* Postorder travelsal */
void MirrorPostOrderTraversal(BinTree BT)
/*算法思想：
1：将先序遍历输出的顺序就是后序遍历输出的镜像顺序。也就是说，将一个二叉树的后序遍历输出就是该二叉树的镜像树的先序输出顺序
2：采用双堆栈，使用一个堆栈(不出栈)记录另一个堆栈使用根右左的顺序时元素的入栈顺序，然后将该堆栈的元素逆序输出即为后序遍历左右根
*/
{
    BinTree T = BT;
    Stack S1, S2;
    S1 = CreateStack(); //记录访问路径
    S2 = CreateStack(); //记录后序输出的堆栈的顺序
    while (T || !IsEmpty(S1))
    { //该循环是为了判定是否完整的遍历了树
        while (T)
        {
            Push(T, S1);
            Push(T, S2);
            T = T->Right; //先访问右子树
        }
        if (!IsEmpty(S1))
        {
            T = TopAndPop(S1);
            T = T->Left;
        }
    }
    while (!IsEmpty(S2)) //开始访问数据
        printf("%d", TopAndPop(S2)->Data);
}