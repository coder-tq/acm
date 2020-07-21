/*
*	Author: coder_tq
*	Time: 2020-03-14 22:34:59
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

struct node
{
    int u, v, id, ret, ans;
} tree[100005];

bool cmp(node a, node b)
{
    return a.ret < b.ret;
}

bool cmp1(node a, node b)
{
    return a.id < b.id;
}

int vis[100005];


int n;
int u, v;
void input()
{
    cin >> n;
    
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        tree[i].u = u;
        tree[i].v = v;
        tree[i].id = i;
        vis[u]++;
        vis[v]++;
    }
}

void solve()
{
	for (int i = 1; i < n; i++)
        tree[i].ret = min(vis[tree[i].u], vis[tree[i].v]);
    sort(tree + 1, tree + n, cmp);
    for (int i = 1; i < n; i++)
        tree[i].ans = i;
    sort(tree + 1, tree + n, cmp1);
    for (int i = 1; i < n; i++)
        cout<<tree[i].ans-1<<endl;
    return;
	
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
