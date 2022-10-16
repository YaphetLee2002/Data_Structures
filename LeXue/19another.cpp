#include<iostream>
#include<cctype>
#include<string>
#include<vector>
using namespace std;
struct tree{
    int Depth;
    char ch;
};
typedef struct tree* TreeNode;
int main()
{
    int childNumCount[100] = {0};
    int maxChild = 0;
    vector<TreeNode>T;
    string s;
    cin >> s;
    int currentDepth = -1;
    for (auto &&i : s)
    {
        if(i == ',')
            continue;
        if(i == '(')
            currentDepth++;
        if(i == ')')
            currentDepth--;
        if(isalpha(i))
        {
            TreeNode TmpCell = (TreeNode)malloc(sizeof(struct tree));
            TmpCell->ch = i;
            TmpCell->Depth = currentDepth;
            T.push_back(TmpCell);
        }
    }
    for (size_t i = 0; i < T.size(); i++)
    {
        int thisChildNUm= 0; 
        size_t j = i + 1;
        while((j < T.size()) && T[j]->Depth > T[i]->Depth)
        {
            if(T[j]->Depth - 1 == T[i]->Depth)
                thisChildNUm++;
            j++;
        }
        maxChild = maxChild < thisChildNUm ? thisChildNUm : maxChild;
        childNumCount[thisChildNUm]++;
    }
    for (auto &&i : T)
    {
        cout.width(i->Depth * 4 + 1);
        cout << i->ch << endl;
    }
    cout << "Degree of tree: " << maxChild << endl;
    for (int i = 0; i <= maxChild; i++)
        cout << "Number of nodes of degree " << i << ": " << childNumCount[i] <<endl; 
    return 0;
}