#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string s;
inline void case_1()
{
    printf("destroy tail\n");
    printf("free list node\n");
}

inline void case_2()
{
    printf("free head node\n");
    printf("free list node\n");
}

inline void putlist()
{
    cout << "generic list: " << s << endl;
}

int main()
{
    cin >> s;
    putlist();
    while (s != "()" && !isalpha(*s.begin()))
    {
        getchar();
        char ch = getchar();
        if (ch == '2'){
            case_2();
            if (*(s.begin() + 1) == '(' && *(s.end() - 2) == ')')
                s = "()";
            else{
                s.erase(s.begin() + 1);
                s.erase(s.begin() + 1);
            }
        }
        else{
            case_1();
            if (*(s.begin() + 1) == '('){
                s.erase(s.begin());
                s.erase(s.end() - 1);
                while (*(s.end() - 1) != ')')
                    s.erase(s.end() - 1);
            }
            else{
                s.erase(s.end() - 2);
                s.erase(s.end() - 2);
            }
            if (s.size() == 3){
                s.erase(s.begin());
                s.erase(s.end() - 1);
            }
        }
        putlist();
    }
    return 0;
}