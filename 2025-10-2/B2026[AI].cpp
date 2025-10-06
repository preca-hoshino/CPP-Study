// AGENT CODE
// B2026 - 计算浮点数相除的余
// GitHub Copilot - 2025-10-06 10:50:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a = 0.0;
    double b = 0.0;
    cin >> a >> b;
    
    // 计算浮点数取模
    double r = fmod(a, b);
    
    cout << r;
    return 0;
}
