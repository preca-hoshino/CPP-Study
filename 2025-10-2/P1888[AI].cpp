// AGENT CODE
// P1888 - 三角函数
// GitHub Copilot - 2025-10-06 10:30:00
#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    long long a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    
    // 排序，找出最小值和最大值
    long long arr[3] = {a, b, c};
    sort(arr, arr + 3);
    
    // arr[0]是最短边（较小锐角的对边），arr[2]是斜边
    long long numerator = arr[0];    // 分子
    long long denominator = arr[2];  // 分母
    
    // 约分
    long long g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
    
    cout << numerator << "/" << denominator;
    
    return 0;
}
