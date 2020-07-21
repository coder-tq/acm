/*
*	Author: coder_tq
*	Time: 2020-02-15 11:48:30
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
int n,p,k;
int arr[200010];
void input()
{
	cin >> n >> p >> k;
	for(int i = 0; i < n; i++) cin >> arr[i];
}

void solve()
{
	ll sum = 0;
	sort(arr,arr+n);
	int pos;
	for(pos = n-1; pos >= 0; pos-=k)
	{
		if(pos < k-1) break;
		sum+=arr[pos];
	}
	while(pos--)
	{
		sum+=arr[pos];
	}
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
