#include <bits/stdc++.h>
using namespace std;

int n, ans(0);
vector<string> s;
map<string, int> idx;
bool is_valid[100010];

bool cmp(string A, string B)
{
    return A.size() < B.size();
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string ss;
        cin >> ss;
        if (ss.size() >= 17)
            continue;
        s.push_back(ss);
    }
    n = s.size();
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        idx[s[i]] = i;
        is_valid[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        string tmp = s[i];
        int sz = tmp.size();
        if (tmp.size() == 1)
        {
            //cout << idx[tmp] << ' ' << i << ' ' << tmp << endl;
            is_valid[i] = true;
            ans = max(ans, 1);
            continue;
        }
        int fl = true;
        for (int k = 0; k < sz; k++)
        {
            string now = "";
            for (int j = 0; j < sz; j++)
            {
                if (k == j)
                    continue;
                now += tmp[j];
            }
            //cout << now << ' ' << idx[now] << ' ' << is_valid[idx[now]] << endl;
            if ((idx[now] == 0 && now != s[0]) || !is_valid[idx[now]])
            {
                fl = false;
                break;
            }
        }
        if (fl)
        {
            is_valid[i] = true;
            ans = max(ans, sz);
        }
    }
    cout << ans << endl;
}