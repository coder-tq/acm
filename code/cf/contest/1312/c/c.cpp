/*
*	Author: coder_tq
*	Time: 2020-03-09 22:35:02
*/ 
#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;
const ll mod = 1e17+7;
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
ll n,k;
ll arr[40];
ll pow1[40];
set<ll> ans;
void input()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void solve()
{
	ans.clear();
	int con = 0;
	sort(arr,arr+n);
	int flag = 1;
	for(int i = 0; i < n; i++)
	{
		con = 0;
		while(arr[i]!=0)
		{
			if(arr[i]%k == 0)
			{
				arr[i]/=k;
				con++;
			}
			else {
				if(ans.count(con)!=0) flag = 0;
				ans.insert(con);
				arr[i]--;
			}
		}
	}
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
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
