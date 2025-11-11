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

// 归并两个有序数组
void merge(vector<Player>& winners, vector<Player>& losers, vector<Player>& all)
{
    int i = 0, j = 0;
    int n1 = winners.size(), n2 = losers.size();
    all.clear();
    
    while(i < n1 && j < n2)
    {
        if(cmp(winners[i], losers[j]))
        {
            all.push_back(winners[i]);
            i++;
        }
        else
        {
            all.push_back(losers[j]);
            j++;
        }
    }
    
    while(i < n1)
    {
        all.push_back(winners[i]);
        i++;
    }
    
    while(j < n2)
    {
        all.push_back(losers[j]);
        j++;
    }
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
        
        // 配对比赛
        for(int i = 0; i < total; i += 2)
        {
            Player p1 = players[i];
            Player p2 = players[i + 1];
            
            if(p1.power > p2.power)
            {
                p1.score++;
                winners.push_back(p1);
                losers.push_back(p2);
            }
            else
            {
                p2.score++;
                winners.push_back(p2);
                losers.push_back(p1);
            }
        }
        
        // 胜者组和败者组内部排序
        sort(winners.begin(), winners.end(), cmp);
        sort(losers.begin(), losers.end(), cmp);
        
        // 归并
        merge(winners, losers, players);
    }
    
    // 输出第Q名的编号
    cout << players[q - 1].id;
    
    return 0;
}
