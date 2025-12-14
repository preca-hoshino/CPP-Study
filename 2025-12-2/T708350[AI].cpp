// AGENT CODE
// T708350 - 猫石游戏
// GitHub Copilot - 2025-12-14 11:00:00
#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
vector<int> segment;
int cnt;
int main()
{
    cin >> n >> k >> s;
    for (auto i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            cnt++;
        }
        else
        {
            if (cnt > 0)
            {
                segment.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if (cnt > 0)
    {
        segment.push_back(cnt);
    }
    int total = 0;
    for (auto &x : segment)
    {
        total += x / k;
    }
    int t1 = (total + 1) / 2;

    int rest = n - total * k;
    int t2 = rest / k;

    int ans = t1 * k + t2 * k;

    cout << ans;

    return 0;
}
