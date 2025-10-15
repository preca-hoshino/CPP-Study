#include <bits/stdc++.h>
using namespace std;
int main()
{
    string score;
    char tmp;
    while (cin >> tmp)
    {
        if (tmp == 'E')
        {
            break;
        }
        score.push_back(tmp);
    }
    int l_num = 0, w_num = 0;
    for (auto i : score)
    {
        if (i == 'L')
        {
            l_num++;
        }
        else
        {
            w_num++;
        }
        if (l_num + w_num == 11)
        {
            cout << w_num << ':' << l_num << endl;
            w_num = 0;
            l_num = 0;
        }
    }
    if (l_num != 0 || w_num != 0)
    {
        cout << w_num << ':' << l_num << endl;
        w_num = 0;
        l_num = 0;
    }
    cout << endl;
    for (auto i : score)
    {
        if (i == 'L')
        {
            l_num++;
        }
        else
        {
            w_num++;
        }
        if (l_num + w_num == 21)
        {
            cout << w_num << ':' << l_num << endl;
            w_num = 0;
            l_num = 0;
        }
    }
    if (l_num != 0 || w_num != 0)
    {
        cout << w_num << ':' << l_num << endl;
        w_num = 0;
        l_num = 0;
    }
    return 0;
}