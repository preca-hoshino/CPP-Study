#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e18;
long long l, k;
int input[100001];
long long max_n = -1, min_n = -1;
bool found = false;
void find_min(long long left, long long right)
{
    if (left > right)
    {
        return;
    }
    long long mid = left + (right - left) / 2;
    long long tmp = 0;
    int problem_sum = 0;
    for (int i = 1; i <= l; i++)
    {
        tmp = max(tmp + input[i], 0LL);  // 关键：先加再取max
        if (tmp >= mid)
        {
            problem_sum++;
            tmp = 0;
        }
    }
    if (problem_sum == k)
    {
        found = true;
        min_n = mid;
        find_min(left, mid - 1); // 继续向左找更小的
    }
    else if (problem_sum > k)
    {
        // 提交次数太多，n太小，向右搜索
        find_min(mid + 1, right);
    }
    else
    {
        // 提交次数太少，n太大，向左搜索
        find_min(left, mid - 1);
    }
}

void find_max(long long left, long long right)
{
    if (left > right)
    {
        return;
    }
    long long mid = left + (right - left) / 2;
    long long tmp = 0;
    int problem_sum = 0;
    for (int i = 1; i <= l; i++)
    {
        tmp = max(tmp + input[i], 0LL);  // 关键：先加再取max
        if (tmp >= mid)
        {
            problem_sum++;
            tmp = 0;
        }
    }
    if (problem_sum == k)
    {
        max_n = mid;
        find_max(mid + 1, right); // 继续向右找更大的
    }
    else if (problem_sum > k)
    {
        // 提交次数太多，n太小，向右搜索
        find_max(mid + 1, right);
    }
    else
    {
        // 提交次数太少，n太大，向左搜索
        find_max(left, mid - 1);
    }
}
int main()
{
    cin >> l >> k;
    for (int i = 1; i <= l; i++)
    {
        cin >> input[i];
    }

    // 先找最小值
    find_min(1, MAXN);

    if (!found)
    {
        cout << -1;
        return 0;
    }

    // 再找最大值
    find_max(1, MAXN);

    cout << min_n << " " << max_n;
    return 0;
}