// AGENT CODE
// P5587 - 打字练习
// GitHub Copilot - 2025-10-08 00:00:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> standard;
    string line = "";
    
    // 读取范文（范文也可能包含退格键，需要处理）
    while(getline(cin, line))
    {
        if(line == "EOF")
        {
            break;
        }
        
        // 处理范文中的退格键
        string processed = "";
        for(char ch : line)
        {
            if(ch == '<')
            {
                if(!processed.empty())
                {
                    processed.pop_back();
                }
            }
            else
            {
                processed += ch;
            }
        }
        standard.push_back(processed);
    }
    
    // 读取输入并处理退格键
    vector<string> input;
    string current = "";
    
    while(getline(cin, line))
    {
        if(line == "EOF")
        {
            break;
        }
        
        // 处理当前行的字符
        for(char ch : line)
        {
            if(ch == '<')
            {
                // 退格：删除当前行最后一个字符（如果非空）
                if(!current.empty())
                {
                    current.pop_back();
                }
            }
            else
            {
                current += ch;
            }
        }
        
        // 当前行处理完毕，保存并开始新行
        input.push_back(current);
        current = "";
    }
    
    // 读取时间
    int T = 0;
    cin >> T;
    
    // 逐行逐位比较，统计正确字符数
    int correct = 0;
    int n = min(standard.size(), input.size());
    
    for(int i = 0; i < n; i++)
    {
        int len = min(standard[i].length(), input[i].length());
        for(int j = 0; j < len; j++)
        {
            if(standard[i][j] == input[i][j])
            {
                correct++;
            }
        }
    }
    
    // 计算KPM = (correct / T) * 60，四舍五入
    int kpm = (int)round(correct * 60.0 / T);
    
    cout << kpm;
    
    return 0;
}
