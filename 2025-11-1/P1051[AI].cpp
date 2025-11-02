// AGENT CODE
// P1051 - [NOIP 2005 提高组] 谁拿了最多奖学金
// GitHub Copilot - 2025-11-02 00:00:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    
    string maxName = "";      // 获得最多奖金的学生姓名
    int maxScholarship = -1;  // 最多奖金数额（初始化为-1以确保第一个学生会被记录）
    int totalScholarship = 0; // 所有学生奖金总和
    
    for(int i = 0; i < n; i++)
    {
        string name = "";
        int finalScore = 0;      // 期末平均成绩
        int classScore = 0;      // 班级评议成绩
        char isCadre;            // 是否学生干部 Y/N
        char isWest;             // 是否西部省份 Y/N
        int papers = 0;          // 发表论文数
        
        cin >> name >> finalScore >> classScore >> isCadre >> isWest >> papers;
        
        int scholarship = 0;     // 当前学生的奖学金总额
        
        // 1. 院士奖学金：期末成绩 > 80 且 论文数 >= 1
        if(finalScore > 80 && papers >= 1)
        {
            scholarship += 8000;
        }
        
        // 2. 五四奖学金：期末成绩 > 85 且 班级评议 > 80
        if(finalScore > 85 && classScore > 80)
        {
            scholarship += 4000;
        }
        
        // 3. 成绩优秀奖：期末成绩 > 90
        if(finalScore > 90)
        {
            scholarship += 2000;
        }
        
        // 4. 西部奖学金：期末成绩 > 85 且 是西部学生
        if(finalScore > 85 && isWest == 'Y')
        {
            scholarship += 1000;
        }
        
        // 5. 班级贡献奖：班级评议 > 80 且 是学生干部
        if(classScore > 80 && isCadre == 'Y')
        {
            scholarship += 850;
        }
        
        // 累加总奖金
        totalScholarship += scholarship;
        
        // 更新最大值（只在第一次出现最大值时更新）
        if(scholarship > maxScholarship)
        {
            maxScholarship = scholarship;
            maxName = name;
        }
    }
    
    // 输出结果
    cout << maxName << endl;
    cout << maxScholarship << endl;
    cout << totalScholarship << endl;
    
    return 0;
}
