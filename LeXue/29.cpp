#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	long long time;
	int flag;
}T[2000006];
bool cmp(struct node x, struct node y)
{
	if (x.time != y.time)
		return x.time < y.time;
	else
		return x.flag > y.flag;
}
int main()
{
	int n;
	int sum = 0,ans=0;
	long long start, end;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld %lld", &start, &end);
		T[sum].time = start;	T[sum++].flag = -1;
		T[sum].time = end;		T[sum++].flag = 1;
	}
	sort(T, T + sum, cmp);
	int temp = 0;
	for (int i = 0; i < sum; i++)
	{
		if (T[i].flag == -1)
			temp++;
		else if (T[i].flag == 1)
			temp--;
		if (temp > ans)
			ans=temp;
	}
	printf("%d\n", ans);
	return 0;
}