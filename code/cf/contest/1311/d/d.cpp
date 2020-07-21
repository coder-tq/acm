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
ll a,b,c; 
void input()
{
	cin >> a >> b >> c;
}

void solve()
{
	ll mi = 0x3f3f3f3f;
	ll ansa,ansb,ansc;
	ll sum;
	for(int i = 1; i <= 10000; i++)
	{
		for(int j = i; j <= 10000; j+=i)
		{
			for(int z = j; z <= 10000; z+=j)
			{
				sum = abs(a-i)+abs(b-j)+abs(c-z);
				if(sum < mi)
				{
					mi = sum;
					ansa = i;
					ansb = j;
					ansc = z;
				}
			}
		}
	}
	cout << mi << endl;
	cout << ansa << ' ' << ansb << ' ' << ansc << endl;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
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
