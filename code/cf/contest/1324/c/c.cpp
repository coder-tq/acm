/*
*	Author: coder_tq
*	Time: 2020-03-12 21:05:02
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
string arr;
int ans[200010];
int len;
int vis[200010];
void input()
{
	arr.clear();
	cin >> arr;
}

void solve()
{
	len = arr.length();
	int pos = -1;
	int mx = -1;
	for(int i = 0; i < len; i++)
	{
		if(arr[i] == 'R')
		{
			mx = max(mx,i-pos);
			pos = i;
		}
	}
	mx = max(mx,len-pos);
	cout << mx << endl;
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
