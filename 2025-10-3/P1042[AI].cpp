// AGENT CODE
// P1042 - [NOIP 2003 普及组] 乒乓球
// GitHub Copilot - 2025-10-15 00:00:00

/*
 * 题目要求：统计乒乓球比赛在11分制和21分制下的比分
 * 
 * 规则：
 * - 达到N分（11或21）且分差≥2时，一局结束
 * - 一局结束后立即开始下一局
 * - W表示华华得分，L表示对手得分
 * - E表示记录结束
 * 
 * 解题思路：
 * 1. 读取所有比赛记录直到遇到E
 * 2. 分别用11分制和21分制规则模拟比赛
 * 3. 每次得分后判断是否满足结束条件
 * 4. 输出每一局的比分
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include<bits/stdc++.h>
using namespace std;

// 计算并输出比分，limit是分制（11或21）
void calculate(const string& score, int limit)
{
    int w = 0, l = 0;  // 华华得分和对手得分
    
    for(char c : score)
    {
        // 统计得分
        if(c == 'W')
        {
            w++;
        }
        else  // c == 'L'
        {
            l++;
        }
        
        // 判断是否一局结束
        // 条件：任意一方达到limit分且分差≥2
        if((w >= limit || l >= limit) && abs(w - l) >= 2)
        {
            cout << w << ":" << l << endl;
            w = 0;
            l = 0;
        }
    }
    
    // 输出最后一局的比分（即使未结束）
    cout << w << ":" << l << endl;
}

int main()
{
    string score = "";
    char ch;
    
    // 读取所有比赛记录直到遇到E
    while(cin >> ch)
    {
        if(ch == 'E')
        {
            break;
        }
        // 只保存W和L
        if(ch == 'W' || ch == 'L')
        {
            score += ch;
        }
    }
    
    // 11分制
    calculate(score, 11);
    
    // 输出空行分隔
    cout << endl;
    
    // 21分制
    calculate(score, 21);
    
    return 0;
}

/*
 * 示例分析：
 * 输入: WWWWWWWWWWWWWWWWWWWWWWLW
 * 共24个字符：22个W，2个L
 * 
 * 11分制：
 * - 前11个W：11:0（第一局结束）
 * - 接下来11个W：11:0（第二局结束）
 * - 剩余1个L，1个W：1:1（第三局未结束）
 * 
 * 21分制：
 * - 前21个W：21:0（第一局结束）
 * - 剩余1个W，2个L：2:1（第二局未结束）
 * 
 * 关键点：
 * 1. 分差必须≥2才能结束一局
 * 2. 即使未结束的局也要输出当前比分
 * 3. 两部分之间有空行
 */
