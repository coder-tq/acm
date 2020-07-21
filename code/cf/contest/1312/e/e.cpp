/*
*	Author: coder_tq
*	Time: 2020-03-09 22:35:02
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
int arr[1010];
int dp[1010][1010]; 
void input()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
}

void solve()
{
	for(int i = 0; i < n; i++) dp[i][i] = arr[i];
	for(int len = 1; len < n; len++)
	{
		//cout << "len:" << len << endl;
		for(int i = 0; i < n-len; i++)
		{
			for(int j = 0; j < len; j++)
			{
				if(dp[i][i+j]!=0&&dp[i][i+j] == dp[i+j+1][i+len]) dp[i][i+len] = max(dp[i][i+len],dp[i][i+j]+1);
			}
			//cout << "i:" << i << " dp: " << dp[i][i+len] << endl;
		}
	}
	int ans[1010];// 
	memset(ans,0,sizeof(ans));
	for(int i = 1; i <= n; i++)
	{
		ans[i] = 0x3f3f3f3f;
		for(int j = 0; j <= i; j++)
		{
			if(dp[j][i-1] != 0)
				ans[i] = min(ans[j]+1,ans[i]);//j到i-1区间可以合并 
			ans[i] = min(ans[j]+i-j+1,ans[i]);//j到i-1区间不可以合并 
		}
	}
	cout << ans[n] << endl;
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
//3 3 3
//3 4 6
//3 5 10
//3 6 15
//4 4  
