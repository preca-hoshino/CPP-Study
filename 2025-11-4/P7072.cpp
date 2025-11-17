//2020 CSP-J 第二题 纪念留存

#include<bits/stdc++.h>
using namespace std;
int n,w;
int a[601];
int main()
{
//	freopen("live.in","r",stdin);
//	freopen("live.out","w",stdout);
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		a[t]++;
		int p=max(1,(int)(i*w/100.0));
		for(int j=600;j>=0;j--)
		{
			p-=a[j];
			if(p<=0)
			{
				cout<<j<<" ";
				break;
			}
			
		}
	}
	return 0;
}