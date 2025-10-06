// AGENT CODE
// B2024 - 输出浮点数
// GitHub Copilot - 2025-10-06 10:40:00
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n = 0.0;
    cin >> n;
    
    // %f 格式（默认6位小数）
    cout << fixed << setprecision(6) << n << endl;
    
    // %f 保留5位小数
    cout << fixed << setprecision(5) << n << endl;
    
    // %e 科学计数法（6位小数）
    cout << scientific << setprecision(6) << n << endl;
    
    // %g 格式（取消fixed和scientific，使用默认格式）
    cout.unsetf(ios::fixed | ios::scientific);
    cout << setprecision(6) << n << endl;
    
    return 0;
}
