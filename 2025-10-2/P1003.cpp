#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,b,g,k;
    vector<tuple<int,int,int,int>>num;
    for(int t=1;t<=n;t++)
    {
        cin>>a>>b>>g>>k;
        num.push_back(make_tuple(a,b,g,k));
    }
    int x,y;
    cin>>x>>y;
    int ans=-1;
    int i=1;
    for(auto index:num)
    {
        if(x>=get<0>(index)&&x<=get<0>(index)+get<2>(index)-1&&y>=get<1>(index)&&y<=get<1>(index)+get<3>(index)-1)
        {
            ans=i;
        }
        i++;
    }
    cout<<ans;
    return 0;
}