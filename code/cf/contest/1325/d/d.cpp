/*
*	Author: coder_tq
*	Time: 2020-03-14 22:34:59
*/ 
#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;
const ll mod = 1e18+7;
ll q_pow(ll a, ll b)
{
    ll ans = 1;
    while(b) {
 
        if(b&1)
            ans = (ans*a);
        a = (a*a);
        b >>= 1;
    }
    return ans;
}
ll n,sum;
void input()
{
	cin >> n >> sum;
}

void solve()
{
	ll tem = n;
	ll cur = 0;
	ll con = 0;
	if(sum < n)
	{
		cout << "-1" << endl;
		return;
	}
	
	if(sum == tem)
	{
		if(tem == 0)
		{
			cout << 0 << endl;
			return;
		}
		cout << 1 << endl;
		cout << tem << endl;
	}
	else
	{
		if((sum-tem)%2!=0)
		{
			cout << "-1" << endl;
			return;
		}
		
		ll flag = tem^((sum-tem)/2);
		if(flag+(sum-tem)/2 == sum)
		{
			cout << 2 << endl;
			cout << tem+(sum-tem)/2 << ' ' << (sum-tem)/2 << endl;
		}
		else {
			cout << 3 << endl;
			cout << tem << ' ' << (sum-tem)/2 << ' ' << (sum-tem)/2 << endl;
		}
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
