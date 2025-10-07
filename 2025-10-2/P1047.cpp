#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,m;
    cin>>l>>m;
    string s(l+1,'0');
    for(int i=0;i<m;i++)
    {
        int left,right;
        cin>>left>>right;
        replace(s.begin()+left,s.begin()+right+1,'0','1');
    }
    int num=count(s.begin(),s.end(),'0');
    cout<<num;
    return 0;
}