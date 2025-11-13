// AGENT CODE
// P1902 - 刺杀大使
// GitHub Copilot - 2025-11-14 00:00:00
#include<bits/stdc++.h>
using namespace std;

int n = 0, m = 0;
int p[1005][1005];
bool vis[1005][1005];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool check(int maxDamage)
{
    memset(vis, false, sizeof(vis));
    queue<pair<int, int>> q;
    
    // 从第1行所有伤害值<=maxDamage的房间开始
    for(int j = 0; j < m; j++)
    {
        if(p[0][j] <= maxDamage)
        {
            q.push({0, j});
            vis[0][j] = true;
        }
    }
    
    // BFS搜索
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && p[nx][ny] <= maxDamage)
            {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    // 检查第n行是否全部可达
    for(int j = 0; j < m; j++)
    {
        if(!vis[n-1][j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    
    int maxP = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> p[i][j];
            maxP = max(maxP, p[i][j]);
        }
    }
    
    // 二分答案
    int left = 0, right = maxP, ans = maxP;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(check(mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    cout << ans;
    return 0;
}
