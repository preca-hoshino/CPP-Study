// AGENT CODE
// P1035 - [NOIP 2002 普及组] 级数求和
// GitHub Copilot - 2025-10-06 14:30:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k = 0;
    cin >> k;
    
    double sum = 0.0;  // 累计和S_n
    int n = 1;         // 当前项数
    
    // 循环累加直到S_n > k
    while(true)
    {
        sum += 1.0 / n;  // 累加1/n
        if(sum > k)
        {
            cout << n << endl;
            break;
        }
        n++;
    }
    
    return 0;
}