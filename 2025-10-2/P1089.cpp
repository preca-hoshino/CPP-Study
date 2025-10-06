#include<bits/stdc++.h>
using namespace std;
int num[20];
int main()
{
    for(int i=1;i<=12;i++)
    {
        cin>>num[i];
    }
    int money_now=0;
    int money_mom=0;
    int dead_month=-1;
    for(int i=1;i<=12;i++)
    {
        money_now+=300;
        if(money_now-num[i]>=100)
        {
            money_mom+=(int)((money_now-num[i])/100)*100;
            money_now-=(int)((money_now-num[i])/100)*100;
        }
        if(money_now-num[i]<0)
        {
            dead_month=i;
            break;
        }
        money_now-=num[i];
    }
    money_now+=money_mom*1.2;
    if(dead_month!=-1)
    {
        cout<<'-'<<dead_month<<endl;
    }
    else
    {
        cout<<money_now<<endl;
    }
    return 0;
}