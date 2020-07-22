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

int n,m,l;
int pos[110];
int w[110],v[110];
ll dij[110][110];
void input()
{
	cin >> n >> m >> l;
	REP(i,1,n) cin >> pos[i];
	REP(i,1,m) cin >> w[i] >> v[i];
	//cout << "111111111" << endl;
}


ll dp[1000][110];
void solve()
{
	sort(pos+1,pos+n+1);
	memset(dp,1,sizeof(dp));
	memset(dij,1,sizeof(dij));
	REP(i,1,m) dp[0][i] = 0;
	REP(i,1,1000)
	{
		REP(j,1,m)
		{
			if(i-v[j] >= 0)
				dp[i][j] = min(dp[i][j-1],dp[i-v[j]][j]+w[j]);
		}
	}
	REP(i,1,20) cout << i << ' ' << dp[i][m] << endl;
	REP(i,1,n) dij[i][i] = 0;
	REP(i,1,n)
	{
		REP(j,1,n)
		{
			dij[i][j] = min(dij[i][j],(dp[pos[j]-pos[i]][m] <= l)?1:llinf);
			REP(k,i,k)
			{
				dij[i][j] = min(dij[j][k],0LL);
			}
			
		}
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	int t = 1;
	cin >> t;
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
