/*
*	Author: coder_tq
*	Time: 2020-02-12 22:35:01
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
void input()
{
	cin >> t;	
}

string ans;
set<int> vec[30];
int vis[30];

void se(char k)
{
	if(vis[k]) return;
	vis[k] = 1;
	ans+=k+'a';
	for(char j:vec[k])
	{
		se(j);
	}
}

void solve()
{
	memset(vis,0,sizeof(vis));
	ans.clear();
	for(int i = 0; i < 30; i++) vec[i].clear();
	int len = t.length();
	for(int i = 0; i < len; i++)
	{
		if(i == 0) {
			vec[t[i]-'a'].insert(t[i+1]-'a');
			vec[t[i+1]-'a'].insert(t[i]-'a');
			continue;
		}
		if(i == len-1)
		{
			vec[t[i]-'a'].insert(t[i-1]-'a');
			vec[t[i-1]-'a'].insert(t[i]-'a');
			continue;
		}
		vec[t[i]-'a'].insert(t[i+1]-'a');
		vec[t[i]-'a'].insert(t[i-1]-'a');
		vec[t[i+1]-'a'].insert(t[i]-'a');
		vec[t[i-1]-'a'].insert(t[i]-'a');
	}
	for(int i = 0; i < 26; i++) 
		if(vec[i].size()>2)
		{
			cout << "NO" << endl;
			return;
		}
	for(int i = 0; i < 26; i++)
	{
		if(vec[i].size() == 0) ans+=i+'a',vis[i] = 1;
	}
	for(int i = 0; i < 26; i++)
	{
		if(vec[i].size() == 1)
		{
			ans+=i+'a';
			vis[i] = 1;
			for(char j:vec[i]) se(j);
			break;
		}
	}
	for(int i = 0; i < 26; i++)
	{
		if(vis[i] == 0) cout << (char)i+'a' << endl;
		return;
	}
	cout << "YES" << endl;
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
