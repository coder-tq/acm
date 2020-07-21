/*
*	Author: coder_tq
*	Time: 2020-02-06 18:49:55
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

int n,t;
int arr[100010];
void input()
{
	cin >> n >> t;
}

void solve()
{
	int ans = -1;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		while(t < arr[i])
		{
			t+=arr[i-sum];
			sum--;
		}
		t-=arr[i];
		sum++;
		ans = max(ans,sum);
	}
	cout << ans << endl;
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
