/*
*	Author: coder_tq
*	Time: 2020-04-03 22:35:01
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
int n,x;
int vis[300];
void input()
{
	memset(vis,0,sizeof(vis));
	cin >> n >> x;
	int t;
	for(int i = 0; i < n; i++)
	{
		cin >> t;
		vis[t] = 1;
	}
}

void solve()
{
	int ans = -1;
	for(int i = 1; i <= 300; i++)
	{
		if(vis[i] == 0&&x>0){
			x--;
			vis[i] = 1;
			continue;
		}
		if(vis[i] == 0)
		{
			ans = i-1;
			break;
		}
	}
	cout << ans << endl;
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
