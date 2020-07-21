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
int x,y,a,b; 
void input()
{
	cin >> x >> y >> a >> b;
}

void solve()
{
	if((y-x)%(a+b)) cout << -1 << endl;
	else cout << (y-x)/(a+b) << endl;
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
