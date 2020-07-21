/*
*	Author: coder_tq
*	Time: 2020-02-06 17:25:15
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
ll n,s; 
void input()
{
	cin >> n >> s;
}

void solve()
{
	if(s > n*9||(s == 0&&n > 1))
	{
		cout << -1 << ' ' << -1 << endl;
		return;
	}
	if(s == n*9)
	{
		for(int i = 0; i < n; i++)
		{
			cout << 9;
		}
		cout << ' ';
		for(int i = 0; i < n; i++)
		{
			cout << 9;
		}
		return;
	}
	if(s >= (n-1)*9&&s < n*9)
	{
		int con = s/9;
		cout << s-con*9;
		for(int i = 0; i < con; i++) cout << 9;
		cout << ' ';
		con = s/9;
		for(int i = 0; i < con; i++) cout << 9;
		cout << s-con*9;
		return;
	}
	if(s < (n-1)*9)
	{
		int t = s;
		int con = (s-1)/9;
		cout << 1;
		for(int i = 0; i < n-con-2; i++) cout << 0;
		cout << (s-1)-con*9;
		for(int i = 0; i < con; i++) cout << 9;
		cout << ' ';
		con = s/9;
		for(int i = 0; i < con; i++) cout << 9;
		cout << s-con*9;
		for(int i = 0; i < n-1-con; i++) cout << 0;
		return;
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
