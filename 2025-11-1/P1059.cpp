#include<bits/stdc++.h>
using namespace std;
bool bow[1001];
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(bow[x]==0)
        {
            sum++;
        }
        bow[x]=1;
    }
    cout<<sum<<endl;
    int flag=0;
    for(int i=1;i<=1000;i++)
    {
        if(bow[i])
        {
            if(flag==0)
            {
                cout<<i;
                flag=1;
            }
            else
            {
                cout<<' '<<i;
            }
        }
    }
    return 0;
}