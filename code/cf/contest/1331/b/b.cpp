/*
*	Author: coder_tq
*	Time: 2020-04-01 22:35:18
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
int n; 
void input()
{
	cin >> n;
}

void solve()
{
	for(int i = 2; i < n; i++)
	{
		if(n%i == 0)
		{
			cout << i << n/i << endl;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
