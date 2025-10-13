#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>num(n,vector<int>(n));
    int x=0,y=(n-1)/2;
    for(int i=1;i<=n*n;i++)
    {
        num[x][y]=i;
        if(x==0&&y!=n-1)
        {
            x=n-1;
            y++;
        }
        else if(x!=0&&y==n-1)
        {
            x--;
            y=0;
        }
        else if(x==0&&y==n-1)
        {
            x++;
        }
        else
        {
            if(num[x-1][y+1]==0)
            {
                x--;
                y++;
            }
            else
            {
                x++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        int flag=1;
        for(int j=0;j<n;j++)
        {
            if(flag==0)
            {
                cout<<' ';
            }
            cout<<num[i][j];
            flag=0;
        }
        cout<<endl;
    }
    return 0;
}