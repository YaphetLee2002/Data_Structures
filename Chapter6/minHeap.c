#include"minHeap.h"

//自顶向下筛选调整
void SiftDown(minHeap H, int start, int m)
{
    int i = start;
    ElementType temp = H.elem[i];
    for (int j = 2 * i + 1; j <= m; j = 2 * j + 1) {
        if (j < m && H.elem[j] > H.elem[j + 1])
            j++;
        if (temp <= H.elem[j])
            break;
        else {
            H.elem[i] = H.elem[j];
            i = j;
        }
    }
    H.elem[i] = temp;
}

void CreateMinHeap(minHeap H, ElementType arr[], int n)
{
    for (int i = 0; i < n; i++)
        H.elem[i] = arr[i];
    H.curSize = n;
    for (int i = (H.curSize - 2) / 2; i >= 0; i--)
        SiftDown(H, i, H.curSize - 1);
}

//自底向上
void SiftUp(minHeap H, int start)
{
    ElementType temp = H.elem[start];
    int j = start;
    int i = (j - 1) / 2;
    while(j > 0) {
        if (H.elem[i] < temp)
            break;
        else {
            H.elem[j] = H.elem[i];
            j = i;
            i = (i - 1) / 2;
        }
        H.elem[j] = temp;
    }
}

int Insert(minHeap H, ElementType X)
{
    if (H.curSize = heapSize)
        return 0;
    H.elem[H.curSize] = X;
    SiftUp(H, H.curSize);
    H.curSize++;
    return 1;
}

int Remove(minHeap H, ElementType X)
{
    if (H.curSize == 0)
        return 0;
    X = H.elem[0];
    H.elem[0] = H.elem[H.curSize - 1];
    H.curSize--;
    SiftDown(H, 0, H.curSize - 1);
    return 1;
}