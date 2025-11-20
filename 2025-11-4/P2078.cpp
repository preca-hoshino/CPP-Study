#include <bits/stdc++.h>
using namespace std;
int n, m, p, q;
struct collection
{
    int node[10001];
    void _init(int x)
    {
        for (int i = 1; i <= x; i++)
        {
            this->node[i] = i;
        }
    }
    int _find(int x)
    {
        if (this->node[x] != x)
        {
            this->node[x] = this->_find(this->node[x]);
        }
        return this->node[x];
    }
    void _union(int x, int y)
    {
        int root_x = this->_find(x);
        int root_y = this->_find(y);
        if (root_x == root_y)
        {
            return;
        }
        else
        {
            if (root_x == 1)
            {
                this->node[root_y] = 1;
                return;
            }
            if (root_y == 1)
            {
                this->node[root_x] = 1;
                return;
            }
            this->node[root_x] = root_y;
            return;
        }
    }
};
collection num1, num2;
int main()
{
    cin >> n >> m >> p >> q;
    int tmp_1 = 0, tmp_2 = 0;
    num1._init(n);
    num2._init(m);
    for (int i = 0; i < p; i++)
    {
        cin >> tmp_1 >> tmp_2;
        num1._union(abs(tmp_1), abs(tmp_2));
    }
    for (int i = 0; i < q; i++)
    {
        cin >> tmp_1 >> tmp_2;
        num2._union(abs(tmp_1), abs(tmp_2));
    }
    int man_sum = 0, woman_sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (num1._find(i) == num1._find(1))
        {
            man_sum++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (num2._find(i) == num2._find(1))
        {
            woman_sum++;
        }
    }
    cout << min(man_sum,woman_sum);
    return 0;
}