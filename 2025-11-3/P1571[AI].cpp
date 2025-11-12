// AGENT CODE
// P1571 - 眼红的Medusa
// GitHub Copilot - 2025-11-12 00:00:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    
    vector<int> innovation(n);
    for(int i = 0; i < n; i++)
    {
        cin >> innovation[i];
    }
    
    set<int> special;
    for(int i = 0; i < m; i++)
    {
        int x = 0;
        cin >> x;
        special.insert(x);
    }
    
    bool first = true;
    for(int i = 0; i < n; i++)
    {
        if(special.count(innovation[i]))
        {
            if(!first) cout << " ";
            cout << innovation[i];
            first = false;
        }
    }
    cout << endl;
    
    return 0;
}
