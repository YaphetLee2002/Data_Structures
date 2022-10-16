#include<stdio.h>

/*Algorithm 1st----------------------------------------------------------------------------------*/
int
MaxSubsequenceSum1(const int A[], int N)
{
    int ThisSum, MaxSum, i, j, k;

    MaxSum = 0;
    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            ThisSum = 0;
            for ( k = 0; k < N; k++)
            {
                ThisSum += A[k];

                if (ThisSum > MaxSum)
                    MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

/*Algorithm 2st----------------------------------------------------------------------------------*/
int
MaxSubsequenceSum2(const int A[], int N)
{
    int ThisSum, MaxSum, i, j;

    MaxSum = 0;
    for (i = 0; i < N; i++)
    {
        ThisSum = 0;
        for (j = 0; j < N; j++)
        {
            ThisSum += A[j];
            
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

/*Algorithm 3st----------------------------------------------------------------------------------*/
static int
MaxSubSum(const int A[], int Left, int Right)
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBroderSum, MaxRightBroderSum;
    int LeftBroderSum, RightBroderSum;
    int Center, i;

    if (Left == Right)  /* Base case */
    {
        if (A[Left] > 0)
            return A[Left];
        else
            return 0;
    }   

    Center = (Left + Right) / 2;
    MaxLeftSum = MaxSubSum(A, Left, Center);
    MaxRightSum = MaxSubSum(A, Center + 1, Right);

    MaxLeftBroderSum = 0; LeftBroderSum = 0;
    for (i = Center; i >= Left; i--)
    {
        LeftBroderSum += A[i];
        if (LeftBroderSum > MaxLeftBroderSum)
            MaxLeftBroderSum = LeftBroderSum;
    }

    MaxRightBroderSum = 0; RightBroderSum = 0;
    for (i = Center + 1; i <= Right; i++)
    {
        RightBroderSum += A[i];
        if (RightBroderSum > MaxRightBroderSum)
            MaxRightBroderSum = RightBroderSum;
    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftSum + MaxRightSum);
}
int
MaxSubsequenceSum3(const int A[], int N)
{
    return MaxSubSum(A, 0, N - 1);
}

/*Algorithm 4st----------------------------------------------------------------------------------*/
int
MaxSubsequenceSum4(const int A[], int N)
{
    int ThisSum, MaxSum, j;

    ThisSum = MaxSum = 0;
    for ( j = 0; j < N; j++)
    {
        ThisSum += A[j];

        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            MaxSum = 0;
    }
    return MaxSum;
}