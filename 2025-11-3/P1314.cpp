#include <bits/stdc++.h>
using namespace std;
long long n, m, s;
long long min_s = LLONG_MAX;
long long qzw[200001];  // 前缀和：符合条件的矿石价值和
long long qzh[200001];  // 前缀和：符合条件的矿石个数
struct stone
{
    int value;
    int weight;
};
stone num[200001];
struct interval
{
    int left_i;
    int right_i;
};
interval sum[200001];
void check(int left, int right)
{
    if (left > right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    
    // 构建前缀和数组
    for (int i = 1; i <= n; i++)
    {
        if (num[i].weight >= mid)
        {
            qzh[i] = qzh[i - 1] + 1;              // 符合的矿石个数
            qzw[i] = qzw[i - 1] + num[i].value;   // 区间内的矿石价值和
        }
        else
        {
            qzw[i] = qzw[i - 1];
            qzh[i] = qzh[i - 1];
        }
    }
    
    // 使用前缀和快速计算Y值
    long long respose = 0;
    for (int i = 1; i <= m; i++)
    {
        long long cnt = qzh[sum[i].right_i] - qzh[sum[i].left_i - 1];    // 符合条件的矿石数量
        long long val = qzw[sum[i].right_i] - qzw[sum[i].left_i - 1];    // 符合条件的矿石价值和
        respose += cnt * val;
    }
    
    // 更新最小差值
    min_s = min(min_s, abs(s - respose));
    
    // 二分搜索（修正逻辑）
    if (respose <= s)
    {
        // Y值过小或相等，需要减小W（增加合格的石头）
        check(left, mid - 1);
    }
    else
    {
        // Y值过大，需要增大W（减少合格的石头）
        check(mid + 1, right);
    }
}
int main()
{
    cin >> n >> m >> s;
    int max_weight = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin >> num[i].weight >> num[i].value;
        max_weight = max(num[i].weight, max_weight);
    }
    for (long long i = 1; i <= m; i++)
    {
        cin >> sum[i].left_i >> sum[i].right_i;
    }
    check(0, max_weight);
    cout << min_s;
    return 0;
}