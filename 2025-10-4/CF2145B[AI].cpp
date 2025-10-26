// AGENT CODE
// CF2145B - Deck of Cards
// GitHub Copilot - 2025-10-26 10:00:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    
    while(t--)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        
        // Count '0's and '1's
        int cnt0 = 0, cnt1 = 0;
        for(char c : s)
        {
            if(c == '0') cnt0++;
            else if(c == '1') cnt1++;
        }
        int cnt2 = k - cnt0 - cnt1;
        
        // min_top: all '2's become '1's
        // max_top: all '2's become '0's
        int min_top = cnt0;
        int max_top = cnt0 + cnt2;
        
        string result = "";
        for(int i = 1; i <= n; i++)
        {
            bool can_be_removed = false;
            bool can_be_kept = false;
            
            // Try all possible top_remove values
            for(int top_remove = min_top; top_remove <= max_top; top_remove++)
            {
                int bottom_remove = k - top_remove;
                
                // Check if card i is removed with this configuration
                if(i <= top_remove || i > n - bottom_remove)
                    can_be_removed = true;
                else
                    can_be_kept = true;
            }
            
            if(can_be_removed && can_be_kept)
                result += '?';
            else if(can_be_removed)
                result += '-';
            else
                result += '+';
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
