#include<stdio.h>
#include<string.h>
int LegalJudge(int, int, int);
int main(void)
{
    int n, k, m, count = 0;
    scanf("%d,%d,%d", &n, &k, &m);
    if(LegalJudge(n, k, m))
        return 0;
    int memory_array[100000];
    memset(memory_array, 1, sizeof(int) * n + 1);
    int num = k + m - 1;
    int mun = (k - m + 1 > 0) ? k - m + 1 : k - m + 1 + n ;
    while(1)
    {     
        while(num > n)
            num %= n; 
        if(memory_array[num])
        {
            if(num == mun)
            {
                printf("%d,", num);
                memory_array[num] = 0;
                count++;
            }
            else
            {
                printf("%d-%d,", num, mun);
                memory_array[num] = memory_array[mun] = 0;
                count +=2;
            }
        }
        if(count == n)
            break;
        int move = 0;
        while(move != m)
        {
            num++;
            if(num > n)
                num %= n;
            if(memory_array[num])
                move++;
        }
        while(move)
        {
            mun--;
            if(mun < 1)
                mun = n;
            if(memory_array[mun])
                move--;
        }
    }
    putchar('\n');
    return 0;
}
int LegalJudge(int n, int k, int m)
{
    if(n < 1 || k < 1 || m < 1)
    {
        printf("n,m,k must bigger than 0.\n");
        return 1;
    }
    if(k > n)
    {
        printf("k should not bigger than n.\n");
        return 1;
    }
    return 0;
}