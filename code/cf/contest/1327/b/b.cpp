/*
*	Author: coder_tq
*	Time: 2020-03-23 22:35:01
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
set<int> arr[100010];
int vis[100010];
void input()
{
	memset(vis,0,sizeof(vis));
	cin >> n;
	for(int i = 0; i < n; i++) arr[i].clear();
	int t;
	int t1;
	for(int i = 0; i < n; i++)
	{
		cin >> t;
		for(int j = 0; j < t; j++)
		{
			cin >> t1;
			arr[i].insert(t1);	
		}
	}
}

void solve()
{
	int pos = -1;
	for(int i = 0; i < n; i++)
	{
		int flag = 0;
		for(int j:arr[i])
		{
			if(vis[j-1] == 0)
			{
				vis[j-1] = 1;
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			pos = i+1;
		}
	}
	if(pos == -1)
		cout << "OPTIMAL" << endl;
	else
	{
		cout << "IMPROVE" << endl;
		for(int i = 0; i < n; i++)
		{
			if(vis[i] == 0) 
			{
				cout << pos << ' ' << i+1 << endl;
				return;
			}
		}
	}
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
