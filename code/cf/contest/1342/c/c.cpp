/*
*	Author: coder_tq
*	Time: 2020-04-26 22:35:02
*/ 
#include <bits/stdc++.h>
#define endl "\n"
#define inf 0x7fffffff-1
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
ll a,b,q;
void input()
{
	cin >> a >> b >> q;
}

void solve()
{
	ll l,r;
	for(ll kase = 0; kase < q; kase++)
	{
		cin >> l >> r;
		ll con = 0;
		con = r/(__gcd(a,b)*a*b)-l/(__gcd(a,b)*a*b);//完整区间数 
		if(r%(__gcd(a,b)*a*b) == 0&&l %(__gcd(a,b)*a*b) == 0) ;
		else con-=1;
		ll num = __gcd(a,b)*a*b-max(a,b);
		ll con1 = 0;
		ll con2 = 0;
		for(ll i = l; i <= r; i++)
		{
			if(i%(__gcd(a,b)*a*b) == 0) break;
			if(i%(__gcd(a,b)*a*b) >= max(a,b)) con1++;
		}
		for(ll i = r; i >= l; i--)
		{
			if(i%(__gcd(a,b)*a*b) >= max(a,b)) con2++;
			if(i%(__gcd(a,b)*a*b) == 0) break;
		}
		if(con < 0)
		{
			cout << con1 << ' ';
		}
		//
		else cout << con*num+con1+con2 << ' ';
		 
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
