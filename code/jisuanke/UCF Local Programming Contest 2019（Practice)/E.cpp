/*
*	Author: $%U%$
*	Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/ 
#include <bits/stdc++.h>
#define endl "\n"
#define inf 0x7fffffff-1
#define llinf 9223372036854775807LL
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define PER(i,a,b) for(int i = a; i >= b; i--)
#define MEM(a) memset(a,0,sizeof(a))

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

ll n,m; 
ll mp[1010][15];
void input()
{
	cin >> n >> m;
	REP(i,0,1001)
	{
		REP(j,0,11) mp[i][j] = 1e17;
	}
	REP(i,1,m)
	{
		int t;
		cin >> t;
		REP(j,1,t) cin >> mp[i][j];
	}
}

ll dp[1010][15];
void solve()
{
	ll ans = llinf;
	REP(i,0,1001)
	{
		REP(j,0,11) dp[i][j] = 1e17;
	}
	//cout << dp[0][0] << endl;
	REP(i,1,10) dp[1][i] = mp[1][i]-1;
	//REP(i,1,10) cout << dp[1][i] << endl;
	REP(i,2,m)
	{
		REP(j,1,10)
		{
			REP(k,1,10)
			{
				//cout << mp[i][j] << ' ' << mp[i-1][k] << ' ' << n << endl; 
				if(mp[i][j] > n||mp[i-1][k] > n) continue;//非输入值
				//第i首歌的第j种选择的最小按键数  
				dp[i][j] = min(dp[i][j],
					dp[i-1][k]+
					min(abs(mp[i][j] - (mp[i-1][k]+1) ),
					abs(n - abs(mp[i][j] - (mp[i-1][k]+1)) )));
				//cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j] << endl;
			}
		}
	}
	REP(i,1,10)
	{
		ans = min(ans,dp[m][i]);
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
