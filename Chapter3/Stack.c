#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "fatal.h"

/* Place in implementation file */
/* Stack implementation is a linked list with a header */
struct Node
{
    ElementType Element;
    PtrToNode Next;
};

/* Return true if S is empty */
int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

/* Initialization of stack, create an empty stack */
Stack CreateStack(void)
{
    Stack S;

    S = (Stack)malloc(sizeof(struct Node));
    if (S == NULL)
        FatalError("Out of space!");
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

/* Empty the stack */
void
MakeEmpty(Stack S)
{
    if (S == NULL) /* Warn while not created stack */
        Error("Must use CreateStack first");
    else
        while (!IsEmpty(S)) /* Pop until S already be empty */
            Pop(S);
}

/* Push an element to the top of stack */
void
Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;

    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL) /* Not enough memory space */
        FatalError("Out of space!");
    else
    {
        TmpCell->Element = X; /* Put the new element into node */
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType
Top(Stack S) /**/
{
    if (!IsEmpty(S))
        return S->Next->Element;
    Error("Empty Stack");
    return 0; /* Return value used to avoid warning */
}

void Pop(Stack S)
{
    PtrToNode FirstCell;

    if (IsEmpty(S))
        Error("Empty stack");
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

ElementType /* Use the top element as return value */
TopAndPop(Stack S)
{
    PtrToNode FirstCell;
    ElementType TopElem;

    if (IsEmpty(S))
        Error("Empty Stack");
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Element;
        free(FirstCell);
        return TopElem;
    }
}