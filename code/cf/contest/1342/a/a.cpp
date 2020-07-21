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
ll x,y,a,b; 
void input()
{
	cin >> x >> y >> a >> b;
}

void solve()
{
	ll dif = abs(x-y);
	ll sum = 0;
		sum=min(a*dif+min(x,y)*b,a*dif+2*min(x,y)*a);
	cout << sum << endl;
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
