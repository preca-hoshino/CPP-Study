#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int if_x=0;
    if(s=="0")
    {
        cout<<"0";
        return 0;
    }
    if(s[0]=='-')
    {
        if_x=1;
        s.erase(0,1);
    }
    reverse(s.begin(),s.end());
    while(s[0]=='0')
    {
        s.erase(0,1);
    }
    if(if_x==1)
    {
        s.insert(0,"-");
    }
    cout<<s;
    return 0;
}