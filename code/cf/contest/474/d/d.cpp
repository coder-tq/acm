/*
*	Author: coder_tq
*	Time: 2020-02-09 16:04:52
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
int k;
int a,b;
ll dp[100010];

void init()
{
	dp[0] = 1;
	for(int i = 1; i <= 100000; i++)
	{
		dp[i] = dp[i-1]+((i>=k)?dp[i-k]:0);
		dp[i]%=mod;
		//cout << i << ' ' << dp[i] << endl;
	}
	for(int i = 1; i <= 100000; i++)
	{
		dp[i] += dp[i-1];
		dp[i]%=mod;
		//cout << i << ' ' << dp[i] << endl;
	}
}

void input()
{
	cin >> a >> b;
}

void solve()
{
	cout << (dp[b]-dp[a-1]+mod)%mod << endl;
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(0);
	int t = 1;
	cin >> t >> k;
	init();
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
