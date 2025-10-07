#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    // 初始化二维数组，行数n+1，列数k+1
    vector<vector<int>> arange(n + 1, vector<int>(k + 1, 0));
    int free_time = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> free_time;
            arange[i][free_time] = j;
        }
    }
    set<int>nums;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(arange[j][i]==0) continue;
            nums.insert(arange[j][i]);
        }
        cout<<nums.size();
        nums.clear();
        if(i!=k)
        {
            cout<<' ';
        }
    }
    return 0;
}