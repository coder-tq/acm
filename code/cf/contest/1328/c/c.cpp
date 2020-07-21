/*
*	Author: coder_tq
*	Time: 2020-03-26 22:35:00
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
string t;
void input()
{
	cin >> n >> t;
}

void solve()
{
	string ans1,ans2;
	int flag = 0;
	for(int i = 0; i < n; i++)
	{
		if(t[i] == '0') ans1+='0',ans2+='0';
		if(t[i] == '2'&&!flag) ans1+='1',ans2+='1';
		if(t[i] == '2'&&flag) ans1+='0',ans2+='2';
		if(t[i] == '1')
		{
			if(!flag)
			{
				flag = 1;
				ans1+='1';
				ans2+='0';
			}
			else
			{
				ans1+='0';
				ans2+='1';
			}
		}
	}
	cout << ans1 << endl << ans2 << endl;
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
