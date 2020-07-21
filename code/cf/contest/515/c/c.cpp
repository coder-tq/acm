/*
*	Author: coder_tq
*	Time: 2020-02-06 19:44:32
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
int j[11];
int con[10];

void input()
{
	cin >> n >> t;
}

void solve()
{
	for(int i = 0; i < n; i++)
	{
		if(t[i] == '6') con[5]++,con[3]++;
		else if(t[i] == '4') con[3]++,con[2]+=2;
		else if(t[i] == '8') con[7]++,con[2]+=3;
		else if(t[i] == '9') con[7]++,con[3]+=2,con[2]++;
		else con[t[i]-'0']++;
	}
	for(int i = 9; i > 1; i--)
	{
		while(con[i])
		{
			cout << i;
			con[i]--;
		}
	}
}

int main()
{
	int t = 1;
	//cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
