// AGENT CODE
// B4133 - [信息与未来 2014] 最大连续部分和
// GitHub Copilot - 2025-11-12 00:00:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0;
    cin >> n;
    
    long long current_sum = 0;
    long long max_sum = LLONG_MIN;
    
    for(int i = 0; i < n; i++)
    {
        long long x = 0;
        cin >> x;
        current_sum += x;
        max_sum = max(max_sum, current_sum);
        if(current_sum < 0)
        {
            current_sum = 0;
        }
    }
    
    cout << max_sum;
    return 0;
}
