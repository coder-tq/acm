/*
*	Author: coder_tq
*	Time: 2020-02-17 23:35:02
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
int spe[200010];
ll midis[200010];
int t1,t2;
int fa[200010];
int road[200010];
int flag[200010];
void input()
{
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++)
		cin >> spe[i];
	for(int i = 0; i < m; i++)
	{
		cin >> t1 >> t2;
		st[t1].insert(t2);
		st[t2].insert(t1);
	}
}

void fun(int k)
{
	if(k == 1) return;
	for(int i : st[k])
	{
		if(midis[i] > midis[k]+1)
		{
			fa[i] = k;
			midis[i] = min(midis[i],midis[k]+1);
			fun(i);
		}
	}
}

void fun1(int k,int pos)
{
	flag[k] = 1;
	road[pos] = k;
	if(k == n) return;
	fun1(fa[k],pos+1);
}

void solve()
{
	for(int i = 0; i < 200010; i++) fa[i] = i;
	for(int i = 0; i < 200010; i++)
	{
		midis[i] = 0x3f3f3f3f;
	}
	midis[n] = 1;
	fun(n);
	int pos = 0;
	fun1(1,0);
	for(int i = 0; i < k; i++)
	{
		//cout << 1 << endl;
		if(!flag[spe[i]])
		{
			cout << midis[1]-1 << endl;
			return;
		}
	}
	ll dist[k+10];
	for(int i = 0; i < k; i++)
	{
		dist[i] = midis[spe[i]];
	}
	sort(dist,dist+k);
	ll ans = 0x3f3f3f3f;
	for(int i = 0; i < k; i++)
	{
		int pos = lower_bound(dist,dist+k,midis[spe[i]])-dist;
		if(pos == 0)
		{
			ans = min(ans,abs(midis[spe[i]]-dist[pos+1]));
			continue;
		}
		if(pos == k-1)
		{
			ans = min(ans,abs(midis[spe[i]]-dist[pos-1]));
			continue;
		}
		ans = min(ans,abs(midis[spe[i]]-dist[pos-1]));
		ans = min(ans,abs(midis[spe[i]]-dist[pos+1]));
	}
	//cout << ans << endl;
	cout << midis[1]-ans << endl;
}

int main()
{
//	ios::sync_with_stdio(false); 
//	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
