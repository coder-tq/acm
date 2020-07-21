/*
*	Author: coder_tq
*	Time: 2020-03-19 22:35:03
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
int arr[200010];
int ans[200010];
set<ll> st;
void input()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		ans[i] = arr[i];
	}
}

void solve()
{
	int con = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] > 0) con++;
	}
	sort(arr,arr+n);
	ll sum = 0;
	for(int i = 0; i < min(con,k); i++)
	{
		st.insert(arr[n-i-1]);
		sum+=arr[n-i-1];
	}
	ll ans1 = 1;
	ll con1 = 1;
	int flag1 = 0;
	int flag2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(!st.count(ans[i])&&flag1)
		{
			con1++;
		}
		else if(!flag1&&st.count(ans[i]))
		{
			flag1 = 1;
		}
		else
		{
			ans1*=con1;
			ans1%=998244353;
			con1 = 1;
		}
	}
	cout << sum << ' ' << ans1 << endl; 
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
