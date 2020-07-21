/*
*	Author: coder_tq
*	Time: 2020-04-12 22:05:01
*/ 
#include <bits/stdc++.h>
#define endl "\n"
#define inf 0x7fffffff
#define llinf 9223372036854775807LL

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
int arr[100010];
int dif[100010];
int vis[100010];
void input()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		vis[i] = 0;
		cin >> arr[i];
	}
}

void solve()
{
	int pos = (n%2 == 0)? n/2:n/2+1;
//	cout << pos << endl;
	sort(arr+1,arr+n+1);
//	for(int i = 1; i <= n; i++) cout << arr[i] << endl;
	cout << arr[pos] << ' ';
	vis[pos] = 1;
	int f = pos-1;
	int e = n-pos;
	if(e >= f)
		for(int i = 1; i <= n/2; i++)
		{
			if(pos+i <= n)
				cout << arr[pos+i] << ' ',vis[pos+i] = 1;
			if(pos-i > 0)
				cout << arr[pos-i] << ' ',vis[pos-i] = 1;
		}
	if(e < f)
	{
		for(int i = 1; i <= n/2; i++)
		{
			if(pos-i > 0)
				cout << arr[pos-i] << ' ',vis[pos-i] = 1;
			if(pos+i <= n)
				cout << arr[pos+i] << ' ',vis[pos+i] = 1;
		}	
	}
	for(int i = 1; i <= n; i++)
	{
		if(vis[i] == 0) cout << arr[i] << ' ';
	}
	cout << endl;
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
