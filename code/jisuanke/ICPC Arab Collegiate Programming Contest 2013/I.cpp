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

int n,m;
int mp[1010][1010]; 
ll dp[1010][1010];
void input()
{
	cin >> n >> m;
	
	REP(i,1,n)
	{
		REP(j,1,m)
		{
			cin >> mp[i][j];
		}
	}
}

void solve()
{
	ll ans = -0x3f3f3f3f3f;
	REP(i,1,n+1)
	{
		REP(j,1,m+1)
		{
			dp[i][j] = 0;
		}
	}
	PER(i,n,1)
	{
		PER(j,m,1)
		{
			dp[i][j] = dp[i][j+1]+dp[i+1][j]-dp[i+1][j+1]+mp[i][j];
			ans = max(dp[i][j],ans);
		}
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int t = 1;
	cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
