/*
*	Author: coder_tq
*	Time: 2020-03-12 21:05:02
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
int n,h,l,r; 
int arr[2010];
ll dp[2010][2010];//第i次第j时间 
void input()
{
	cin >> n >> h >> l >> r;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
}

void solve()
{
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j < h; j++)
		{
			dp[i][j] = -0x3f3f3f3f;
		}
	}
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < h; j++)
		{
			j+=h;
			if(j%h<=r&&j%h>=l)
			{
				dp[i][j%h] = max(dp[i][j%h],max(dp[i-1][(j-arr[i])%h]+1,dp[i-1][(j-arr[i]+1)%h]+1));
			}
			else
			{
				dp[i][j%h] = max(dp[i][j%h],max(dp[i-1][(j-arr[i])%h],dp[i-1][(j-arr[i]+1)%h]));
			}
			j-=h;
		}
	}
	ll ans = -1;
	for(int i = 0; i < h; i++) ans = max(ans,dp[n][i]);
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 0; j < h; j++) cout << dp[i][j] << " "; cout << endl;
//	}
	cout << ans << endl;
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
