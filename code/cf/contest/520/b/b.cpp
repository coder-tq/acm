/*
*	Author: coder_tq
*	Time: 2020-02-06 17:44:43
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
ll dp[100010];
int vis[100010];

void dfs(int k)
{
	if(vis[k]) return;
	vis[k] = 1;
	//if(vis[k]) return 0x3f3f3f3f;
	//cout << k << ' ';
	if(k > 20000) return;
	if(k < 0) return;
	dp[k-1] = (dp[k-1]!=-1)?min(dp[k-1],dp[k]+1):dp[k]+1;
	dp[2*k] = (dp[2*k]!=-1)?min(dp[2*k],dp[k]+1):dp[k]+1;
	dfs(k-1);
	dfs(2*k);
}

void input()
{
	cin >> n >> m;
}

void solve()
{
	memset(dp,-1,sizeof(dp));
	dp[n] = 0;
	dfs(n);
	cout << dp[m] << endl;
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
