// AGENT CODE
// P1046 - [NOIP 2005 普及组] 陶陶摘苹果
// GitHub Copilot - 2025-10-06 14:35:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int apples[10] = {0}; // 10个苹果的高度
    int reach = 0;        // 陶陶伸手能达到的高度
    
    // 读入10个苹果的高度
    for(int i = 0; i < 10; i++)
    {
        cin >> apples[i];
    }
    
    // 读入陶陶的伸手高度
    cin >> reach;
    
    // 计算陶陶最大能达到的高度（加上30cm板凳）
    int maxHeight = reach + 30;
    
    // 统计能摘到的苹果数量
    int count = 0;
    for(int i = 0; i < 10; i++)
    {
        if(apples[i] <= maxHeight)
        {
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}