#include <bits/stdc++.h>
using namespace std;
int num[500001];
int ans;
int l, m, n;
bool judge(int x)
{
    int sum = 0;
    int now = 0;
    int i = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (num[i] - num[now] < x)
        {
            sum++;
        }
        else
        {
            now = i;
        }
    }
    if (sum > m)
    {
        return 0;
    }
    else
    {

        return 1;
    }
}
void search(int left, int right)
{
    if (left > right)
    {
        return;
    }
    int mid = (left + right) / 2;
    if (judge(mid))
    {
        ans = mid;
        search(mid + 1, right);
    }
    else
    {
        search(left, mid - 1);
    }
}
int main()
{
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    num[n + 1] = l;
    search(1, l);
    cout << ans;
    return 0;
}