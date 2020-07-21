/*
*	Author: fairy_girl
*	Time: 2020-04-15 22:35:00
*/ 
#include <bits/stdc++.h>
#define endl "\n"
#define inf 0x7fffffff
#define llinf 9223372036854775807LL

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
ll a,b,c,d; 
void input()
{
	cin >> a >> b >> c >> d;
}

void solve()
{
	ll x = b;
	ll y = c;
	ll z = c;
	cout << x << ' ' << y << ' ' << z << endl;
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