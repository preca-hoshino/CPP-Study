// AGENT CODE
// P1014 - Cantor 表
// GitHub Copilot - 2025-10-12 12:00:00
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;
    // find smallest t such that t*(t+1)/2 >= N
    long long t = (long long)ceil((sqrt(1.0 + 8.0 * N) - 1.0) / 2.0);
    long long prev = t * (t - 1) / 2;
    long long pos = N - prev; // 1-based position within diagonal t
    long long num, den;
    if (t % 2 == 0)
    {
        num = pos;
        den = t - pos + 1;
    }
    else
    {
        num = t - pos + 1;
        den = pos;
    }
    cout << num << "/" << den;
    return 0;
}
