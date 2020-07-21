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
int n,m;
string arr[1000];
int vis[1000];
int ans[1000];
void input()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void solve()
{
	memset(ans,0,sizeof(ans));
	int flag = 1;
	int zhw[1000];
	memset(zhw,0,sizeof(zhw));
	for(int i = 0; i < n; i++)
	{
		flag = 1;
		for(int j = 0; j < m/2; j++)
		{
			if(arr[i][j]!=arr[i][m-1-j]) flag = 0;
		}
		if(flag) zhw[i] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if(vis[i]||vis[j]) continue;
			flag = 1;
			for(int z = 0; z < m; z++)
			{
				if(arr[i][z] != arr[j][m-1-z]) flag = 0;
			}
			if(flag) ans[i] = j,vis[i] = 1,vis[j] = 1;
		}
	}
	int con = 0;
	for(int i = 0; i < n; i++)
	{
		if(ans[i] == 0) continue;
		else con++;
	}
	for(int i = 0; i < n; i++)
	{
		if(ans[i] == 0&&zhw[i] == 1)
		{
			con++;
			break;
		}
	}
	for(int i = n-1; i >=0; i--)
	{
		if(ans[i] == 0) continue;
		else con++;
	}
	
	cout << con*m << endl;
	for(int i = 0; i < n; i++)
	{
		if(ans[i] == 0) continue;
		else cout << arr[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(ans[i] == 0&&zhw[i] == 1)
		{
			cout << arr[i];
			break;
		}
	}
	for(int i = n-1; i >=0; i--)
	{
		if(ans[i] == 0) continue;
		else cout << arr[ ans[i] ];
	}
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
