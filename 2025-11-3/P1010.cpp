#include <bits/stdc++.h>
using namespace std;
int n;
void print(int x)
{
    if (x == 0)
    {
        cout << "0";
        return;
    }
    if (x == 2)
    {
        cout << "2";
        return;
    }
    int sum = x;
    while (sum)
    {
        int power = (int)(log(sum) / log(2));
        cout << "2";
        if (power == 1)
        {
        }
        else
        {
            cout << "(";
            print(power);
            cout << ")";
        }
        sum -= pow(2, power);
        if (sum != 0)
        {

            cout << "+";
        }
    }
    return;
}
int main()
{
    cin >> n;
    print(n);
    // cout << endl;
    return 0;
}