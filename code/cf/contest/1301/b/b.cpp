/*
*	Author: coder_tq
*	Time: 2020-02-13 22:34:59
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
ll arr[100010]; 
void input()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
}

void solve()
{
	ll mi = 0x3f3f3f3f;
	ll mx = -1;
	for(int i = 0; i < n; i++)
	{
		if(arr[i]==-1)
		{
			if(i-1>=0&&arr[i-1]!=-1)
			{
				mi = min(mi,arr[i-1]);
				mx = max(mx,arr[i-1]);
			}
			if(i+1<n&&arr[i+1]!=-1)
			{
				mi = min(mi,arr[i+1]);
				mx = max(mx,arr[i+1]);
			}
		}
	}
	if(mx == -1)
	{
		cout << "0 0" << endl;
		return;
	}
	ll ans = (mi+mx)/2;
	ll cha = -1;
	for(int j = 1; j < n; j++)
	{
		if(arr[j] == -1&&arr[j-1] == -1) continue;
		else if(arr[j] == -1)
		{
			cha = max(cha,abs(arr[j-1]-ans));
		}
		else if(arr[j-1] == -1)
		{
			cha = max(cha,abs(arr[j]-ans));
		}
		else cha = max(cha,abs(arr[j]-arr[j-1]));
	}
	//cout << endl;
	cout << cha << ' ' << ans << endl;
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
