// AGENT CODE
// P1309 - [NOIP 2011 普及组] 瑞士轮
// GitHub Copilot - 2025-11-12 00:00:00
#include<bits/stdc++.h>
using namespace std;

struct Player
{
    int id;     // 编号
    int score;  // 总分
    int power;  // 实力值
};

// 排序规则：分数降序，分数相同编号升序
bool cmp(const Player& a, const Player& b)
{
    if(a.score != b.score)
    {
        return a.score > b.score;
    }
    return a.id < b.id;
}

int main()
{
    int n = 0, r = 0, q = 0;
    cin >> n >> r >> q;
    
    int total = 2 * n;
    vector<Player> players(total);
    
    // 读取初始分数
    for(int i = 0; i < total; i++)
    {
        players[i].id = i + 1;
        cin >> players[i].score;
    }
    
    // 读取实力值
    for(int i = 0; i < total; i++)
    {
        cin >> players[i].power;
    }
    
    // 初始排序
    sort(players.begin(), players.end(), cmp);
    
    // 进行R轮比赛
    for(int round = 0; round < r; round++)
    {
        vector<Player> winners, losers;
        winners.reserve(n);
        losers.reserve(n);
        
        // 配对比赛
        for(int i = 0; i < total; i += 2)
        {
            if(players[i].power > players[i + 1].power)
            {
                players[i].score++;
                winners.push_back(players[i]);
                losers.push_back(players[i + 1]);
            }
            else
            {
                players[i + 1].score++;
                winners.push_back(players[i + 1]);
                losers.push_back(players[i]);
            }
        }
        
        // 归并两个有序数组（关键优化：胜者组和败者组天然有序）
        int i = 0, j = 0, k = 0;
        while(i < n && j < n)
        {
            if(cmp(winners[i], losers[j]))
            {
                players[k++] = winners[i++];
            }
            else
            {
                players[k++] = losers[j++];
            }
        }
        while(i < n)
        {
            players[k++] = winners[i++];
        }
        while(j < n)
        {
            players[k++] = losers[j++];
        }
    }
    
    // 输出第Q名的编号
    cout << players[q - 1].id;
    
    return 0;
}
