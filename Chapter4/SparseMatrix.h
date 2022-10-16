#include<stdio.h>
#include<stdlib.h>

#define MaxTerm 30;
typedef int ElementType;
typedef struct {
    int row, col;
    ElementType value;
} Triple;

typedef struct {
    int Rows, Cols, Terms;
    Triple elem[MaxTerm];
} SparseMatrix;