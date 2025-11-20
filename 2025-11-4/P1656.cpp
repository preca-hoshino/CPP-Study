#include <bits/stdc++.h>
using namespace std;
int n, m;
struct collection
{
    int node[100001];
    void _init()
    {
        for (int i = 1; i <= n; i++)
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
            this->node[root_x] = root_y;
            return;
        }
    }
};
collection num;
vector<pair<int, int>> road;
int main()
{
    cin >> n >> m;
    int tmp_1 = 0, tmp_2 = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp_1 >> tmp_2;
        if (tmp_1 < tmp_2)
        {
            road.push_back(make_pair(tmp_1, tmp_2));
        }
        else
        {
            road.push_back(make_pair(tmp_2, tmp_1));
        }
    }
    sort(road.begin(), road.end(), [](auto x, auto y) -> bool
         {
        if(x.first==y.first)
        {
            return x.second<y.second;
        }
        return x.first<y.first; });
    for (int i = 0; i < m; i++)
    {
        num._init();
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                continue;
            }
            num._union(road[j].first, road[j].second);
        }
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (num._find(j) == j)
            {
                sum++;
            }
        }
        if (sum == 2)
        {
            cout << road[i].first << ' ' << road[i].second << endl;
        }
    }
    return 0;
}