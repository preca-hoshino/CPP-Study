// AGENT CODE
// T708682 - 相似字符串
// GitHub Copilot - 2025-12-14 10:00:00
#include <bits/stdc++.h>
using namespace std;
bool check(char c1, char c2)
{
    if (c1 == c2)
    {
        return true;
    }
    if ((c1 == 'I' && c2 == 'l') || (c1 == 'l' && c2 == 'I'))
    {
        return true;
    }
    return false;
}
string s1, s2;
int main()
{
    cin >> s1 >> s2;
    bool flag = true;
    if (s1.length() != s2.length())
    {
        flag = false;
    }
    else
    {
        for (auto i = 0; i < s1.length(); ++i)
        {
            if (check(s1[i], s2[i]) == 0)
            {
                flag = false;
                break;
            }
        }
    }

    if (flag == true)
    {

        cout << "YES" << endl;
    }
    else
    {

        cout << "NO" << endl;
    }

    return 0;
}
