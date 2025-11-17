#include<bits/stdc++.h>
using namespace std;
long long a,b,p,ans=1;
long long p_pow(long long base,long long power)
{
    if(power==1)
    {
        return base%p;
    }
    if(power%2==0)
    {
        return p_pow((base%p)*(base%p),power/2)%p;
    }
    if(power%2==1)
    {
        return (p_pow((base%p)*(base%p),power/2)*(base%p))%p;
    }
}
int main()
{
    cin>>a>>b>>p;
    // for(long long i=1;i<=b;i++)
    // {
    //     ans*=(a%p);
    //     ans%=p;
    // }
    
    cout<<a<<'^'<<b<<" mod "<<p<<"="<<p_pow(a,b);
    return 0;
}