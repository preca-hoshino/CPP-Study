// AGENT CODE
// P1051 - [NOIP 2005 提高组] 谁拿了最多奖学金
// GitHub Copilot - 2025-11-12 00:00:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    
    string max_name = "";
    int max_money = 0;
    int total_money = 0;
    
    for(int i = 0; i < n; i++)
    {
        string name = "";
        int avg_score = 0;
        int class_score = 0;
        char is_cadre = 'N';
        char is_west = 'N';
        int papers = 0;
        
        cin >> name >> avg_score >> class_score >> is_cadre >> is_west >> papers;
        
        int money = 0;
        
        // 院士奖学金：8000元，平均成绩>80 && 论文>=1
        if(avg_score > 80 && papers >= 1)
        {
            money += 8000;
        }
        
        // 五四奖学金：4000元，平均成绩>85 && 班级评议>80
        if(avg_score > 85 && class_score > 80)
        {
            money += 4000;
        }
        
        // 成绩优秀奖：2000元，平均成绩>90
        if(avg_score > 90)
        {
            money += 2000;
        }
        
        // 西部奖学金：1000元，平均成绩>85 && 西部省份学生
        if(avg_score > 85 && is_west == 'Y')
        {
            money += 1000;
        }
        
        // 班级贡献奖：850元，班级评议>80 && 学生干部
        if(class_score > 80 && is_cadre == 'Y')
        {
            money += 850;
        }
        
        total_money += money;
        
        if(money > max_money)
        {
            max_money = money;
            max_name = name;
        }
    }
    
    cout << max_name << endl;
    cout << max_money << endl;
    cout << total_money << endl;
    
    return 0;
}
