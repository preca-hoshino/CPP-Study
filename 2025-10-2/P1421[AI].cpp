// AGENT CODE
// P1421 - 小玉买文具
// GitHub Copilot - 2025-10-06 15:30:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    
    // 将钱转换为角
    int total = a * 10 + b;
    
    // 签字笔价格是19角
    int pens = total / 19;
    
    cout << pens << endl;
    return 0;
}