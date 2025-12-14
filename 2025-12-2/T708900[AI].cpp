// AGENT CODE
// T708900 - 役满之泪
// GitHub Copilot - 2025-12-14 10:00:00
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[13];
    for(int i = 0; i < 13; i++)
    {
        cin >> a[i];
    }

    int min_draws = 100; // Initialize with a large enough number

    // Iterate through each possible pair (13 types)
    for(int pair_idx = 0; pair_idx < 13; pair_idx++)
    {
        int needed = 0;
        for(int i = 0; i < 13; i++)
        {
            int required = (i == pair_idx) ? 2 : 1;
            if(a[i] < required)
            {
                needed += (required - a[i]);
            }
        }
        if(needed < min_draws)
        {
            min_draws = needed;
        }
    }

    cout << min_draws << endl;
    return 0;
}
