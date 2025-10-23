// AGENT CODE
// B2039 - 整数大小比较
// GitHub Copilot - 2025-10-24 00:00:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x = 0, y = 0;
    cin >> x >> y;
    if (x > y)
    {
        cout << ">";
    }
    else if (x == y)
    {
        cout << "=";
    }
    else
    {
        cout << "<";
    }
    return 0;
}
