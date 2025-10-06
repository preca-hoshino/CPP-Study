// AGENT CODE
// B2027 - 计算球的体积
// GitHub Copilot - 2025-10-06 11:00:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r = 0;
    cin >> r;
    
    // 计算球的体积：V = 4/3 * π * r^3
    const double pi = 3.14;
    double v = (4.0 / 3.0) * pi * r * r * r;
    
    cout << fixed << setprecision(5) << v;
    return 0;
}
