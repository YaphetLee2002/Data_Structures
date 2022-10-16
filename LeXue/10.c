#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

struct Node
{
    ElementType Element;
    PtrToNode Next;
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

void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    TmpCell->Element = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Next->Element;
}


void TopAndPop(Stack S)
{
    PtrToNode FirstCell;
    ElementType TopElem;

    FirstCell = S->Next;
    S->Next = FirstCell->Next;
    TopElem = FirstCell->Element;
    free(FirstCell);
    putchar(TopElem);
}

int main(void)
{
    Stack S = CreateStack();
    int round;
    scanf("%d", &round);
    for (int i = 0; i < round; i++)
    {
        char ch;
        getchar();
        while ((ch = getchar()) != '#')
        {
            if (isalpha(ch))
            {
                putchar(ch);
                continue;
            }
            if (IsEmpty(S))
            {
                Push(ch, S);
                continue;
            }
            switch (ch)
            {
            case '^':
            case '(':
                Push(ch, S);
                break;
            case ')':
                while (Top(S) != '(')
                    TopAndPop(S);
                Pop(S);
                break;

            case '+':
            case '-':
            {
                while (Top(S) != '(' && !IsEmpty(S))
                    TopAndPop(S);
                Push(ch, S);
            }
            break;

            case '*':
            case '/':
            {
                while(Top(S) != '+' && Top(S) != '-' && Top(S) != '(' && !IsEmpty(S))
                    TopAndPop(S);
                Push(ch, S);
            }
            break;
            
            default:
                break;
            }
        }
        while (!IsEmpty(S))
            TopAndPop(S);
        putchar('\n');
    }
    return 0;
}