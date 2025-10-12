#include <bits/stdc++.h>
using namespace std;

int n, c1, c2, Ans(0);

int main()
{
    scanf("%d%d%d", &n, &c1, &c2);
    c1 = min(c1,c2);
    if (c1 * 2 <= c2)
    {
        cout << 3 * n * c1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2])
            Ans += c1 + c2;
        else
            Ans += 3 * c1;
    }
    cout << Ans << endl;
    return 0;
}