// AGENT CODE
// CF2145C - Monocarp's String
// GitHub Copilot - 2025-10-26 10:15:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    
    while(t--)
    {
        int n = 0;
        cin >> n;
        string s;
        cin >> s;
        
        // Calculate prefix sum: prefix[i] = (count of 'a' in s[0..i-1]) - (count of 'b' in s[0..i-1])
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + (s[i] == 'a' ? 1 : -1);
        }
        
        int total_diff = prefix[n];
        
        // If already balanced
        if(total_diff == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        
        // Find minimum length substring to remove
        // We need to remove substring [l, r] such that:
        // prefix[r+1] - prefix[l] = total_diff
        int min_length = n + 1;
        
        for(int l = 0; l < n; l++)
        {
            for(int r = l; r < n; r++)
            {
                int substring_diff = prefix[r + 1] - prefix[l];
                if(substring_diff == total_diff)
                {
                    int length = r - l + 1;
                    min_length = min(min_length, length);
                }
            }
        }
        
        // If we need to remove the entire string
        if(min_length == n)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << min_length << "\n";
        }
    }
    
    return 0;
}
