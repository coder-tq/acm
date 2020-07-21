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

void solve()
{
	int ans = 0;
	int sum = 0;
	int flag = 0;
	for(char i : t)
	{
		if(i == '1'&&flag==0)
		{
			flag = 1;
			continue;
		}
		if(flag&&i=='0') sum++;
		if(flag&&i=='1') ans+=sum,sum = 0;
	}
	//ans+=sum;
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
