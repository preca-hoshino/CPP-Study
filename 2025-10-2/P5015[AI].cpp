// AGENT CODE
// P5015 - [NOIP 2018 普及组] 标题统计
// GitHub Copilot - 2025-10-07 14:30:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    
    int count = 0;
    for(char ch : s)
    {
        if(ch != ' ' && ch != '\n')
        {
            count++;
        }
    }
    
    cout << count;
    return 0;
}
