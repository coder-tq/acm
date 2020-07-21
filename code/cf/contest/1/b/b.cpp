/*
*	Author: coder_tq
*	Time: 2020-02-09 15:34:11
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
	int x = 0,y = 0;
	int len = t.length();
	int mode = 0;
	int flag = 0;
	for(int i = 0; i < len; i++)
	{
		if(!flag&&t[i] >= '0'&&t[i] <= '9') 
		{
			flag = 1;
			mode++;
			//cout << t[i] << endl;
		}
		if(t[i]<'0'||t[i]>'9') flag = 0;
	}
	//cout << mode << endl;
	if(mode == 1)
	{
		for(int i = 0; i < len; i++)
			if(t[i] >= 'A'&&t[i] <= 'Z') x = x*26+t[i]-'A'+1;
		for(int i = 0; i < len; i++)
			if(t[i] >= '0'&&t[i] <= '9') y = y*10+t[i]-'0';
		cout << "R" << y << "C" << x << endl;
	}
	else
	{
		int i = 1;
		for(; i < len; i++)
			if(t[i] >= '0'&&t[i] <= '9') x = x*10+t[i]-'0'; else break;
		for(; i < len; i++)
			if(t[i] >= '0'&&t[i] <= '9') y = y*10+t[i]-'0';
		string tem,ans;
		while(y>26)
		{
			if(y%26)
				tem += y%26+'A'-1;
			else tem+='Z',y--;
			y /= 26;
		}
		tem += y+'A'-1;
		for(int j = tem.length()-1; j >= 0; j--) ans+=tem[j];
		cout << ans << x << endl;
	}
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
