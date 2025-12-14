// AGENT CODE
// T708447 - 醒来之后，我回到了汰换系统更新前
// GitHub Copilot - 2025-12-14 10:30:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> max_w(n, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int w;
            cin >> w;
            max_w[j] = max(max_w[j], w);
        }
    }

    long long total_profit = 0;
    for (int i = 0; i < n; ++i) {
        if (max_w[i] > v[i]) {
            total_profit += (long long)(max_w[i] - v[i]);
        }
    }

    cout << total_profit << endl;

    return 0;
}
