// #pragma GCC optimize(3)
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int T, n, ans;
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n;
        int i[5]={0,0,0,0,0};
        for (i[1] = 0; i[1] * i[1] <= n; i[1]++)
        {
            for (i[2] = i[1]; i[1] * i[1] + i[2] * i[2] <= n; i[2]++)
            {
                for (i[3] = i[2]; i[1] * i[1] + i[2] * i[2] + i[3] * i[3] <= n; i[3]++)
                {
                    for (i[4] = i[3]; i[1] * i[1] + i[2] * i[2] + i[3] * i[3] + i[4] * i[4] <= n; i[4]++)
                    {
                        if (i[1] * i[1] + i[2] * i[2] + i[3] * i[3] + i[4] * i[4] == n)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}