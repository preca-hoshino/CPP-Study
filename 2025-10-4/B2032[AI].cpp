// AGENT CODE
// B2032 - 等差数列末项计算
// GitHub Copilot - 2025-10-23 00:00:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a1 = 0, a2 = 0, n = 0;
    cin >> a1 >> a2 >> n;
    int d = a2 - a1;
    int an = a1 + (n - 1) * d;
    cout << an;
    return 0;
}
