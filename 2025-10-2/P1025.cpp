#include <bits/stdc++.h>
using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    // f(n,k)=f(n-1,k)+k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            if (i >= j)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
                /*
                这个方程背后的逻辑是：
                    dp[i-1][j-1]：拆分中包含1的方案数。如果方案中有1，去掉这个1后，剩下的 i-1 被拆分成 j-1 个数
                    dp[i-j][j]：拆分中不包含1的方案数。如果最小数≥2，可以从每个数中各减1，得到 i-j 拆分成 j 个数的方案
                */
            }
        }
    }
    cout << dp[n][k] << flush;
    return 0;
}