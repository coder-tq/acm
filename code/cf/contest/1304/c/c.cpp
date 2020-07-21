/*
*	Author: coder_tq
*	Time: 2020-02-15 21:05:02
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
int n,m;
int t[1000],l[1000],h[1000]; 
void input()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> t[i] >> l[i] >> h[i];
	}
}

void solve()
{
	int flag = 1;
	int cur = 0;
	int mi = m;
	int mx = m;
	for(int i = 0; i < n; i++)
	{
		mi-=t[i]-cur;
		mx+=t[i]-cur;
		if(mx < l[i]||mi > h[i]) flag = 0;
		if(mi < l[i]) mi = l[i];
		if(mx > h[i]) mx = h[i];
		cur = t[i];
	}
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
