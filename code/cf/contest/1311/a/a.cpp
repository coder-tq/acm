/*
*	Author: coder_tq
*	Time: 2020-02-24 22:35:02
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
int a,b; 
void input()
{
	cin >> a >> b;
}

void solve()
{
	int dif = b-a;
//	cout << dif << endl;
	if(dif == 0)
	{
		cout << 0 << endl;
		return;
	}
	if(dif%2 == 1&&dif > 0)
	{
		cout << 1 << endl;
		return;
	}
	if(dif%2 == 0&&dif > 0)
	{
		cout << 2 << endl;
		return;
	}
	if(abs(dif)%2 == 1&&dif < 0)
	{
		cout << 2 << endl;
		return;
	}
	if(abs(dif)%2 == 0&&dif < 0)
	{
		cout << 1 << endl;
		return;
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
