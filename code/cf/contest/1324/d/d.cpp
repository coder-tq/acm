/*
*	Author: coder_tq
*	Time: 2020-03-12 21:05:02
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
ll a[200010],b[200010];
ll dif[200010]; 
void input()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
}

void solve()
{
	for(int i = 0; i < n; i++)
	{
		dif[i] = a[i]-b[i];
	}
	sort(dif,dif+n);
	//for(int i = 0; i < n; i++) cout << dif[i] << ' ';cout << endl;
	ll sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(dif[i] <= 0)
		{
			//cout << n-(lower_bound(dif,dif+n,-dif[i]+1)-dif)-1 << endl;
			sum += n-(lower_bound(dif,dif+n,-dif[i]+1)-dif);
		}
		if(dif[i] > 0) sum+=n-i-1;
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
