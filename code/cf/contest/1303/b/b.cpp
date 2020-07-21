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
ll n,g,b; 
void input()
{
	cin >> n >> g >> b;
}

void solve()
{
	ll go;
	if(n%2==0) go=n/2;
	else go=n/2+1;
	ll ba = n-go;
	ll sum = 0;
	sum = (go/g-1)*(b+g)+(go%g?:g);
	sum = max(sum,n);
	cout << sum << endl;
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
