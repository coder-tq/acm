/*
*	Author: coder_tq
*	Time: 2020-04-11 11:29:44
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
ll a[300010];
ll b[300010];
ll dif[300010];
void input()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
}

void solve()
{
	ll sum = 0;
	dif[0] = max(a[0]-b[n-1],0LL);
	for(int i = 1; i < n; i++) dif[i] = max(a[i]-b[i-1],0LL);
	int pos = -1;
	ll mx = -1;
	ll mi = 1e18;
	for(int i = 0; i < n; i++)
	{
		sum+=dif[i];
	}
	for(int i = 0; i < n; i++)
	{
		sum-=dif[i];
		sum+=a[i];
		mi = min(mi,sum);
		sum-=a[i];
		sum+=dif[i];
	}
	cout << mi << endl;
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
