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
string a,b,c; 
void input()
{
	cin >> a >> b >> c;
}

void solve()
{
	int ans = 1;
	for(int i = 0; i < a.length(); i++)
	{
		if(b[i] == c[i]||a[i] == c[i]) continue;
		ans = 0;
	}
	if(ans) cout << "YES" << endl;
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
