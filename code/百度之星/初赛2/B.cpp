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

int n;
ll a[100010]; 
void input()
{
	
}

void solve()
{
	
}

int main()
{
	//ios::sync_with_stdio(false);
	int t = 1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		REP(i,1,n) scanf("%lld",&a[i]);
		ll ans = 0;
		ll cur = 0;
		REP(i,2,n)
		{
			ans+=(a[i]-a[i-1])*(n-i+1)*(i-1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
