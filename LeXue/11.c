#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int turn_to_opposite = 0;
int previous_operator = 1;

int IsEmpty(Stack S);
void MakeEmpty(Stack S);
Stack CreateStack(void);
void Pop(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
ElementType TopAndPop(Stack S);
void TransExpression();
void EvalExpression();

struct Node
{
    ElementType Element;
    int is_negaive;
    PtrToNode Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

void MakeEmpty(Stack S)
{
    
    while (!IsEmpty(S))
    {
        S->is_negaive = 0;
        Pop(S);
    }
}

Stack CreateStack(void)
{
    Stack S;

    S = (Stack)malloc(sizeof(struct Node));
    S->Next = NULL;
    S->is_negaive = 0;
    MakeEmpty(S);
    return S;
}

void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    TmpCell->Element = X;
    if(turn_to_opposite)
        TmpCell->is_negaive = 1;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

void Pop(Stack S)
{
    PtrToNode FirstCell;
    FirstCell = S->Next;
    S->Next = S->Next->Next;
    free(FirstCell);
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Next->Element;
}

ElementType TopAndPop(Stack S)
{
    PtrToNode FirstCell;
    ElementType TopElem;

    FirstCell = S->Next;
    S->Next = FirstCell->Next;
    TopElem = FirstCell->Element;
    free(FirstCell);
    return TopElem;
}

void TransExpression()
{
}

void EvalExpression()
{
}

int main(void)
{
    int round;
    scanf("%d", &round);
    for (int i = 0; i < round; i++)
    {
        Stack expression_stack = CreateStack();
        Stack operation_stack = CreateStack();
        char ch;
        getchar();
        while ((ch = getchar()) != '\n')
        {
            if (isdigit(ch)) //读取到一个数�
            {
                Push(ch, operation_stack); //数字进入运算堆栈
                previous_operator = 0;     //运算符判断值为0，代表本次不为运算符
                continue;
            }

            if (ch != '(' && ch != ')') //如果既不是数字，也不是括�
                previous_operator = 1;  //只能是运算符
            else                        //是括�
                previous_operator = 0;

            if (IsEmpty(expression_stack)) //表达式堆栈为�
            {
                Push(ch, expression_stack); //直接入栈
                continue;
            }
            switch (ch) //表达式堆栈不为空并且该字符不是数�
            {
            case '^':
            case '(':
                Push(ch, expression_stack);
                break;
            case ')':
                while (Top(expression_stack) != '(')
                    Push(TopAndPop(expression_stack), operation_stack);
                Pop(expression_stack);
                break;

            case '-':
                if(previous_operator) //本次是减号并且前一个也是运算符
                {
                    previous_operator = 0;
                    turn_to_opposite = 1;
                    break;
                }
            case '+':
            {
                while (Top(expression_stack) != '(' && !IsEmpty(expression_stack))
                    Push(TopAndPop(expression_stack), operation_stack);
                Push(ch, expression_stack);
            }
            break;

            case '*':
            case '/':
            {
                while (Top(expression_stack) != '+' && Top(expression_stack) != '-' && Top(expression_stack) != '(' && !IsEmpty(expression_stack))
                    Push(TopAndPop(expression_stack), operation_stack);
                Push(ch, expression_stack);
            }
            break;

            default:
                break;
            }
        }
        while (!IsEmpty(expression_stack))
            Push(TopAndPop(expression_stack), operation_stack);
    }
    return 0;
}