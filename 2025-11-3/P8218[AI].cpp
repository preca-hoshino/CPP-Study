// AGENT CODE
// P8218 - 【深进1.例1】求区间和
// GitHub Copilot - 2025-11-12 00:00:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    
    vector<long long> sum(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        int a = 0;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    
    int m = 0;
    cin >> m;
    
    for(int i = 0; i < m; i++)
    {
        int l = 0, r = 0;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    
    return 0;
}
