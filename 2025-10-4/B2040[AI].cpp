// AGENT CODE
// B2040 - 判断是否为两位数
// GitHub Copilot - 2025-10-26 00:00:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    
    if(n >= 10 && n <= 99)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    
    return 0;
}
