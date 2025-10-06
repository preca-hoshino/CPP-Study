// AGENT CODE
// P1425 - 小鱼的游泳时间
// GitHub Copilot - 2025-10-06 10:30:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a = 0, b = 0, c = 0, d = 0;
    cin >> a >> b >> c >> d;
    
    // 将时间转换为分钟数
    int startMinutes = a * 60 + b;
    int endMinutes = c * 60 + d;
    
    // 计算时间差
    int totalMinutes = endMinutes - startMinutes;
    
    // 转换回小时和分钟
    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;
    
    cout << hours << " " << minutes;
    return 0;
}
