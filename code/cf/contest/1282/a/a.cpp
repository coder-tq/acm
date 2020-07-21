/*
*	Author: coder_tq
*	Time: 2020-02-15 11:48:30
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
int a,b,c,r;
void input()
{
	cin >> a >> b >> c >> r;
	if(a > b) swap(a,b);
}

void solve()
{
	int s = c-r;
	int e = c+r;
	int ans = max(s-a,0)+max(b-e,0);
	cout << min(ans,b-a) << endl;
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
