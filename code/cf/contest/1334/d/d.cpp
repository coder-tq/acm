/*
*	Author: coder_tq
*	Time: 2020-04-11 11:29:44
*/ 
#include <bits/stdc++.h>
//#define endl "\n"

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
ll n,l,r; 
void input()
{
	cin >> n >> l >> r;
}

void solve()
{
	ll pos = 1;
	ll curpos = 2;
	ll cur;
	ll sum = 0;
	for(ll i = 0; i < n; i++)
	{
		sum+=(n-i)*2;
		cout << sum << endl;
		if(sum < l) continue;
		else 
		{
			pos = i+1;
			curpos = (l - ( (n*2)+((n-i+1)*2) )/2*i)/2 + pos;
			if((l - ( (n*2)+((n-i+1)*2) )/2*i) % 2 == 1) curpos++;
			break;
		}
	}
	cout << pos << endl;
	cout << curpos << endl;
	for(ll i = l; i <= r; i++)
	{
		if(i%2==1)
		{
			cur = pos;
		}
		else
		{
			cur = curpos++;
			if(curpos > n)
			{
				pos++;
				curpos = pos+1;
			}
		}
		if(i == n*(n-1)+1)
		{
			cout << 1;
			break;
		}
		if(i >= l && i <= r) cout << cur << ' ';
	}
	cout << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
