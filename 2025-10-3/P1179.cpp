#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,r;
    cin>>l>>r;
    string tmp;
    int sum=0;
    for(int i=l;i<=r;i++)
    {
        tmp=to_string(i);
        sum+=count(tmp.begin(),tmp.end(),'2');
    }
    cout<<sum;
    return 0;
}