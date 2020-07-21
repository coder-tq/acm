/*
*	Author: fairy_girl
*	Time: 2020-04-23 22:45:02
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
int n;
int a,b,c,d;
void input()
{
	cin >> n >> a >> b >> c >> d;
}

void solve()
{
	ll mi = (a-b)*n;
	ll mx = (a+b)*n;
	int flag = 1;
	if(mx < c-d||mi > c+d) flag = 0;
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
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
