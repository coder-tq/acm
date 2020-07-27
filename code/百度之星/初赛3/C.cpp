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
void input()
{
	scanf("%lld%lld",&n,&m);
}

void solve()
{
	//1 2 3
	//3 2 1
	//1 2 3 4
	//4 2 3 1
	//4 3 2 1
	
	//7 6 5 4 3 2 1
	if(n == 1) 
	{
		printf("0\n");
		return;
	}
	if(m >= n/2)
	{
		printf("%lld\n",n*(n-1)/2);
		return;
	}
	ll ans;
	ans = min(n*(n-1)/2,(n-1+n-m)*m/2 + (n-m*2)*m + m*(m-1)/2);
	printf("%lld\n",ans);
}
int main()
{
	//ios::sync_with_stdio(false);
	int t = 1;
	scanf("%d",&t);
	while(t--)
	{
		input();
		solve();
	}
	return 0;
}
