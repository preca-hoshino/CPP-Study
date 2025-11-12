// AGENT CODE
// P1024 - [NOIP 2001 提高组] 一元三次方程求解
// GitHub Copilot - 2025-11-12 00:00:00
#include<bits/stdc++.h>
using namespace std;

double a = 0, b = 0, c = 0, d = 0;

// 计算方程的值 f(x) = ax^3 + bx^2 + cx + d
double f(double x)
{
    return a*x*x*x + b*x*x + c*x + d;
}

// 二分法求解区间 [left, right] 内的根
double bisection(double left, double right)
{
    while(right - left > 0.001)
    {
        double mid = (left + right) / 2;
        if(f(mid) * f(left) < 0)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return (left + right) / 2;
}

int main()
{
    cin >> a >> b >> c >> d;
    
    vector<double> roots;
    
    // 从 -100 到 100 遍历，每次检查相邻两个整数点
    for(int i = -100; i < 100; i++)
    {
        double x1 = i;
        double x2 = i + 1;
        double fx1 = f(x1);
        double fx2 = f(x2);
        
        // 如果 f(x1) * f(x2) <= 0，说明区间内有根或端点是根
        if(fx1 * fx2 <= 0)
        {
            double root = 0;
            // 如果 fx1 接近 0，则 x1 就是根
            if(fabs(fx1) < 0.0001)
            {
                root = x1;
            }
            // 如果 fx2 接近 0，则 x2 就是根（但这种情况会在下一轮的 fx1 处理）
            else if(fabs(fx2) < 0.0001)
            {
                continue;  // 跳过，等下一轮处理
            }
            // 否则用二分法求根
            else
            {
                root = bisection(x1, x2);
            }
            
            roots.push_back(root);
            
            // 找到3个根就停止
            if(roots.size() == 3)
            {
                break;
            }
        }
    }
    
    // 输出三个根，保留2位小数
    if(roots.size() >= 3)
    {
        cout << fixed << setprecision(2);
        cout << roots[0] << " " << roots[1] << " " << roots[2];
    }
    
    return 0;
}
