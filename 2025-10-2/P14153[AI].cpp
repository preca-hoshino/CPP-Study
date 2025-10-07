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
        
        int answer = 0;
        
        // 枚举每个可能的洞位置
        for(int ih = 1; ih <= n; ih++)
        {
            for(int jh = 1; jh <= m; jh++)
            {
                // 用map记录当前有袋鼠的位置
                map<pair<int,int>, int> kangaroos;
                
                // 初始化：除洞外每个位置都有一只袋鼠
                for(int i = 1; i <= n; i++)
                {
                    for(int j = 1; j <= m; j++)
                    {
                        if(i != ih || j != jh)
                        {
                            kangaroos[{i, j}] = 1;
                        }
                    }
                }
                
                // 模拟每个操作
                for(char op : ops)
                {
                    map<pair<int,int>, int> next_kangaroos;
                    
                    for(auto& p : kangaroos)
                    {
                        int i = p.first.first;
                        int j = p.first.second;
                        int count = p.second;
                        
                        int ni = i, nj = j;
                        
                        // 根据操作移动
                        if(op == 'U') ni = i - 1;
                        else if(op == 'D') ni = i + 1;
                        else if(op == 'L') nj = j - 1;
                        else if(op == 'R') nj = j + 1;
                        
                        // 检查是否掉入洞或出界
                        if(ni < 1 || ni > n || nj < 1 || nj > m)
                        {
                            // 出界，袋鼠被移除
                            continue;
                        }
                        if(ni == ih && nj == jh)
                        {
                            // 掉入洞，袋鼠被移除
                            continue;
                        }
                        
                        // 袋鼠存活，移动到新位置
                        next_kangaroos[{ni, nj}] += count;
                    }
                    
                    kangaroos = next_kangaroos;
                }
                
                // 统计剩余袋鼠数
                int remaining = 0;
                for(auto& p : kangaroos)
                {
                    remaining += p.second;
                }
                
                // 检查是否等于k
                if(remaining == k)
                {
                    answer++;
                }
            }
        }
        
        cout << answer << endl;
    }
    
    return 0;
}
