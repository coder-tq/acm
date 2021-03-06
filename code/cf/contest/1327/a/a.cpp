/*
*	Author: coder_tq
*	Time: 2020-03-23 22:35:01
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
ll n,k;
void input()
{
	cin >> n >> k;
}

void solve()
{
	if(n%2 != k%2)
	{
		cout << "NO" << endl;
		return;
	}
	if(pow(k,2)>n)
	{
		cout << "NO" << endl;
		return;
	}
	else cout << "YES" << endl;
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
