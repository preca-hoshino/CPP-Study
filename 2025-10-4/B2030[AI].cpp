// AGENT CODE
// B2030 - 计算线段长度
// GitHub Copilot - 2025-10-23 00:00:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double xa = 0, ya = 0, xb = 0, yb = 0;
    cin >> xa >> ya;
    cin >> xb >> yb;
    double distance = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
    cout << fixed << setprecision(3) << distance;
    return 0;
}
