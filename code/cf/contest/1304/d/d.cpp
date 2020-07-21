/*
*	Author: coder_tq
*	Time: 2020-02-15 21:05:02
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
string tem;
int ans[200010];
void input()
{
	cin >> n >> tem;
}
//7 6 2 5 4 1 3
//7 6 1 5 4 2 3
void solve()
{
	memset(ans,0,sizeof(ans));
	vector<int> mi;
	vector<int> mx;
	for(int i = 0; i < n-1; i++)
	{
		if(i == n-2)
		{
			if(tem[i] == '>') mi.push_back(i+1);
			
			if(tem[i] == '<') mx.push_back(i+1);
		}
		if(i == 0)
		{
			if(tem[i] == '<') mi.push_back(i);
			
			if(tem[i] == '>') mx.push_back(i);
		}
		if(tem[i-1] == '>'&&tem[i] == '<')
		{
			mi.push_back(i);
		}
		if(tem[i-1] == '<'&&tem[i] == '>')
		{
			mx.push_back(i);
		}
		
	}
	int nu = n;
	int cur = 1;
	int si;
	si = mx.size();
	for(int i = 0; i < si; i++)
	{
		ans[mx[i]] = nu--;
	}
	for(int i = 0; i < si; i++)
	{
		int t = mx[i];
		while(t > 0 && tem[t-1] == '<' && !ans[--t]) ans[t] = nu--;
	}
	for(int i = n-1; i >= 0; i--) if(!ans[i]) ans[i] = cur++;
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << endl;
	
	
	memset(ans,0,sizeof(ans));
	si = mi.size();
	nu = n;
	cur = 1;
	for(int i = n-2; i >= 0; i--)
	{
		if(tem[i] == '<') ans[i+1] = nu--;
	}
	for(int i = 0; i < si; i++)
	{
		ans[mi[i]] = cur++;
	}
	for(int i = 0; i < n-1; i++)
	{
		if(tem[i] == '>') 
		{
			if(ans[i] == 0) ans[i] = nu--;
		}
	}
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
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
