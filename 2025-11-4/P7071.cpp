//2020 CSP-J 第一题 纪念留存

#include<bits/stdc++.h>
using namespace std;
int n;
int pows(int x)
{
	int t=1;
	for(int i=1;i<=x;i++)
	{
		t<<=1;
	}
	return t;
}
int main()
{
	cin>>n;
	if(n%2==1)
	{
		cout<<-1;
		return 0;
	}
	while(1)
	{
		if(n==0)
		{
			return 0;
		}
		int t=1;
		while(1)
		{
			t++;
			if(pows(t)>n)
			{
				n-=pows(t-1);
				break;
			}
		}
		cout<<pows(t-1)<<' ';
	}
}