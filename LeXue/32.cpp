#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
typedef int ElementType;
struct TreeNode;
typedef TreeNode *SearchTree; 
vector<int> v;
struct TreeNode {
    ElementType Element;
    SearchTree LeftTree;
    SearchTree RightTree;
    int Height;
};

SearchTree Insert(SearchTree ST, ElementType X, int H)
{
    if (ST == NULL) {
        ST = (SearchTree)malloc(sizeof(struct TreeNode));
        ST->Element = X;
        ST->Height = H;
        ST->LeftTree = ST->RightTree = NULL;
    }
    else if(X < ST->Element)
        ST->LeftTree = Insert(ST->LeftTree, X, H + 1);
    else if(X > ST->Element)
        ST->RightTree = Insert(ST->RightTree, X, H + 1);
    return ST;
}

void PrintElement(SearchTree ST)
{
    for (int i = 0; i < 4 * ST->Height; i++)
        putchar(' ');
    
    cout << ST->Element << endl;
    v.push_back(ST->Element);
}

void PrintTree(SearchTree ST)
{
    if(ST != NULL)
    {
        PrintTree(ST->LeftTree);
        PrintElement(ST);
        PrintTree(ST->RightTree);
    }
}

int main()
{
    SearchTree newTree = NULL;
    int element;
    while(cin >> element) {
        if(!element)
            break;
        else
            newTree = Insert(newTree, element, 0);
    }
    PrintTree(newTree);
    cout << endl;
    for (auto &&i : v)
    {
        cout << " " << i;
    }
    cout << endl;
    return 0;
}