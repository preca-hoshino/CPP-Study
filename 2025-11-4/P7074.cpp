//2020 CSP-J 第三题 纪念留存
//修改：记忆化搜索+状态转移（from参数区分来向）
/*
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001][1001],book[1001][1001];
int ans,max_ans=-999999;
int dx[3]={-1,0,1},dy[3]={0,1,0};
void dfs(int x,int y,int ans)
{
	if(x==n&&y==m)
	{
		if(ans>max_ans)
		{
			max_ans=ans;
		}
	}
	for(int i=0;i<3;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx<=n&&tx>=1&&ty<=m&&ty>=1&&book[tx][ty]==0)
		{
			book[tx][ty]=1;
			dfs(tx,ty,ans+a[tx][ty]);
			book[tx][ty]=0;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	book[1][1]=1;
	dfs(1,1,a[1][1]);
	cout<<max_ans;
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
const long long min_ll = -1e18;
int n = 0, m = 0;
long long a[1001][1001], f[1001][1001][2];

inline long long mx(long long p, long long q, long long r)
{
	return p > q ? (p > r ? p : r) : (q > r ? q : r);
}

long long dfs(int x, int y, int from)
{
	if(x < 1 || x > n || y < 1 || y > m)
	{
		return min_ll;
	}
	if(f[x][y][from] != min_ll)
	{
		return f[x][y][from];
	}
	if(from == 0)
	{
		f[x][y][from] = mx(dfs(x + 1, y, 0), dfs(x, y - 1, 0), dfs(x, y - 1, 1)) + a[x][y];
	}
	else
	{
		f[x][y][from] = mx(dfs(x - 1, y, 1), dfs(x, y - 1, 0), dfs(x, y - 1, 1)) + a[x][y];
	}
	return f[x][y][from];
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			f[i][j][0] = f[i][j][1] = min_ll;
		}
	}
	f[1][1][0] = f[1][1][1] = a[1][1];
	cout << dfs(n, m, 1);
	return 0;
}