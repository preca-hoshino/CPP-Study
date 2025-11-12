// AGENT CODE
// P3156 - 【深基15.例1】询问学号
// GitHub Copilot - 2025-11-12 00:00:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    
    vector<int> id(n + 1);
    
    // 读取学号
    for(int i = 1; i <= n; i++)
    {
        cin >> id[i];
    }
    
    // 处理查询
    for(int i = 0; i < m; i++)
    {
        int pos = 0;
        cin >> pos;
        cout << id[pos] << "\n";
    }
    
    return 0;
}
