/*
*	Author: coder_tq
*	Time: 2020-02-13 22:34:59
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
ll n,m;
void input()
{
	cin >> n >> m;
}

void solve()
{
	ll ans = 0;
	if(m == 0)
	{
		cout << 0 << endl;
		return;
	}
	if(n%2 == 0)
	{
		ans = (n/2-m/2)*(n/2+m/2);
		ans += 1.0*(n/2+m/2+n/2-(m-m/2)+1)/2*m;
	}
	else 
	{
		if(m%2) 
		{
			ans = ((n-1)/2-(m-1)/2)*((n-1/2)+(m-1)/2);
			ans += 1.0*((n-1)/2+1+(m-1)/2+(n-1)/2-(m-1)/2+1)/2*m;
		}
		else
		{
			ans = ((n-1)/2-(m-1)/2-1)*((n-1/2)+(m-1)/2+1);
			ans += 1.0*((n-1)/2+1+(m-1)/2+1+(n-1)/2-(m-1)/2+1)/2*m;
		}
	}
	cout << ans << endl;
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
