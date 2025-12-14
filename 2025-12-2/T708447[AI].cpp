// AGENT CODE
// T708447 - 醒来之后，我回到了汰换系统更新前
// GitHub Copilot - 2025-12-14 10:30:00
#include <bits/stdc++.h>
using namespace std;
int n, m;
long long total = 0;
int main()
{
    cin >> n >> m;
    vector<int> v(n,0);
    vector<int> max_w(n, 0);
    for (auto &i:v)
    {
        cin >> i;
    }
    for (auto i = 0; i < m; ++i)
    {
        int w;
        for (auto &j:max_w)
        {
            cin >> w;
            j= max(j, w);
        }
    }
    for (auto i = 0; i < n; ++i)
    {
        if (max_w[i] > v[i])
        {
            total += (long long)(max_w[i] - v[i]);
        }
    }
    cout << total << endl;
    return 0;
}
