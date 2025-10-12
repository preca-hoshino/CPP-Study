#include <bits/stdc++.h>
using namespace std;

long long pow2[110];

int main()
{   
    pow2[0] = 1;
    for(int i=1;i<=40;i++)pow2[i] = 2*pow2[i-1];
    int T;
    cin >> T;
    long long a, b, c;
    while (T--)
    {
        cin >> a >> b >> c;
        auto n = (int)(log(c) / log(2) + 1) ;
        // cout<<(int)(log(c)/log(2)+1)*a+b<<endl;
        long long ans;
        memset(&ans, 0x3f, sizeof(ans));
        for (int i = 0; i <= n; i++)
        {
            ans = min(ans, 1ll * (n - i) * a + 1ll * ((c+pow2[n-i]-1)/pow2[n-i]) * b);
        }
        cout << ans << endl;
    }
    return 0;
}