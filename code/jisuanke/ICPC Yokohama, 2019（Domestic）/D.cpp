/*
*	Author: $%U%$
*	Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/ 
#include <bits/stdc++.h>
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
ll arr1[1010];
ll arr2[1010]
void input()
{
	scanf("%d%d",&n,&m);
	REP(i,1,n) scanf("%d",&arr1[i]);
	REP(i,1,n) scanf("%d",&arr2[i]);
}

ll dp[1010][1010];
void solve()
{
	REP(len,0,n)//区间长度 
	{
		REP(i,1,n)//起点
		{
			REP(k,i,i+len)
			{
				dp[i][i+len] = min(dp[i][i+len],dp[i][k]+dp[k][len])
			}
		} 
	}
}

int main()
{
	int t = 1;
	//scanf("%d",&t);
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
