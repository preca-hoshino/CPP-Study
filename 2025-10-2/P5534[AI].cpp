// AGENT CODE
// P5534 - 【XR-3】等差数列
// GitHub Copilot - 2025-10-07 15:25:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a1 = 0, a2 = 0, n = 0;
    cin >> a1 >> a2 >> n;
    
    // 计算公差
    long long d = a2 - a1;
    
    // 计算末项 an = a1 + (n-1)*d
    long long an = a1 + (n - 1) * d;
    
    // 等差数列求和公式: S = n*(a1+an)/2
    long long sum = n * (a1 + an) / 2;
    
    cout << sum;
    return 0;
}
