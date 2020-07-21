/*
*	Author: coder_tq
*	Time: 2020-03-01 21:15:00
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
ll sum[800010];
ll a[200010];
void solve()
{
	for(int i = 0; i < n; i++)
	{
		if(a[i]-i>=0) sum[a[i]-i]+=a[i];
		else sum[i-a[i]]+=a[i];
	}
	ll ans = 0;
	for(int i = 0; i < 800010; i++)
	{
		ans = max(ans,sum[i]);
	}
	cout << ans << endl;
}


void input()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
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
