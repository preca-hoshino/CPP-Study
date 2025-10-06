// AGENT CODE
// P1909 - [NOIP 2016 普及组] 买铅笔
// GitHub Copilot - 2025-10-06 10:30:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    
    int minCost = INT_MAX;
    
    for(int i = 0; i < 3; i++)
    {
        int count = 0, price = 0;
        cin >> count >> price;
        
        // 计算需要购买的包数（上取整）
        int packages = (n + count - 1) / count;
        int totalCost = packages * price;
        
        minCost = min(minCost, totalCost);
    }
    
    cout << minCost;
    return 0;
}
