/*
*	Author: coder_tq
*	Time: 2020-02-17 23:35:02
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
int n,x;
int arr[100010];
void input()
{
	cin >> n >> x;
	for(int i = 0; i < n; i++)
	cin >> arr[i];
}

void solve()
{
	int dis = -1;
	int pos = 0;
	int ans = -1;
	for(int i = 0; i < n; i++)
	{
		dis = max(arr[i],dis);
		if(arr[i] == x)
		{
			cout << 1 << endl;
			return;
		}
	}
	if(dis <= x)
	{
		if(x%dis == 0) ans = x/dis; 
		else ans = x/dis+1;
	}
	else if(dis > x)
	{
		ans = 2;
	}
	cout << ans << endl;
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
