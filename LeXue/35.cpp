#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef int ElementType;
vector<int> v;

static void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/* Insertion sort */
void InsertionSort(ElementType A[], int N)
{
    int j, P;

    ElementType Tmp;
    for (P = 1; P < N; P++)
    {
        Tmp = A[P];
        for (j = P; j > 0 && A[j - 1] > Tmp; j--)
            A[j] = A[j - 1];
        A[j] = Tmp;
    }
}

/* Quick sort */
/* Return median of Left, Center, and Right */
/* Order these and hide the pivot */
ElementType
Median3(ElementType A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;

    if (A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if (A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if (A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);

    /* Invariant: A[Left] <= A[Center] <= A[Right] */

    Swap(&A[Center], &A[Right - 1]); /* Hide pivot */
    return A[Right - 1];             /* Return pivot */
}

#define Cutoff (5)

void Qsort(ElementType A[], int Left, int Right)
{
    int i, j;
    ElementType Pivot;
    if (Left + Cutoff <= Right)
    {
        Pivot = Median3(A, Left, Right);
        v.push_back(Pivot);
        i = Left;
        j = Right - 1;
        for (;;)
        {
            while (A[++i] < Pivot) {}
            while (A[--j] < Pivot) {}
            if (i < j)
                Swap(&A[i], &A[j]);
            else
                break;
        }
        Swap(&A[i], &A[Right - 1]); /* Restore pivot */

        Qsort(A, Left, i - 1);
        Qsort(A, i + 1, Right);
    }
    else /* Do an insertion dort on he subarry */
        InsertionSort(A + Left, Right - Left + 1);
}
void QuickSort(ElementType A[], int N)
{
    Qsort(A, 0, N - 1);
}

int main()
{
    int array[100010];
    int length = 0;
    string s;
    while(1) {
        getline(cin, s);
        if(s[0] == '#')
            break;
        else {
            int n = stoi(s);
            array[length++] = n;
        }
    }
    QuickSort(array, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    putchar('\n');
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    
    return 0;
}