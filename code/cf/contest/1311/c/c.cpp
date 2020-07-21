/*
*	Author: coder_tq
*	Time: 2020-02-24 22:35:02
*/ 
#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll q_pow(ll a, ll b)
{
    ll ans = 1;
    while(b) {
 
        if(b&1)
            ans = (ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans;
}
int n,m;
string tem;
int p[200010];
int ans[200010][30];
int sum[30];
void input()
{
	cin >> n >> m >> tem;
	for(int i = 0; i < m; i++)
	{
		cin >> p[i];
	}
	memset(sum,0,sizeof(sum));
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j < 30; j++)
		{
			ans[i][j] = 0;
		}
	}
}

void solve()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 30; j++)
		{
			ans[i][j] = ans[i-1][j];
			if(tem[i-1]-'a'==j) ans[i][j]++;
			//cout << i << ' ' << j << ' ' << ans[i][j] << ' ' << tem[i-1] << endl;
		}
	}
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < 30; j++)
		{
			sum[j]+=ans[p[i]][j];
		}
	}
	for(int j = 0; j < 30; j++)
	{
		sum[j]+=ans[n][j];
	}
	for(int i = 0; i < 26; i++)
	{
		cout << sum[i] << ' ';
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
