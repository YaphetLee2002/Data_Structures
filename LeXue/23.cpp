#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int capacity, n, maxx = 0;
bool count_array[101] = {false};
bool x[101] = {false};
int MAX[101] = {0};
int v[101] = {0};
void dfs(bool isLoad, int step, int sum, bool thiscount[])
{
    if(step >= n)
        return;
    if(!isLoad)
    {
        dfs(true, step + 1, sum, thiscount);
        dfs(false, step + 1, sum, thiscount);
        return ;
    }
    else
    {   
        int now = sum + v[step];
        if(now > capacity)
            return ;
        if(now > maxx)
        {
            maxx = now;
            thiscount[step] = true;
            for (int i = step; i < n; i++)
                count_array[i] = thiscount[i]; 
        }
        dfs(true, step + 1, now, thiscount);
        dfs(false, step + 1, now, thiscount);
        x[step] = false;
    }
}

int main()
{
    cin >> capacity;
    cin >>  n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    //MAX[0] = v[0];
    //for (int i = 1; i < n; i++)
    //    MAX[i] = v[i] + MAX[i - 1];
    dfs(true ,0, 0, x);
    dfs(false, 0, 0, x);
    cout << maxx << endl;
    for (int i = 0; i < n; i++)
    {
        cout << count_array[i];
    }
    return 0;
}