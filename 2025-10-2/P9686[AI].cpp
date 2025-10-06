// AGENT CODE
// P9686 - 【Judg】评测结果判断
// GitHub Copilot - 2025-10-06 10:30:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    vector<int> failed;
    for(int i = 1; i <= n; i++)
    {
        string result;
        cin >> result;
        if(result != "AC")
        {
            failed.push_back(i);
        }
    }
    for(int i = 0; i < failed.size(); i++)
    {
        if(i > 0)
        {
            cout << " ";
        }
        cout << failed[i];
    }
    return 0;
}
