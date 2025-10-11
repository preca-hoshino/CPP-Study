#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> num(n+1);
    num[0]=1;
    num[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i>=j)
            {
                num[i]+=num[i-j];
                num[i]%=100003;
            }
        }
    }
    cout<<num[n];
    return 0;
}