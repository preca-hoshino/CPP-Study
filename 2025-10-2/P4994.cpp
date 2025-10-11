#include<bits/stdc++.h>
using namespace std;
int m;
int main()
{
    cin>>m;
    vector<int> f;
    f.push_back(0);
    f.push_back(1);
    for(int i=2;;i++)
    {
        f.push_back((f[i-1]+f[i-2])%m);
        if(f[i-1]==0&&f[i-2]==1&&f[i]==1)
        {
            cout<<i-1<<flush;
            break;
        }
    }
    return 0;
}