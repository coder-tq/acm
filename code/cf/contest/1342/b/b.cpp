/*
*	Author: coder_tq
*	Time: 2020-04-26 22:35:02
*/ 
#include <bits/stdc++.h>
#define endl "\n"
#define inf 0x7fffffff-1
#define llinf 9223372036854775807LL

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
	int flag1 = 0;
	int flag0 = 0;
	int con1 = 0;
	int con0 = 0;
	for(int i = 0; i < t.length(); i++)
	{
		if(t[i] == '1') flag1 = 1,con1++;
		if(t[i] == '0') flag0 = 1,con0++;
	}
	if(flag1 == 0 || flag0 == 0)
	{
		for(int i = 0; i < t.length(); i++)
		{
			if(flag1) cout << 1;
			else cout << 0;
		}
		cout << endl;
		return;
	}
	int la = t[0]-'0';
	int pos = 0;
	while(pos < t.length())
	{
		//if(con1 == 0&&con0 == 0) break;
		cout << la;
		if(la == t[pos]-'0') pos++;
		la=!la;
	}
	cout << endl;
	return;
}

int main()
{
//	ios::sync_with_stdio(false); 
//	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
