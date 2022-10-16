typedef int ElementType;
#ifndef _Stack_h
#define _Stack_h
#include "BinTree.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(BinTree X, Stack S);
BinTree Top(Stack);
void Pop(Stack S);
BinTree TopAndPop(Stack S);

#endif /* _Stack_h */