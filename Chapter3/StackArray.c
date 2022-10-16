#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

/* Place in implementation file */
/* Stack implementation is a dynamically allocated array */

struct StackRecord
{
    int Capacity;       /* Capacity of stack*/
    int TopOfStack;     /* The position of top */
    ElementType *Array; /* Store the elements */
};

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS; /* TopOfStack is initialized as EmptyTOS = -1 */
}

int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity - 1; /* TopOfStack begin with 0 while Capacity begin with 1 */
}

Stack CreateStack(int MaxElements)
{
    Stack S;

    if (MaxElements < MinStackSize)
        Error("Stack size is too small");

    S = malloc(sizeof(struct StackRecord));
    if (S == NULL) /* Insufficient space for Stack */
        FatalError("Out of space!");

    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL) /* Insufficient for array */
        FatalError("Out of space!");
    S->Capacity = MaxElements; /* The capacity of stack is the maximum number of elements */
    MakeEmpty(S);              /* Make sure an empty stack */

    return S;
}

void /* Entirely release the stack */
DisposeStack(Stack S)
{
    if (S != NULL)
    {
        free(S->Array);
        free(S);
    }
}

void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS; /* Only change the top position of stack */
}

/* Push a new element into stack */
void Push(ElementType X, Stack S)
{
    if (IsFull(S)) /* Stack already full of elements */
        Error("Full Stack");
    else
        S->Array[++S->TopOfStack] = X; /* Top position of stack increase, and push the new element */
}

/* Only return the top element of stack */
ElementType
Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Array[S->TopOfStack];
    Error("Empty Stack");
    return 0; /*Return value to avoid warining*/
}

/* Only delete the top element of stack */
void Pop(Stack S)
{
    if (IsEmpty(S))
        Error("Empty Stack");
    else
        S->TopOfStack--;
}

/* Return the top element of stack then delete it */
ElementType
TopAndPop(Stack S)
{
    if (!IsEmpty(S))
        return S->Array[S->TopOfStack--]; /* Use decrement operator distinguished from function Top */
    Error("Empty Stack");
    return 0; /* Return value to avoid warining */
}