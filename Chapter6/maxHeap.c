#include"maxHeap.h"

void SiftDown(maxHeap H, int start, int m)
{
    int i = start;
    int j = 2 * i + 1;
    ElementType temp = H.elem[i];
    while (j <= m) {
        if(j < m && H.elem[j] < H.elem[j + 1])
            j++;
        if(temp >= H.elem[j])
            break;
        else {
            H.elem[i] = H.elem[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    H.elem[i] = temp;
}

void HeapSort(maxHeap H)
{
    for (int i = (H.curSize - 2) / 2; i >= 0; i--)
        SiftDown(H, i, H.curSize - 1);
    for (int i = H.curSize - 1; i > 0; i--)
    {
        ElementType temp = H.elem[0];
        H.elem[0] = H.elem[i];
        H.elem[i] = temp;
        SiftDown(H, 0, i - 1);
    }
}