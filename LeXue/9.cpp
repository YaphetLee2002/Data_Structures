#include <stdio.h>
#include <stdlib.h>
int JudgeStack(int);
int main()
{
    int length = 1, round = 1, num = 0, count[10000] = {0};
    while(length && round)
    {
        scanf("%d %d", &length, &round);
        for (int i = 0; i < round; i++)
        {
            count[num] = JudgeStack(length);
            num++;
            if(i + 1 == round)
            {
                count[num] = 3;
                num++;
            }
        }
    }
    for (int i = 0; count[i+1]; i++)
    {
        if(count[i] == 1)
            printf("No\n");
        else if (count[i] == 2)
            printf("Yes\n");
        else if (count[i] == 3)
            putchar('\n');
    }
}

int
JudgeStack(int length)
{
    while (1)
    {
        int a[10000] = {0};
        for (int i = 0; i < length; i++) //读入栈中元素
            scanf("%d", &a[i]);
        int flag1 = 0;
        int flag2 = 0;              //如果序列不合法为1
        for (int i = 0; i < length; i++) //对每一个元素依次判断
        {
            flag1 = 0;
            int temp, j;
            for (j = i + 1; j < length; j++)
            {
                if (a[j] < a[i])
                {
                    flag1 = 1;
                    temp = a[j];
                    break;
                }
            }
            if (flag1 == 1)
            {
                for (int k = j + 1; k < length; k++)
                {
                    if (a[k] < a[i] && a[k] > temp)
                    {
                        flag2 = 1;
                        break;
                    }
                    else if (a[k] < a[i] && a[k] < temp)
                    {
                        temp = a[k];
                    }
                }
            }
            if (flag2 == 1) //序列不合法，结束判断
                break;
        }
        if (flag2 == 0) //合法
            return 2;
        else if (flag2 == 1) //不合法
            return 1;
    }
}