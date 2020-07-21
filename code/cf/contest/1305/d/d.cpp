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
int n;
set<int> st[1010];
set<int> root;
int vis[1010];

void kill(int k)
{
	st[k].clear();
	for(int i = 0; i < 1010; i++)
	{
		if(st[i].count(k))
		{
			st[i].erase(k);
			if(st[i].size() == 1) root.insert(i);
		}
	}
}

void input()
{
	cin >> n;
	int t1,t2;
	for(int i = 0; i < n-1; i++)
	{
		cin >> t1 >> t2;
		st[t1].insert(t2);
		st[t2].insert(t1);
	}
}

void solve()
{
	for(int i = 1; i <= n; i++)
	{
		if(st[i].size() == 1) root.insert(i);
	}
	while(root.size() >= 2)
	{
		int root1 = -1;
		int root2 = -1;
		for(int i:root)
		{
			if(vis[i]) continue;
			if(root1 == -1)
			{
				root1 = i;
				continue;
			}
			else if(root2 == -1)
			{
				root2 = i;
				continue;
			}
			else break;
		}
		int iroot;
		root.erase(root1);
		root.erase(root2);
		cout << "? " << root1 << " " << root2 << endl;
		cin >> iroot;
		if(iroot == root1||iroot == root2) 
		{
			cout << "! " << iroot << endl;
			return;
		}
		kill(root1);
		kill(root2); 
	}
	for(int i : root)
	{
		cout << "! " << i << endl;
		return;
	}
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

