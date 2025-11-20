#include<bits/stdc++.h>
using namespace std;
int n,m;
struct collection
{
    int node[100001];
    void _init()
    {
        for(int i=1;i<=n;i++)
        {
            this->node[i]=i;
        }
    }
    int _find(int x)
    {
        if(this->node[x]!=x)
        {
            this->node[x]=this->_find(this->node[x]);
        }
        return this->node[x];
    }
    void _union(int x,int y)
    {
        int root_x=this->_find(x);
        int root_y=this->_find(y);
        if(root_x==root_y)
        {
            return ;
        }
        else
        {
            this->node[root_x]=root_y;
            return ;
        }
    }
};
collection num;
int main()
{
    cin>>n>>m;
    int tmp_1=0,tmp_2=0;
    num._init();
    for(int i=0;i<m;i++)
    {
        cin>>tmp_1>>tmp_2;
        num._union(tmp_1,tmp_2);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(num._find(i)==i)
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}