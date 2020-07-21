/*
*	Author: coder_tq
*	Time: 2020-03-19 22:35:03
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
	if(n == 1) cout << "-1" << endl;
	else
	{
		for(int i = 0; i < n-1; i++)
		{
			if(i == 0) cout << 2;
			else cout << 3;
		}
		cout << 3;
		cout << endl;
	}
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
