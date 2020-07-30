/*
*	Author: coder_tq1
*	Time: 2020-07-29 22:35:02
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

int n,k,z;
int a[200010];
void input()
{
	scanf("%d%d%d",&n,&k,&z);
	REP(i,1,n)
	{
		scanf("%d",&a[i]);
	}
}

ll ans;
ll dp[200010][10]; // dp[][]分数 i当前位置 j已经左移次数 i+j*2=总次数 
void solve()
{
	REP(i,1,n)
	{
		REP(j,0,9) dp[i][j] = 0;
	}
	ans = 0;
	REP(j,0,z)
	{
		REP(i,1,n)
		{
			if(j == 0){
				dp[i][j] = dp[i-1][j]+a[i];
			}
			else {
				dp[i][j] = max(dp[i-1][j]+a[i],dp[i+1][j-1]+a[i]);
			}
		}
	}
	REP(i,1,n)
	{
		REP(j,0,z)
		{
			if(i+j*2-1 == k) ans = max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
}

int main()
{
	int t = 1;
	scanf("%d",&t);
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
