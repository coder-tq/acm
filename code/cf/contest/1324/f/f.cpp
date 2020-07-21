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
int n;
int arr[200010];
set<int> tree[200010];
ll dp[200010];
int t1,t2;
void input()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < n-1; i++) 
	{
		cin >> t1 >> t2;
		tree[t1].insert(t2);
//		tree[t2].insert(t1);
	}
}

int fun(int k)
{
	if(dp[k]!=-0x3f3f3f3f) return dp[k];
	ll sum = 0;
	for(int i : tree[k])
	{
		sum+=fun(i);
	}
	dp[k] = sum+arr[k]==0?-1:1;
	return dp[k];
}

void solve()
{
	for(int i = 0; i <= n; i++) dp[i] = -0x3f3f3f3f;
	for(int i = 1; i <= n; i++)
	{
		if(tree[i].size() == 1) 
		{
			dp[i] = arr[i]==0?-1:1;
			tree[i].clear();
		}
	}
	for(int i = 1; i <= n; i++) cout << fun(i) << ' ';
//	for(int i = 1; i <= n; i++) cout << dp[i] << ' ';
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
