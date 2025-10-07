// AGENT CODE
// P14153 - [ICPC 2022 Nanjing R] 停停，昨日请不要再重现
// GitHub Copilot - 2025-10-07 10:45:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    
    while(T--)
    {
        int n = 0, m = 0, k = 0;
        cin >> n >> m >> k;
        
        string ops;
        cin >> ops;
        
        // 预处理：对每个初始位置，计算其轨迹经过的所有位置和最终位置
        // path[i][j] 存储位置(i,j)上的袋鼠经过的所有位置集合
        // final_pos[i][j] 存储最终位置（出界则为{-1,-1}）
        vector<vector<set<pair<int,int>>>> path(n+1, vector<set<pair<int,int>>>(m+1));
        vector<vector<pair<int,int>>> final_pos(n+1, vector<pair<int,int>>(m+1));
        
        // 对每个初始位置模拟一次
        for(int si = 1; si <= n; si++)
        {
            for(int sj = 1; sj <= m; sj++)
            {
                int i = si, j = sj;
                path[si][sj].insert({i, j}); // 记录起始位置
                
                bool out = false;
                
                // 模拟操作序列
                for(char op : ops)
                {
                    if(op == 'U') i--;
                    else if(op == 'D') i++;
                    else if(op == 'L') j--;
                    else if(op == 'R') j++;
                    
                    // 检查是否出界
                    if(i < 1 || i > n || j < 1 || j > m)
                    {
                        out = true;
                        break;
                    }
                    
                    path[si][sj].insert({i, j});
                }
                
                // 记录最终位置
                if(out)
                {
                    final_pos[si][sj] = {-1, -1};
                }
                else
                {
                    final_pos[si][sj] = {i, j};
                }
            }
        }
        
        int answer = 0;
        
        // 枚举每个可能的洞位置
        for(int ih = 1; ih <= n; ih++)
        {
            for(int jh = 1; jh <= m; jh++)
            {
                int surviving = 0;
                
                // 检查每个初始位置的袋鼠
                for(int si = 1; si <= n; si++)
                {
                    for(int sj = 1; sj <= m; sj++)
                    {
                        // 如果初始位置就是洞，没有袋鼠
                        if(si == ih && sj == jh)
                        {
                            continue;
                        }
                        
                        // 检查轨迹是否经过洞
                        if(path[si][sj].count({ih, jh}))
                        {
                            continue; // 掉入洞
                        }
                        
                        // 检查是否出界
                        if(final_pos[si][sj].first == -1)
                        {
                            continue; // 出界
                        }
                        
                        // 袋鼠存活
                        surviving++;
                    }
                }
                
                if(surviving == k)
                {
                    answer++;
                }
            }
        }
        
        cout << answer << endl;
    }
    
    return 0;
}
