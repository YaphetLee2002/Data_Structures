#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
int main()
{
    int count;
    scanf("%d", &count);
    while(count--) {
        int n;
        scanf("%d", &n);
        v.push_back(n);
    }
    int j = 0;
    bool istrue = true;
    for (auto &&i : v)
    {
        if (i == j) {
            printf("%d ", i);
            istrue = false;
        }
        j++;   
    }
    if(istrue)
        printf("No ");
    putchar('\n');
    return 0;
}