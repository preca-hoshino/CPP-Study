// AGENT CODE
// T708459 - 月影戀
// GitHub Copilot - 2025-12-14 10:10:00
#include <bits/stdc++.h>
using namespace std;
void work()
{
    long long h_ans = 0;
    long long a = 1LL << 60;
    while (1)
    {
        long long b = a - h_ans;
        cout << "? " << a << " " << b << endl;
        cout.flush();
        long long g;
        cin >> g;
        if (g == a)
        {
            break;
        }

        h_ans += g;
    }

    cout << "! " << h_ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }

    return 0;
}
