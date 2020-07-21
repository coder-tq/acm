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
string t; 
ll con[30];
ll ans[30][30];
void input()
{
	cin >> t;
}

void solve()
{
	int len = t.length();
	for(int i = 0; i < len; i++)
	{
		con[t[i]-'a']++;
	}
	ll mx = 0;
	for(int i = 0; i < 30; i++)
	{
		mx = max(con[i],mx);
	}
	for(int i = 0; i < len; i++)
	{
		con[t[i]-'a']--;
		for(int j = 0; j < 26; j++)
		{
			ans[t[i]-'a'][j]+=con[j];
		}
	}
	for(int i = 0; i < 30; i++)
	{
		for(int j = 0; j < 30; j++)
		{
			mx = max(ans[i][j],mx);
		}
	}
	cout << mx << endl;
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
