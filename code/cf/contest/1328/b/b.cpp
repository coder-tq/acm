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
int n,k; 
void input()
{
	cin >> n >> k;
}

void solve()
{
	ll sum = 0;
	int pos1 = 1;
	for(int i = 1; i < n; i++)
	{
		sum+=i;
		if(sum >= k) 
		{
			sum-=i;
			break;
		}
		pos1 = i+1;
	}
	int pos2 = k-sum-1;
	//cout << pos1 << ' ' << pos2 << endl;
	for(int i = n-1; i >= 0; i--)
	{
		if(i == pos1||i == pos2) cout << 'b';
		else cout << 'a';
	}
	cout << endl;
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
