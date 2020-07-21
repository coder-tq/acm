/*
*	Author: coder_tq
*	Time: 2020-02-24 22:35:02
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
int arr[110],p[110]; 
void input()
{
	memset(arr,0,sizeof(arr));
	memset(p,0,sizeof(p));
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int t;
	for(int i = 0; i < m; i++)
	{
		cin >> t;
		p[t] = 1;
	}
}

void solve()
{
	int mi = -1;
	int mx = -1;
	for(int i = 1; i < n; i++)
	{
		if(p[i] == 1&&mi == -1)
		{
			mi = i;
		}
		if(p[i] == 1) mx = i;
		if(p[i] == 0)
		{
			if(mi == -1) continue;
			else{
				sort(arr+mi-1,arr+mx+1);
			}
			mi = -1,mx = -1;
		}
	}
	//sort(arr+0,arr+n);
	//cout << mi-1 << ' ' << mx+1 << endl;
	if(mi!=-1) sort(arr+mi-1,arr+mx+1);
	int flag = 1;
	for(int i = 0; i < n-1; i++)
	{
		if(arr[i] > arr[i+1]) flag = 0;
	}
	if(flag)
	{
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
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
