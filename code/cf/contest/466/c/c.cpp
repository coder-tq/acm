/*
*	Author: coder_tq
*	Time: 2020-02-08 12:05:13
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
ll arr[500010];
ll pix[500010];
void input()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void solve()
{
	ll sum = 0;
	pix[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		pix[i] = pix[i-1]+arr[i-1];
		sum+=arr[i-1];
	}
	ll ans = 0;
	if(sum%3 == 0)
	{
		ll ans1 = 0,ans2 = 0;
		for(int i = 1; i < n; i++)
		{
			if(pix[i] == sum/3) ans1++;
			if(pix[i] == sum/3*2) ans+=ans1;
		}
		if(sum == 0) ans = ans1*(ans1-1)/2;
	}
	cout << ans << endl;
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
