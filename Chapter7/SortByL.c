#include"DataList.h"
#include"StaticLinkList.h"

//选择排序
void SelectSort(DataList L)
{
    ElementType temp;
    for (int i = 0; i < L.n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j <= L.n - 1; j++) {
            if(L.Elem[j] < L.Elem[k])
                k = j;
        }
        if(k != i)
            Swap(L, i, k);
    }
}

//插入排序
void InsertSort(DataList L)
{
    ElementType temp, j;
    for (int i = 1; i < L.n - 1; i++) { //对每个位置
        if(L.Elem[i] < L.Elem[i - 1]) { //如果这个位置比上个位置小
            temp = L.Elem[i]; //先记录这里的值
            for ( j = i - 1; j >= 0 && temp < L.Elem[j]; j--) { //从这里往回一直蹭，直到比这个值小
                L.Elem[j + 1] = L.Elem[j];
            }
            L.Elem[j + 1] = temp;
        }
    }
};

void SLinkInsertSort(StaticLinkList SL)
{
    int i, p, pr;
    SL.Elem[0].Element = MAXVALUE;
    SL.Elem[0].link = 1;
    SL.Elem[1].link = 0;
    for (int i = 2; i < SL.n; i++) {
        p = SL.Elem[0].link; //p是扫描指针，当前p在开头的下一位
        pr = 0; //pr是p的前一位，pr会指向p
        while (SL.Elem[p].Element <= SL.Elem[i].Element) { //扫描直到发现比当前位小的数
            pr = p; //pr后移
            p = SL.Elem[p].link; //p后移
        }
        SL.Elem[i].link = p; //这两步相当于插入i
        SL.Elem[pr].link = i;
    }
}

//折半插排
void BinaryInsertSort(DataList L)
{
    ElementType temp;
    int low, high, mid;
    for (int i = 1; i < L.n - 1; i++) {
        temp = L.Elem[i];
        low = 0;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if(temp < L.Elem[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (int j = i - 1; j >= low; j--)
            L.Elem[j + 1] = L.Elem[j];
        L.Elem[low] = temp;
    }
}

//希尔排序
void insertSort_gap(DataList L, int start, int gap)
{
    ElementType temp;
    for (int i = start + gap; i <= L.n - 1; i += gap) {
        if (L.Elem[i - gap] > L.Elem[i]) {
            temp = L.Elem[i];
            int j;
            j = i;
            do {
                L.Elem[j] = L.Elem[j - gap];
                j -= gap;
            } while (j - gap > 0 && L.Elem[j - gap] > temp);
            L.Elem[j] = temp; 
        }
    }   
}
void ShellSort(DataList L, int d[], int m)
{
    int start, gap;
    for (int i = m - 1; i >= 0; i--)
    {
        gap = d[i];
        for ( start = 0; start < gap; start++)
            insertSort_gap(L, start, gap);
    }
}

//冒泡排序
void BubbleSort(DataList L)
{
    int exchange;
    ElementType temp;
    for (int i = 0; i < L.n - 2; i++) {
        exchange = 0;
        for (int j = L.n - 1; j >= i + 1; j--) {
            if(L.Elem[j - 1] > L.Elem[j]) {
                Swap(L, j - 1, j);
                exchange = 1;
            }
        }
        if(!exchange)
            return ;
    }
}

//几种归并排序
//二路归并，将left~mid与mid+1~right归并为一个表
void Merge(DataList L, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0, s = right - left + 1; //s代表长度，i为左，j为中+1，k为合并后的数组下标
    ElementType *L2 = (ElementType*)malloc(s * sizeof(ElementType)); //赋一个动态数组
    while (i <= mid && j <= right) { 
        if(L.Elem[i] <= L.Elem[j]) //将i和j处的元素比较，谁小存谁
            L2[k++] = L.Elem[i++];
        else
            L2[k++] = L.Elem[j++];
    }
    while(i <= mid) //若第一个表未检测完，全都复制进去
        L2[k++] = L.Elem[i++];
    while(j <= right) //若第二个表未检测完，全部复制进去
        L2[k++] = L.Elem[j++];
    for (int i = 0; i < s; i++)
        L.Elem[left + i] = L2[i]; //将L2全部返还给L
    free(L2);
}
//二路归并排序递归算法
void MergeSort_recur(DataList L, int left, int right)
{
    if(left < right) {
        int mid = (left + right) / 2; //取中点
        MergeSort_recur(L, left, mid); //对左半部分归并排序
        MergeSort_recur(L, mid + 1, right); //对右半部分归并排序
        Merge(L, left, mid, right); //左右二路归并
    }
}

//基于静态链表的二路归并算法
int SListMerge(StaticLinkList SL, int s1, int s2)
{//s1和s2分别为两个有序链表第一个节点的下标，返回的SL.Elem[0].link为排好后链表的第一个节点下标
    int r = 0, p1 = s1, p2 = s2;  //p1，p2为链表检测指针，r为结果链指针
    while(p1 != -1 && p2 != -1) { //当二者都未结束
        if(SL.Elem[p1].Element <= SL.Elem[p2].Element) { //谁小存谁
            SL.Elem[r].link = p1; //接过去
            r = p1; //修改当前末尾
            p1 = SL.Elem[p1].link; //p1后移
        }
        else {
            SL.Elem[r].link = p2;
            r = p2;
            p2 = SL.Elem[p2].link;
        }
    } //至此，r是SL当前的末尾
    if(p1 == -1) //谁先空了，就将另一个链表接到SL后
        SL.Elem[r].link = p2;
    else
        SL.Elem[r].link = p1;
    return SL.Elem[0].link;
}
//基于静态链表的二路归并排序算法
int SLinkMergeSort(StaticLinkList SL, int left, int right)
{ //从left到right排序，返回排序后第一个节点的下标。SL.Elem[0].link储存每次二路归并后结果链的头指针
    if(left >= right)
        return left;
    int s1, s2, mid = (left +right) / 2;
    SL.Elem[mid].link = -1; //拆分两个链表
    SL.Elem[right].link = -1;
    s1 = SLinkMergeSort(SL, left, mid); //归并排序左边
    s2 = SLinkMergeSort(SL, mid + 1, right); //归并排序右边
    return SListMerge(SL, s1, s2); //二路归并
}

//迭代二路归并排序中的二路归并算法
void Merge_2(DataList L, DataList L2, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left; //i、j为检测指针，k为存放指针
    while(i <= mid && j <= right) { //若两个表都没有检测完，则进行比较，谁小放谁
        if(L.Elem[i] <= L.Elem[j])
            L2.Elem[k++] = L.Elem[i++];
        else
            L2.Elem[k++] = L.Elem[j++];
    }
    while(i <= mid) //若第一个表没检测完，复制
        L2.Elem[k++] = L.Elem[i++];
    while(j <= right) //若第二个表没检测完，复制
        L2.Elem[k++] = L.Elem[j++];
}

void MergePass(DataList L, DataList L2, int len)
{
    int i = 0;
    while(i + 2 * len <= L.n - 1) {
        Merge_2(L, L2, i, i + len - 1, i + 2 * len - 1);
        i = i + 2 * len;
    }
    if(i + len <= L.n - 1)
        Merge_2(L, L2, i, i + len - 1, L.n - 1);
    else {
        for (int j = i; j < L.n - 1; j++) {
            L2.Elem[j] = L.Elem[j];
        }
        L2.n = L.n;
    }
}

void MergeSort_iter(DataList L)
{
    DataList L2;
    int len = 1;
    while(len < L.n) {
        MergePass(L, L2, len);
        len *= 2;
        MergePass(L2, L, len);
        len *= 2;
    }
}

int Partition(DataList L, int low, int high)
{
    int k = low;
    ElementType pivot = L.Elem[low];
    for (int i = low + 1; i <= high; i++) {
        if(L.Elem[i] < pivot) {
            k++;
            if(k != i)
                Swap(L, i, k);
        }
    }
    L.Elem[low] = L.Elem[k];
    L.Elem[k] = pivot;
    return k;
}

void QuickSort(DataList L, int left, int right)
{
    if(left < right) { //序列长度小于等于1或不合理
        int pivotpos = Partition(L, left, right);
        QuickSort(L, left, pivotpos - 1);
        QuickSort(L, pivotpos + 1, right);
    }
}

void QuickSort_insert(DataList L, int M)
{
    if (L.n <= M)
        InsertSort(L);
    else {
        int pivotpos = Partition(L, 0, L.n - 1);
        QuickSort(L, 0, pivotpos - 1);
        QuickSort(L, pivotpos + 1, L.n - 1);
    }
}

//在序列中三者和并交换到左端
DataList Median3(DataList L, int left, int right)
{
    int mid = (left + right) / 2;
    int k1, k2;
    if(L.Elem[left] < L.Elem[mid]) {
        k1 = left;
        k2 = mid;
    }
    else {
        k1 = mid;
        k2 = left;
    }
    if(L.Elem[right] < L.Elem[k1]) {
        k2 = k1;
        k1 = right;
    }
    else if(L.Elem[right] < L.Elem[k2])
        k2 = right;
    if(k2 != left)
        Swap(L, k2, left);
}

int HoarePartition(DataList L, int left, int right)
{
    if (left < right) {
        Median3(L, left, right);
        int i = left, j = right;
        ElementType pivot = L.Elem[left];
        do {
            while (i < j && pivot <L.Elem[j])
                j--;
            if(i < j) {
                L.Elem[i++] = L.Elem[j];
                while(i < j && L.Elem[i] < pivot)
                    i++;
                if(i < j)
                    L.Elem[j--] = L.Elem[i];
            }
        } while (i < j);
        L.Elem[i] = pivot;
        return i;
    }
    return left;
}