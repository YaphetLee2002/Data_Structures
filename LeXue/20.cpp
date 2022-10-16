#include<iostream>
#include<string>
using namespace std;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *BinTree;

struct TreeNode
{
    bool State;
    BinTree Left;
    BinTree Right;
};

BinTree CreateTree(void)
{
    BinTree T = new TreeNode;
    T->State = false;
    T->Left = nullptr;
    T->Right = nullptr;
    return T;
}

bool isPrefix(const string s, BinTree BT)
{
    BinTree T = BT;
    for (size_t i = 0; i < s.size(); i++)
    {
        if(s[i] == '0')
        {
            if(T->Left == nullptr)
            {
                T->Left = CreateTree();
                T = T->Left;
            }
            else
                T = T->Left;
        }
        if(s[i] == '1')
        {
            if(T->Right == nullptr)
            {
                T->Right = CreateTree();
                T = T->Right;
            }
            else
                T = T->Right;
        }
        if(T->State)
            return true;
    }
    if(T->Left != nullptr || T->Right != nullptr)
        return true;
    T->State = true;
    return false;
}

int main()
{
    int count;
    scanf("%d", &count);
    BinTree BT = CreateTree();
    while(count--)
    {
        string str;
        cin >> str;
        if(isPrefix(str, BT) == true)
        {
            cout << str << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}