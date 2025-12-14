// AGENT CODE
// T708530 - 武汉之泪
// GitHub Copilot - 2025-12-14 10:30:00
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];

    if (n == 1) {
        if (a[0] == b[0]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }

    vector<long long> xa(n), xb(n);
    xa[0] = a[0] - 1;
    for(int i=1; i<n; ++i) xa[i] = a[i] - a[i-1] - 1;

    xb[0] = b[0] - 1;
    for(int i=1; i<n; ++i) xb[i] = b[i] - b[i-1] - 1;

    bool za = false;
    for(int i=1; i<n; ++i) if(xa[i] == 0) za = true;

    bool zb = false;
    for(int i=1; i<n; ++i) if(xb[i] == 0) zb = true;

    if (za && zb) {
        long long sa = 0, sb = 0;
        if (n % 2 != 0) {
            // Odd n: Invariant is sum of odd indices (0-based: 0, 2, 4...)
            // Wait, problem indices are 1-based.
            // My x is 0-based. x[0] is x_1.
            // x_1, x_3, ... are indices 0, 2, ...
            for(int i=0; i<n; i+=2) sa += xa[i];
            for(int i=0; i<n; i+=2) sb += xb[i];
        } else {
            // Even n: Invariant is sum of even indices (0-based: 1, 3, 5...)
            // x_2, x_4, ... are indices 1, 3, ...
            for(int i=1; i<n; i+=2) sa += xa[i];
            for(int i=1; i<n; i+=2) sb += xb[i];
        }
        if (sa == sb) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else {
        if (xa == xb) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}
