/*
*	Author: coder_tq
*	Time: 2020-03-26 22:35:00
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
int a,b; 
void input()
{
	cin >> a >> b;
}

void solve()
{
	int ans = a/b;
	if(ans*b == a)
	{
		cout << 0 << endl;
		return;
	}
	ans+=1;
	cout << ans*b-a << endl;
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
