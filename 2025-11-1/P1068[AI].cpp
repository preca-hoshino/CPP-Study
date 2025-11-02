// AGENT CODE
// P1068 - [NOIP 2009 普及组] 分数线划定
// GitHub Copilot - 2025-11-02 00:00:00
#include<bits/stdc++.h>
using namespace std;

struct Student
{
    int id;      // 报名号
    int score;   // 笔试成绩
};

// 自定义排序规则：成绩降序，成绩相同按报名号升序
bool cmp(const Student &a, const Student &b)
{
    if(a.score != b.score)
    {
        return a.score > b.score;  // 成绩降序
    }
    return a.id < b.id;  // 报名号升序
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    
    vector<Student> students(n);
    for(int i = 0; i < n; i++)
    {
        cin >> students[i].id >> students[i].score;
    }
    
    // 排序
    sort(students.begin(), students.end(), cmp);
    
    // 计算分数线排名（向下取整）
    int rank = m * 150 / 100;
    
    // 分数线为第 rank 名的成绩（索引 rank-1）
    int cutoff = students[rank - 1].score;
    
    // 统计实际进入面试的人数（所有成绩 >= 分数线的选手）
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(students[i].score >= cutoff)
        {
            count++;
        }
    }
    
    // 输出分数线和实际人数
    cout << cutoff << " " << count << endl;
    
    // 输出所有达线选手
    for(int i = 0; i < n; i++)
    {
        if(students[i].score >= cutoff)
        {
            cout << students[i].id << " " << students[i].score << endl;
        }
    }
    
    return 0;
}
