// AGENT CODE
// T708900 - 役满之泪
// GitHub Copilot - 2025-12-14 10:00:00
#include<bits/stdc++.h>
using namespace std;
int card[13];
int min_turn = 99999;
int main()
{
    for(auto &i:card)
    {
        cin >> i;
    }
    for(int index_pair = 0; index_pair < 13; index_pair++)
    {
        int sum = 0;
        for(int i = 0; i < 13; i++)
        {
            int required = (i == index_pair) ? 2 : 1;
            if(card[i] < required)
            {
                sum += (required - card[i]);
            }
        }
        if(sum < min_turn)
        {
            min_turn = sum;
        }
    }

    cout << min_turn << endl;
    return 0;
}
