// AGENT CODE
// B2031 - 计算三角形面积
// GitHub Copilot - 2025-10-23 00:00:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double area = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    cout << fixed << setprecision(2) << area;
    return 0;
}
