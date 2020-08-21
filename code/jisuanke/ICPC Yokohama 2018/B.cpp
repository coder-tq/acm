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

int n;
ll arr[5010];
void input()
{
	scanf("%d",&n);
	REP(i,1,n) scanf("%lld",&arr[i]);
}


void solve()
{
	sort(arr+1,arr+n+1);
    map<ll,int> dp[n+1];
	int ans = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            int t = arr[i] - arr[j];
            dp[i][t] = dp[j][t] + 1;
            ans = max(ans,dp[i][t]+1);
        }
    }
	printf("%d\n",ans);
}

int main()
{
	freopen("out.txt","r",stdin);
	int t = 1;
	//scanf("%d",&t);
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
