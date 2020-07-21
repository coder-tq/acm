/*
*	Author: coder_tq
*	Time: 2020-03-03 22:35:02
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
int a[110],b[110]; 
void input()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
}

void solve()
{
	sort(a,a+n);
	sort(b,b+n);
	for(int i = 0; i < n; i++) cout << a[i] << ' ';
	cout << endl;
	for(int i = 0; i < n; i++) cout << b[i] << ' ';
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
