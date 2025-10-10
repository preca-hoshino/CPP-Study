#include<bits/stdc++.h>
using namespace std;
int ans,add_sum;
vector<int> num;
int n,k;
set<int>primary;
bool check(int x)
{
    if(primary.find(x)!=primary.end())
    {
        return 1;
    }
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            return 0;
        }
    }
    primary.insert(x);
    return 1;
}
void dfs(int index,int sum)
{
    if(sum==k)
    {
        // cout<<add_sum<<endl;
        if(check(add_sum))
        {
            ans++;
        }
        return;
    }
    if(index>=n)
    {
        return;
    }
    add_sum+=num[index];
    dfs(index+1,sum+1);
    add_sum-=num[index];
    dfs(index+1,sum);
    return;
}
int main()
{
    cin>>n>>k;
    int tmp;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        num.push_back(tmp);
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     freopen("P1036.out", "w", stdout);
//     for(int x=3;x<5000000;x++)
//     {
//         bool tmp=0;
//         for(int i=2;i<x;i++)
//         {
//             if(x%i==0)
//             {
//                 tmp=1;
//                 break;
//             }
//         }
//         if(tmp==0)
//         {
//             cout<<x<<',';
//         }
//     }
//     fclose(stdout);
//     return 0;
// }