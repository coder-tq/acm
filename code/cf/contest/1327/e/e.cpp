/*
*	Author: coder_tq
*	Time: 2020-03-23 22:35:01
*/ 
#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;
const ll mod = 998244353;
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
ll ans[100010];
void input()
{
	cin >> n;
}
void solve()
{
	ll s=1;
	for(int i = 1; i <= n; i++)
	{
		ans[i] = (9*i+1);
		//cout << ans[i] << endl;
	}
	for(int i = n; i >= 1; i--) cout << ((ans[i]*10-ans[i-1])*q_pow(10,i-1)/10+100*mod)%mod << ' ';
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
