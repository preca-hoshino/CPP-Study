// AGENT CODE
// P1422 - 小玉家的电费
// GitHub Copilot - 2025-10-06 15:35:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int usage = 0;
    cin >> usage;
    
    double cost = 0.0;
    
    // 分段计费
    if (usage <= 150)
    {
        // 全部按0.4463元/千瓦时计算
        cost = usage * 0.4463;
    }
    else if (usage <= 400)
    {
        // 前150按0.4463，超出部分按0.4663
        cost = 150 * 0.4463 + (usage - 150) * 0.4663;
    }
    else
    {
        // 前150按0.4463，151-400按0.4663，超出400按0.5663
        cost = 150 * 0.4463 + 250 * 0.4663 + (usage - 400) * 0.5663;
    }
    
    // 输出保留1位小数
    cout << fixed << setprecision(1) << cost << endl;
    return 0;
}