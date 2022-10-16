#include<iostream>
#include<string>
#include<vector>
using namespace std;
inline bool isprefix(const string longstring, const string shortstring)
{
    if(longstring.compare(0, shortstring.size(), shortstring, 0, shortstring.size()) == 0)
        return true;
    else
        return false;
}
inline bool isPrefix(const string s1, const string s2)
{
    if(s1.size() > s2.size())
        return isprefix(s1, s2);
    else
        return isprefix(s2, s1);
}
int main()
{
    int count;
    scanf("%d", &count);
    vector<string>s;
    while(count--)
    {
        string tmpstr;
        cin >> tmpstr;
        for (auto &i : s)
        {
            if(isPrefix(i, tmpstr))
            {
                cout << tmpstr << endl;
                return 0;
            }
        }
        s.push_back(tmpstr);
    }
    puts("YES");
    return 0;
}