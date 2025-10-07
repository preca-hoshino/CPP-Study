// AGENT CODE
// P14161 - [ICPC 2022 Nanjing R] 完美回文
// GitHub Copilot - 2025-10-07 15:15:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T = 0;
    cin >> T;
    
    while(T--)
    {
        string s;
        cin >> s;
        
        int n = s.length();
        
        // 统计每个字符出现的次数
        map<char, int> cnt;
        for(char ch : s)
        {
            cnt[ch]++;
        }
        
        // 找出出现次数最多的字符
        int max_count = 0;
        for(auto& p : cnt)
        {
            max_count = max(max_count, p.second);
        }
        
        // 需要修改的次数 = 总长度 - 最多字符的数量
        cout << n - max_count << endl;
    }
    
    return 0;
}
