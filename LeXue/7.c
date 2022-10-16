#include<stdio.h>
#include<stdlib.h>
#define MaxDegree 100

typedef struct Node *PtrToNode;
typedef PtrToNode Polynomial;

struct Node
{
    int Cofficient;
    int Exponent;
    PtrToNode Next;
};

Polynomial CreatePoly(void)
{
    Polynomial Poly;
    Poly = (Polynomial)malloc(sizeof(struct Node));
    Poly->Next = NULL;
    return Poly;
}

void AddOne(Polynomial TmpCell, Polynomial TmpCells)
{
    TmpCells->Exponent = TmpCell->Exponent;
    TmpCells->Cofficient = TmpCell->Cofficient;
    TmpCell = TmpCell->Next;
}

void AddPolynomial(Polynomial P1, Polynomial P2, Polynomial Polysum)
{
    Polynomial TmpCell1, TmpCell2, TmpCells;
    TmpCell1 = P1;
    TmpCell2 = P2;
    TmpCells = Polysum;
    while(TmpCell1 != NULL && TmpCell2 != NULL)
    {
        if(TmpCell1->Exponent == TmpCell2->Exponent)
        {
            TmpCells->Exponent = TmpCell1->Exponent;
            TmpCells->Cofficient = TmpCell1->Cofficient + TmpCell2->Cofficient;
            TmpCell1 = TmpCell1->Next;
            TmpCell2 = TmpCell2->Next;
            if(TmpCell1 != NULL || TmpCell2 != NULL)
                TmpCells->Next = CreatePoly();
            TmpCells = TmpCells->Next;
        }
        else if(TmpCell1->Exponent < TmpCell2->Exponent)
        {
            AddOne(TmpCell1, TmpCells);
            TmpCell1 = TmpCell1->Next;
            if(TmpCell1 != NULL || TmpCell2 != NULL)
                TmpCells->Next = CreatePoly();
            TmpCells = TmpCells->Next;
        }
        else
        {
            AddOne(TmpCell2, TmpCells);
            TmpCell2 = TmpCell2->Next;
            if(TmpCell2 != NULL || TmpCell1 != NULL)
                TmpCells->Next = CreatePoly();
            TmpCells = TmpCells->Next;
        }
    }
    while(TmpCell1 != NULL)
    {
        AddOne(TmpCell1, TmpCells);
        TmpCell1 = TmpCell1->Next;
        if(TmpCell1 != NULL)
            TmpCells->Next = CreatePoly();
        TmpCells = TmpCells->Next;  
    }            
    while(TmpCell2 != NULL)
    {
        AddOne(TmpCell2, TmpCells);
        TmpCell2 = TmpCell2->Next;
        if(TmpCell2 != NULL)
            TmpCells->Next = CreatePoly();
        TmpCells = TmpCells->Next; 
    }            
}

void PrintPoly(const Polynomial Poly)
{
    Polynomial TmpCell;
    TmpCell = Poly;
    int count = 0;
    while(TmpCell != NULL)
    {
        if(TmpCell->Cofficient)
        {
            printf("<%d,%d>",TmpCell->Cofficient, TmpCell->Exponent);
            if(TmpCell->Next != NULL)
                putchar(',');
            count++;
        }
        TmpCell = TmpCell->Next;
    }
    if(!count)
        printf("<0,0>\n");
    else
        putchar('\n');
}

int main(void)
{
    char ch;
    Polynomial PolyArray[3], Poly1, Poly2;
    for (int i = 0; i < 3; i++)
        PolyArray[i] = CreatePoly();
    Poly1 = CreatePoly();
    Poly2 = CreatePoly();

    while((ch = getchar()) == '1')
    {
        for (int i = 0; i < 3; i++)
        {
            int items;
            scanf("%d", &items);
            Polynomial TmpCell = PolyArray[i];
            for (int j = 0; j < items; j++)
            {
                scanf("%d %d", &TmpCell->Cofficient, &TmpCell->Exponent);

                if(j < items - 1)
                    TmpCell->Next = CreatePoly();
                TmpCell = TmpCell->Next;
            }            
        }
        for (int i = 0; i < 3; i++)
            PrintPoly(PolyArray[i]);
        AddPolynomial(PolyArray[0], PolyArray[1], Poly1);
        AddPolynomial(PolyArray[2], Poly1, Poly2);
        PrintPoly(Poly1);
        PrintPoly(Poly2);
    }
    return 0;
}