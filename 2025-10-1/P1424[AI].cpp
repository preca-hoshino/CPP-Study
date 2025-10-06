// AGENT CODE
// P1424 - 小鱼的航程（改进版）
// GitHub Copilot - 2025-10-06 15:40:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x = 0, n = 0;
    cin >> x >> n;
    
    int total = 0;        // 总游泳距离
    int current = x;      // 当前是周几
    
    for(int i = 0; i < n; i++)
    {
        // 如果是周一到周五（1-5），游泳250公里
        if(current >= 1 && current <= 5)
        {
            total += 250;
        }
        // 周六(6)和周日(7)休息，不累加
        
        // 移动到下一天
        current++;
        if(current > 7)
        {
            current = 1;
        }
    }
    
    cout << total << endl;
    return 0;
}