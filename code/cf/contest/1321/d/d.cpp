/*
*	Author: coder_tq
*	Time: 2020-03-01 21:15:00
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
int n,m,k;
set<int> st[200010];
int road[200010];
int dep[200010];
const int inf = 1e9;

void init()
{
	for(int i = 0; i < 200010; i++)
	{
		dep[i] = inf;
	}
}

void input()
{
	cin >> n >> m;
	int t1,t2;
	for(int i = 0; i < m; i++)
	{
		cin >> t1 >> t2;
		st[t2].insert(t1);
	}
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		cin >> road[i];
	}
}

void dist(int pos)
{
	if(pos == 1) return;
	for(int i : st[pos])
	{
		if(dep[i] > dep[pos]+1)
		{
			dep[i] = min(dep[i],dep[pos]+1);
			dist(i);
		}
	}
}

void solve()
{
	dep[k] = 0;
	dist(k);
	int ans1,ans2;
	ans1 = ans2 = 0;
	for(int i = 1; i <= n; i++) cout << dep[i] << ' ';
	cout << endl;
	for(int i = 0; i < k; i++)
	{
		if(i == 0)
		{
			int mi = inf;
			int con = 0;
			for(int j:st[road[i]])
			{
				if(dep[j] == mi) con++;
				if(mi > dep[j])
				{
					mi = dep[j];
					con = 1;
				}
			}
			if(con >= 2) ans2++;
			if(con == 1&&mi > dep[i]) ans1++,ans2++;
		}
	}
	cout << ans1 << ' ' << ans2 << endl;
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--)
	{
		init();
		input();
		solve();
	}
	return 0;
}
