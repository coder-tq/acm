/*
*	Author: coder_tq
*	Time: 2020-03-03 22:35:02
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
ll arr[200010]; 
void input()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void solve()
{
	sort(arr,arr+n);
	if(n > m)
	{
		cout << 0 << endl;
		return;
	}
	ll sum = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			sum *= abs(arr[i]-arr[j]);
			sum%=m;
		}
	}
	cout << sum << endl;
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
