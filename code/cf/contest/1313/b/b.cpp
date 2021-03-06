/*
*	Author: coder_tq
*	Time: 2020-02-23 17:05:00
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
int n,x,y; 
void input()
{
	cin >> n >> x >> y;
}

void solve()
{
	cout << min(max(x+y+1-n,1),n) << ' ' << min(n,x+y-1) << endl;
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
