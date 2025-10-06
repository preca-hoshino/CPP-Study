// AGENT CODE
// P1085 - [NOIP 2004 普及组] 不高兴的津津
// GitHub Copilot - 2025-10-06 14:40:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int school = 0, mom = 0;      // 学校上课时间和妈妈安排时间
    int maxHours = 0;             // 最长的上课时间
    int unhappiestDay = 0;        // 最不高兴的那天
    
    // 遍历7天
    for(int day = 1; day <= 7; day++)
    {
        cin >> school >> mom;
        int totalHours = school + mom;  // 当天总上课时间
        
        // 如果超过8小时且比之前记录的最长时间更长
        if(totalHours > 8 && totalHours > maxHours)
        {
            maxHours = totalHours;
            unhappiestDay = day;
        }
    }
    
    cout << unhappiestDay << endl;
    return 0;
}