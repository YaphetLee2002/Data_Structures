#include"SparseMatrix.h"

void Transpose(SparseMatrix a, SparseMatrix b)
{
    int CurrentB;
    b.Cols = a.Rows;
    b.Rows = a.Cols;
    b.Terms = a.Terms;
    if(a.Terms > 0) {
        CurrentB = 0;
        for (int k = 0; k < a.Cols; k++) {
            for (int i = 0; i < a.Terms; i++) {
                if (a.elem[i].col == k) {
                    b.elem[CurrentB].row = k;
                    b.elem[CurrentB].col = a.elem[i].row;
                    b.elem[CurrentB].value = a.elem[i].value;
                    CurrentB++;
                }
            }
        }
    }
}

void FastTranspos(SparseMatrix a, SparseMatrix b)
{
    int *rowSize = (int*) malloc(a.Cols * sizeof(int));
    int *rowStart = (int*) malloc(a.Cols * sizeof(int));
    b.Rows = a.Cols;
    b.Cols = a.Rows;
    b.Terms = a.Terms;
    if(a.Terms > 0) {
        for (int i = 0; i < a.Cols; i++)
            rowSize[i] = 0;
        for (int i = 0; i < a.Terms; i++)
            rowSize[a.elem[i].col]++;
        rowStart[0] = 0;
        for (int i = 0; i < a.Cols; i++)
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
        for (int i = 0; i < a.Terms; i++)
        {
            int j = rowStart[a.elem[i].col];
            b.elem[j].col = a.elem[i].row;
            b.elem[j].row = a.elem[i].col;
            b.elem[j].value = a.elem[i].value;
            rowStart[a.elem[i].col]++;
        }       
    }
    free(rowSize);
    free(rowStart);
}